# 数位dp

## 简介

个人认为数位dp就是针对一些较大的数字，如1e18，需要枚举每个数字（状态）是否符合一定条件，然后据此计算答案（如符合条件的数字总数）。由于枚举每个数字复杂度过大，因此可以将数字按位数分开作为状态记录，搜索答案时也是按位数dfs。

同时它的用法有几个需要注意的地方，**第一个**是答案可以通过预处理之后以[l,r]=[min,r]-[min,l-1]的形式给出。**第二个**是枚举时某一位是否达到那一位的上界，需要记录一下，以此来确定这一位搜索时的上界，具体是记录一个pre_num（上一位）和一个flag（bool标记）。**第三个**是dfs时加上记忆化以此来做优化。**第四个**是前导零问题，有些题目需要处理。

数位dp有一个大致模板，具体修改根据题目来。

这篇博客可做参考：[数位dp](https://blog.csdn.net/wust_zzwh/article/details/52100392)

## 模板

有注释版：

```c++
typedef long long ll;
int a[20];
ll dp[20][state];//不同题目状态不同
ll dfs(int pos,int state/*state变量*/,bool lead/*前导零*/,bool limit/*数位上界变量*/)//不是每个题都要判断前导零
{
    //递归边界，既然是按位枚举，最低位是0，那么pos==-1说明这个数我枚举完了
    if(pos==-1) return 1;/*这里一般返回1，表示你枚举的这个数是合法的，那么这里就需要你在枚举时必须每一位都要满足题目条件，也就是说当前枚举到pos位，一定要保证前面已经枚举的数位是合法的。不过具体题目不同或者写法不同的话不一定要返回1 */
    //第二个就是记忆化(在此前可能不同题目还能有一些剪枝)
    if(!limit && !lead && dp[pos][state]!=-1) return dp[pos][state];
    /*常规写法都是在没有限制的条件记忆化，这里与下面记录状态是对应，具体为什么是有条件的记忆化后面会讲*/
    int up=limit?a[pos]:9;//根据limit判断枚举的上界up;这个的例子前面用213讲过了
    ll ans=0;
    //开始计数
    for(int i=0;i<=up;i++)//枚举，然后把不同情况的个数加到ans就可以了
    {
        if() ...
        else if()...
        ans+=dfs(pos-1,/*状态转移*/,lead && i==0,limit && i==a[pos]) //最后两个变量传参都是这样写的
        /*这里还算比较灵活，不过做几个题就觉得这里也是套路了
        大概就是说，我当前数位枚举的数是i，然后根据题目的约束条件分类讨论
        去计算不同情况下的个数，还有要根据state变量来保证i的合法性，比如题目
        要求数位上不能有62连续出现,那么就是state就是要保存前一位pre,然后分类，
        前一位如果是6那么这意味就不能是2，这里一定要保存枚举的这个数是合法*/
    }
    //计算完，记录状态
    if(!limit && !lead) dp[pos][state]=ans;
    /*这里对应上面的记忆化，在一定条件下时记录，保证一致性，当然如果约束条件不需要考虑lead，这里就是lead就完全不用考虑了*/
    return ans;
}
ll solve(ll x)
{
    int pos=0;
    while(x)//把数位都分解出来
    {
        a[pos++]=x%10;//个人老是喜欢编号为[0,pos),看不惯的就按自己习惯来，反正注意数位边界就行
        x/=10;
    }
    return dfs(pos-1/*从最高位开始枚举*/,state/*一系列状态 */,true,true);//刚开始最高位都是有限制并且有前导零的，显然比最高位还要高的一位视为0嘛
}
int main()
{
    ll le,ri;
    while(~scanf("%lld%lld",&le,&ri))
    {
        //初始化dp数组为-1,这里还有更加优美的优化,后面讲
        printf("%lld\n",solve(ri)-solve(le-1));
    }
}
```

无注释版：

```c++
typedef long long ll;
int a[20];
ll dp[20][state];
ll dfs(int pos,int state,bool lead,bool limit)
{

    if(pos==-1) return 1;//others

    if(!limit && !lead && dp[pos][state]!=-1) return dp[pos][state];

    int up=limit?a[pos]:9;

    ll ans=0;

    for(int i=0;i<=up;i++)
    {
        if() ...
        else if()...
        ans+=dfs(pos-1,i,lead && i==0,limit && i==a[pos])//others
    }
    if(!limit && !lead) dp[pos][state]=ans;

    return ans;
}
ll solve(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,-1,true,true);
}
int main()
{
    ll le,ri;
    memset(dp,-1,sizeof dp);
    while(cin>>le>>ri)cout<<solve(ri)-solve(le-1)<<'\n';
    return 0;
}
```

## 例题

### [windy数](https://www.luogu.com.cn/problem/P2657)

**不含前导零**且**相邻两个数字之差至少为 2** 的正整数被称为 windy 数。windy 想知道，在 a 和 b 之间，**包括 a 和 b** ，总共有多少个 windy 数？

ACcode

```c++

using namespace std;

//const int N=2e9+5;
ll dp[15][15];//dp[pos][pre_num]---当前第几位和上一位的数
int num[15];//存下n的每一位
//未到边界且前导非零的状态称为平方状态，非平方状态需要搜索具体计算
//dfs(当前位数, 上一位的数,  是否达到界限,是否有前导零)
ll dfs(int pos,int pre_num,bool flag,bool zero)
{
    if(pos<=0)return 1;//到达最后一位就搜索边界返回1(因为合适才能搜索所以这个状态贡献是1)
    // 没到边界   &&   算过了
    if(!flag&&dp[pos][pre_num]!=-1)return dp[pos][pre_num];
    int max_num;//枚举上限
    if(flag)max_num=num[pos];//到达边界
    else max_num=9;//没到边界--9
    ll res=0;//此状态的权
    for(int i=0;i<=max_num;++i){//枚举下界到上界
        //      题目所说   前导零也是可以的
        if(abs(i-pre_num)>=2||zero)
        //      下一位 此位到达边界&&下一位也到达边界  此位前导为零&&下一位也为0->下一位前导为零
        res+=dfs(pos-1,i,flag&&(i==num[pos]),zero&&(i==0));
    }
    //不是边界&&前导非零---记录此平方状态的权
    if(!flag&&!zero)dp[pos][pre_num]=res;
    return res;
}
ll solve(int n)
{
    int cnt=0;//总位数
    while(n)
    {
        num[++cnt]=n%10;//存下来
        n/=10;
    }
    return dfs(cnt,-666,1,1);//dfs(当前位数,上一位的数,是否达到界限,是否有前导零)
}
int main()
{
    int l,r;
    memset(dp,-1,sizeof dp);//mem -1 代表没算过
    memset(num,0,sizeof num);//men 0  代表不存在
    cin>>l>>r;
    cout<<solve(r)-solve(l-1)<<'\n';//ans=[l,r]=[1,r]-[1,l-1]
    system("pause");
    return 0;
}
```
