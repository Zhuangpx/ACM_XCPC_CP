# Divide by Zero 2021 and Codeforces Round #714 (Div. 2) Editorial 2021.04.12

链接：[#714(div.2)](https://codeforces.com/contest/1513).
开始记录cf的比赛，这是第一场。还不熟悉md格式，凑合写。
由于现在菜的很，div123只能过A，不过为了养成好习惯，还是写一 写。~~（一题也行啊）~~ 

# A. Array and Peaks（思维+构造）
https://codeforces.com/contest/1513/problem/A
链接: [Array and Peaks](https://codeforces.com/contest/1513/problem/A).
题意：给出整数n和k，将数字1~n排除某个序列使之出现k个峰。其中峰指该值比左右值都大。注意峰不能在首尾即前后必须有数字。
很简单的思维题。
官方题解：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210412111625366.png)
显然峰值先考虑大到小，每隔一位就放入一个峰值然后将其减1作为下一个峰值。那么当峰值数大于总数的一半即k*2>n将有峰值放不下也就是无解。
可以先判断有误解，再输出答案。
我当时比赛的代码：

```javascript
        // violet apricity
// Do all I can do.Do good to be good.
 
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<sstream>
 
#define STD using namespace std;
#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f
#define r0 return 0;
#define SYP system("pause");
#define endl '\n'
 
STD
const int maxn=105;
int re[maxn];
int main()
{
    for(int i=0;i<=100;i++)re[i]=i;
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k*2>=n){cout<<-1<<'\n';continue;}
        int a=1,b=n-k+1;
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(i%2==1||b>n)cout<<a++<<' ';
            else if(i%2==0&&b<=n)cout<<b++<<' ';
        }
        cout<<'\n';
    }
    //SYP
    return 0;
}
```
# B.AND Sequences（思维+构造+排列组合+AND&与运算）
链接: [AND Sequences](https://codeforces.com/contest/1513/problem/B).
题意：输入n和n个整数。将n个整数排列，求good permutations的总数对1e9+7取模。
good permutations定义为：![在这里插入图片描述](https://img-blog.csdnimg.cn/20210412112529758.png)
这题比赛的时候想法是记录出现两次以上的数字个数和出现次数，若不存在输出0，否则取两个相同数字作为首尾其它位置排列组合。理由是首尾相同之后一定满足good permutations。
最终结果：
```javascript
        // violet apricity
// Do all I can do.Do good to be good.
 
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<sstream>
 
#define STD using namespace std;
#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f
#define r0 return 0;
#define SYP system("pause");
#define endl '\n'
 
STD
const int maxn=2e5+5;
const int mod=1e9+7;
int a[maxn];
ll pre[maxn];
int yes[maxn];
void init()
{
    pre[1]=pre[0]=1;
    for(int i=2;i<maxn;i++){
        pre[i]=((i%mod)*(pre[i-1]%mod))%mod;
    }
}
int main()
{
    init();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        memset(yes,0,sizeof yes);
        vector<int>ans;
        int ma=0;
        int can=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            yes[a[i]]++;
            if(yes[a[i]]==2)ans.push_back(a[i]),can++;
        }
 
        //cout<<"debug:"<<can<<'\n';
        //cout<<"debug:"<<pre[1]<<' '<<pre[2]<<' '<<pre[3]<<'\n';
 
        if(can==0){cout<<0<<'\n';continue;}
        ll res=0;
        for(int i=0;i<can;i++){
            ll p=(yes[ans[i]]%mod*(yes[ans[i]]-1)%mod)%mod*pre[n-2]%mod;
            //cout<<"debug:"<<p<<'\n';
            res+=p;
            res%=mod;
        }
        cout<<res<<'\n';
    }
    //SYP
    return 0;
}
```
结果是wa了，只能过样例点。
分析一下为什么wa了：这里很显然a[1]=a[n]是一个**必要条件**，但事实上它**并不是一个充分条件**。因为除了a[1]=a[n]外还要满足a[1]&x=a[n]&x，x=a[2]&a[3]~~a[n-1]。
来看看官方题解：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210412113020714.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
首先解释一下官方题解的意思。
_pref(i)=a[1]&a[2]&~~a[i]，
_suf(i)=a[i]&a[i+1]&~~a[n]，
我们知道几个数相&只会使结果越来越小，所以_pref(2)<=_pref(1)=_suf(2)<=_suf(3)，又由题有_pref(1)=_suf(3)，所以得出：a[1]=_pref(2)=_suf(3)。
从而对1<=i<=n有_pref(i)=a[i]&&_suf[i]=a[1]。
我这里做出自己的另一种理解：
有上述可知，若将中间看作整体，有a[1]&x=a[n]，a[1]=x&a[n]，a[1]=a[n]，那么我们可以再把后两项或前两项看作整体，成为一个n-1项的序列，且我们同样可以得出以上结论，即首尾相等且等于首尾分别与中间&的结果，当我们继续往下推可以得到：a[1]=a[1]&a[2]=a[2]&F(a[3]&~a[n])，
把左右两边&a[1]得到a[1]&a[1]=a[1]&a[2]&F(a[3]&~a[n])，
那么a[1]=a[1]&~~a[n]的结论就得出来了。
也就是说要找的首尾应该是相等的且等于所有数&的结果。
那么下面就可以来实现了：
首先mp记录每个数出现次数，p=a[1]&a[2]~~a[n]，mul=(n-2)!。
其中p为放置在首尾的数，mul为中间数字的全排列。
若mp[p]<=2说明没有合题意能放在首尾的数即无解输出0，
否则 ans=mp[p]*（mp[p]-1）*mul。
前两项相乘表示所有合适的数选出来两个排列在首尾的方案数和，即c(2,cnt)。
记得边乘边取模。
赛后补题：
~~~javascript
        // violet apricity
// Do all I can do.Do good to be good.

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<sstream>

#define STD using namespace std;
#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f
#define r0 return 0;
#define SYP system("pause");
#define endl '\n'

STD
const int maxn=2e5+5;
const int mod=1e9+7;
ll a[maxn];
map<ll,ll>mp;
int main()
{
    int t;cin>>t;
    while(t--){
        mp.clear();
        int n;cin>>n;
        ll p,mul=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]]++;
            if(i==1)p=a[i];
            else p&=a[i];
            if(i<=n-2)mul=(mul*i)%mod;
        }
        if(mp[p]>=2){
            ll ans=(mp[p]*(mp[p]-1))%mod;
            cout<<ans*mul%mod<<'\n';
        }
        else cout<<0<<'\n';
    }
    //SYP
    return 0;
}
~~~
# C.Add One（dp+矩阵）
https://codeforces.com/contest/1513/problem/C
链接：[Add One](https://codeforces.com/contest/1513/problem/C)
题意：t组样例，每组给出两个整数n，m。对n操作m次输出最终n的长度对1e9+7取模。
操作指：n每一个十进制位的数字加1。eg：1912-->21023。
这题比赛时来不及想，不过大概率也做不出来。
还是先上官方题解：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210412125428215.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
考虑一位数如何加1会变成两位数。
对于n=10，操作k次，设dp[i]==操作i次后n长度：
0<=k<=8：dp[k]==2;
k=9:   dp[k]==3;
k>=10:  dp[k]=dp[k-9]+dp[k-10]
那么我们可以先预处理一下。
最后结果就是：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210412130303495.png)
也就是遍历每一位数设为x，若m+x<10 ans+=1；否则ans+=dp[m+x-10]。
记得取模。数据很多所以得IOS关同步。
~~~javascript
        // violet apricity
// Do all I can do.Do good to be good.

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<sstream>

#define STD using namespace std;
#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f
#define r0 return 0;
#define SYP system("pause");
#define endl '\n'

STD
const int maxn=2e5+5;
const int mod=1e9+7;
int dp[maxn];
int main()
{
    IOS
    for(int i=0;i<9;i++)dp[i]=2;
    dp[9]=3;
    for(int i=10;i<maxn;i++)dp[i]=(dp[i-9]+dp[i-10])%mod;
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ans=0;
        while(n){
            int x=n%10;
            ans+=((x+m<10)?1:dp[x+m-10]);
            ans%=mod;n/=10;
        }
        cout<<ans<<'\n';
    }
    SYP
    return 0;
}
~~~
那么就到这了，再往下DEF不会了。
