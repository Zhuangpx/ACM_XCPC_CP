# [Codeforces Round #721 (Div. 2)](https://codeforces.com/contest/1527)
闲话：这场不想多写证明了，基本上就是推推推（其实是懒啦）。
## [A. And Then There Were K](https://codeforces.com/contest/1527/problem/A)
### 题意
![A](https://img-blog.csdnimg.cn/20210521081448248.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
找出最大的k让上面那一个式子为0.
### 题解
&起来为0且最大化那么让最高位为0其它位为1即可。
### code
```cpp
using namespace std;
 
const int N=1e8;
const ll maxn=1e10;
//ll a[12];
ll solve(ll n)
{
    ll cnt=0;
    ll now=n;
    while(now){
        //a[++cnt]=now%2;
        now/=2;
    }
    ll ans=0;
    ll res=cnt-1;
    while(res>0){
        ans+=pow(2,res-1);
        res--;
    }
    return ans;
}
int main()
{
    //IOS
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        cout<<solve(n)<<'\n';
    }
    //SYP
    return 0;
}
```
## [B1. Palindrome Game (easy version)](https://codeforces.com/contest/1527/problem/B1)
### 题意
![B1](https://img-blog.csdnimg.cn/20210521081900396.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
### 题解
总结总结总结，分情况推记下就可以了。（懒得解释了wsfw）
### code
```cpp
using namespace std;
 
const int N=1e8;
const ll maxn=1e10;
 
int main()
{
    //IOS
    ll t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++)if(s[i]=='0')cnt++;
        if(cnt==0)cout<<"DRAW\n";//这里是不需要，题目说了保证至少一个0
        else if(cnt%2==0){
            cout<<"BOB\n";
        }
        else if(cnt%2==1){
            if(cnt==1)cout<<"BOB\n";
            else cout<<"ALICE\n";
        }
    }
    //SYP
    return 0;
}
```
## [B2. Palindrome Game (hard version)](https://codeforces.com/contest/1527/problem/B2)
### 题意
![C](https://img-blog.csdnimg.cn/20210521082500347.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
### 题解
初始条件和b1不一样而已，还是分情况推推推。
### code
```cpp
using namespace std;
 
const int N=1e5+5;
const ll maxn=1e10;
int main()
{
    //IOS
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int zero=0,one=0;
        bool yes=1;
        for(int i=0;i<n;i++){
            s[i]=='1'?(one++):(zero++);
        }
        if(zero==0)//特判0
        cout<<"DRAW\n";
        else if(n%2==1&&s[n/2]=='0'){
            int now=one;
            for(int i=0,j=n-1;i<j;i++,j--){
                if(s[i]==s[j]&&s[i]=='1')now-=2;
            }
            if(now==0){//回文
                if(zero==1)cout<<"BOB\n";//特判1
                else cout<<"ALICE\n";
            }
            else if(zero==2)cout<<"DRAW\n";//特判2
            else cout<<"ALICE\n";
        }
        else {
            for(int i=0,j=n-1;i<j;i++,j--){
                if(s[i]!=s[j]){
                    yes=0;break;
                }
            }
            if(yes==0)cout<<"ALICE\n";
            else cout<<"BOB\n";
        }
    }
    //SYP
    return 0;
}
```
事实上，无论是b1还是b2，除了特定情况，拥有多种选择的人往往胜率较高，往这个方向思考能更加快得出结论。
## [C. Sequence Pair Weight](https://codeforces.com/contest/1527/problem/C)
### 题意
![C](https://img-blog.csdnimg.cn/20210521082630344.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
这题有必要说一下。是一道简单套路的题。
定义一个序列的weight（权重）为其相等元素组成的无序对的对数。要求一个序列所有子序列的权重和。
### 题解
我们左往右遍历，用map存下每个数字，对于一对相等元素[a,b]，其能产生贡献的在于[1,a]和[b,n]，答案即是**(a-1+1)*(n-b+1)**。因此通过map存数字，往右遍历到第i个数字d用map[d]来计算前面每个d和当前这一个d产生的贡献，因为每一个d产生的贡献都是其距离左端点的距离乘上i距离右端点的距离，结果加起来就是所有位置左端点到左端点的距离和乘上i距离右端点的距离，因此map可以存下之前所有d位置到左端点的距离和，因为左端点为1，所以存下之前所有d的序号即可。如果前面没有出现d，那么map[d]=0，0乘上任何数都是0，因此可以省去判断是否出现的步骤，直接乘上加进答案里。
### code
```cpp
using namespace std;
 
const int N=1e5+5;
const ll maxn=1e10;
//ll a[N];
int main()
{
    //IOS
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll ans=0;
        map<ll,ll>p;
        for(ll i=1;i<=n;i++){
            ll d;cin>>d;
            ans+=p[d]*(n-i+1);
            p[d]+=i;
        }
        cout<<ans<<'\n';
    }
    //SYP
    return 0;
}
```
