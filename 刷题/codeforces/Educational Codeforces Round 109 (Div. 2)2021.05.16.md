# [Educational Codeforces Round 109 Div. 2 2021.05.16](https://codeforces.com/contest/1525)
## [A. Potion-making](https://codeforces.com/contest/1525/problem/A)
### 题意
![A](https://img-blog.csdnimg.cn/2021051618460769.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
两个数a，b占比分别为k%和(100-k)%，输入k求a+b最小值。
### 题解
不妨先取一个一定满足题意的，即a=k，b=100-k，然后再考虑缩小。分别除以gcd就好了。
### code
```cpp
using namespace std;
int gcd(int a,int b)   //return a=gcd(a,b)
{
    ll temp;
    while(b){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main()
{
    int ans=0;
    int t;cin>>t;
    while(t--){
        ans=0;
        int a;cin>>a;
        int b=100-a;
        int c=gcd(a,b);
        cout<<a/c+b/c<<'\n';
    }
    return 0;
}
```
## [B. Permutation Sort](https://codeforces.com/contest/1525/problem/B)
### 题意
![B](https://img-blog.csdnimg.cn/20210516185050500.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
给n和n个数，要求将其升序，每次可以选一个连续区间修改其中任意顺序，但是不能选一整个。
### 题解
特殊的地方就在首尾。分情况讨论即可。
如果1在第n个并且n在第一个，因为不能操作一整个区间，也就是说无法同时将这两个归位，所以需要通过两次操作把它们拿出来，然后再拿回去。答案就是3.
如果已经升序就是0.
如果首尾至少一个位置合法了，那么选择除了合法的之外的首尾那个区间进行操作即可，答案是1.
其它情况，也就是第一个和最后一个都放了其它数，两次操作分别把1和n放到合法位置，答案就是2.
### code
```cpp
const int N=55;
int a[N];
int main()
{
    int ans=0;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ans=0;
        bool yes=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>1&&a[i]<a[i-1])yes=1;
        }
        if(yes==0)cout<<0<<'\n';
        else if(a[1]==n&&a[n]==1)cout<<3<<'\n';
        else if(a[1]==1||a[n]==n)cout<<1<<'\n';
        else cout<<2<<'\n';
    }
    return 0;
}
```
## [D. Armchairs](https://codeforces.com/contest/1525/problem/D)
### 题意
![D](https://img-blog.csdnimg.cn/20210516190603686.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
一开始有<=(n/2)个1，把它们分别配对到一个0上，并且每个0只能配对一个1，花费为该1和该0的距离。要求将所有1移动到0的距离和最小值。
### 题解
dp一下。

```cpp
dp[i][j]:把前i个1移动到前j个0的最小花费
pos[p]:第p个1或0的下标（位置）
n1:1数量
n0:0数量
初始化dp:INF
从左往右枚举前i个1移动的区间
同时这里枚举j是在[i,n0]内
if i==1 
   dp[i][j]=min(dp[i][j-1],abs(pos[i]-pos[j])
   //如果只有1一个1，那么就是在[1,j]区间里选一个位置使当前区间最小
else 
   dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(pos[i]-pos[j])
   //第一个转移：第i个1不放在新加入的第j个0处，那么就要把i个1放在前j-1个0，特殊地，如果不够放即j-1<i，因为上述初始化为INF，所以取min时默认后一个转移选项
   //第二个转移：第i个1放在新加入的第j个0处，那么当前费用就是前i-1个1放在前j-1个0处加上第i个1放在第j个0处的费用。
```
解释一下为什么j左界是i，因为我们这里i是从左往右数的，数到i和i+1个，对于第i个0，把i+1移动到那和把i移动到那明显后者更优，也就是说宁可移动i也不需要移动i+1，前面的也同理。所以不需要考虑i前面的0。同时也是为了能使每个i有地方放（这点在初始化与取min时已经排除了影响，实际上可有可无）。
### code
```cpp
using namespace std;
int n1,n0;
const int N=5001;
int c1[N],c0[N];
int dp[N][N];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int d;cin>>d;
        if(d==1){
            c1[++n1]=i;
        }
        else if(d==0){
            c0[++n0]=i;
        }
    }
    if(n1==0){cout<<0<<'\n';return 0;}
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n1;i++){
        for(int j=i;j<=n0;j++){
            if(i==1)dp[i][j]=min(dp[i][j-1],abs(c1[i]-c0[j]));
            else dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(c1[i]-c0[j]));
        }
    }
    cout<<dp[n1][n0]<<'\n';
    return 0;
}

```

