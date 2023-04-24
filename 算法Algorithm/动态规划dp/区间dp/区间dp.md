# 区间dp

## 引入例题

### LPS

最长回文子序列LPS，设dp[l,r]表示闭区间l到r的LPS长度，那么它可以转移到dp[l+1,r]，dp[l,r-1]，dp[l+1,r-1]三种情况。通过边界缩小区间。

### NPS

回文子序列数量，需要利用容斥。

dp[l,r]=dp[l+1,r]+dp[l,r-1]-dp[l+1,r-1]

dp[l,r]+=dp[l+1,r-1]+1

也可以用另一种设计思路

可以用长为3的滚动数组

dp[len,l]=dp[len-1,l+1]+dp[len-1,l]-dp[len-2,l+1]

dp[len,l]+=dp[len-2,l+1]

### 石子合并

一排石子，每次可以合并相邻某两堆，费用为合并后石子数量。要求合并成一堆求最小费用或者最大费用。

由最终状态往前思考，对于区间[l,r]枚举断点i。

dp[l,r]=min dp[l,i]+dp[i,r]+cost[l,r]

### 最优矩阵链乘MCM



### 最优三角形剖分OT



### 覆盖刷串



## 简介

顾名思义，区间dp就是在区间上处理动态规划（求最优解）的问题。其主要思想在于先对小区间求解再对大区间求解，或者说一个大区间应该由若干个小区间**合并**而来。

区间 DP 的特点：

**合并**：即将两个或多个部分进行整合，当然也可以反过来；

**特征**：能将问题分解为能两两合并的形式；

**求解**：对整个问题设最优值，枚举合并点，将问题分解为左右两个部分，最后合并两个部分的最优值得到原问题的最优值。

下面给出最简单形式的小模板（具体根据题目要求修改）

```c++
//mst(dp,0) 初始化DP数组
for(int i=1;i<=n;i++)
{
    dp[i][i]=初始值 //转移的最小边界
}
for(int len=2;len<=n;len++)  //区间长度
for(int i=1;i<=n;i++)        //枚举起点
{
    int j=i+len-1;           //区间终点
    if(j>n) break;           //越界结束
    for(int k=i;k<j;k++)     //枚举分割点，构造状态转移方程
    {
        dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+w[i][j]);
    }
}
```

具体在题目中体会

## （线性）[石子合并](https://vjudge.net/problem/51Nod-1021)

原题出自[51Nod - 1021](https://www.51nod.com/Challenge/Problem.html#problemId=1021)

最朴素的区间dp，复杂度是O(n^3)，即枚举长度，起点，断点。

N堆石子摆成一条线。现要将石子有次序地合并成一堆。规定每次只能选相邻的2堆石子合并成新的一堆，并将新的一堆石子数记为该次合并的代价。计算将N堆石子合并成一堆的最小代价。

我们用dp[l,r]表示将区间[l,r]合并的代价，那么它必须是有[l,k]与[k+1,r]合并而来的，代价就是两个代价和加上新的代价，也就是dp[l,r]=dp[l,k]+dp[k+1,r]+(sum[r]-sum[l-1])，至于k枚举即可。

那么就可以枚举区间的长度-区间的起点-区间的断点k，最小边界应该是dp[i,i]=w[i,i]。

```c++
using namespace std;

const int N=102;
int dp[N][N];
int w[N];//直接前缀和
int main()
{
    int n;cin>>n;
    memset(w,0,sizeof w);
    memset(dp,0x3f,sizeof dp);//先初始化为无穷大
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        cin>>w[i];//这里是a[i]
        w[i]+=w[i-1];//这里是前缀和
        dp[i][i]=0;//初始化边界dp[i][i]=0
    }
    for(int len=2;len<=n;len++)//枚举长度，因为边界长度1处理过了所以len从2开始
    {
        for(int i=1;i<=n;i++)//枚举起点i，终点就是i+len-1
        {
            int j=i+len-1;
            if(j>n)continue;
            for(int k=i;k<j;k++)//断点应该是区间[i,i+len)内
            {
                dp[i][j]=min(dp[i][k]+dp[k+1][j]+(w[j]-w[i-1]),dp[i][j]);//分成了区间[i,k]和[k+1,i+len]
            }
        }
    }
    cout<<dp[1][n]<<'\n';//答案就是整个区间[1,n]的值
    //SYP
    return 0;
}
```

## 环形+四边形优化：[HDU - 3506 Monkey Party](http://acm.hdu.edu.cn/showproblem.php?pid=3506)

翻译之后就是环形石子合并。

首先对于环形的处理方法有下面两种：

- 方法一：枚举断点，将环形转化为线性
- 方法二：将链延长两倍变成2 * n堆，把n前面n-1加到n后面，那么答案就是f[i,n+i-1],1<=i<=2 * n-1中取最优。

接下来就是优化复杂度。在枚举断点的时候可以优化。

这里的问题是满足**四边形不等式（+优化）的**，就是：

- 区间值关系，满足交叉小于包含
- 满足单调性（所以只能用于min而不能用于max）

放在这里就是**花费w满足四边形不等式**,有：

```c++
i<i_<=j_<j
w[i][j_]+w[i_][j]<=w[i_][j_]+w[i][j]
单调性：w[i][j]>=w[i_][j_]
```

以上能推出**dp满足四边形不等式**。设

```c++
s[i][j]:dp[i][j]的最有分割点
s[i][j-1]<=s[i][j]<=s[i+1][j]
```

证明的话在[这里](https://blog.csdn.net/noiau/article/details/72514812).

再说一下为什么复杂度能降到O(n^2)

讨论一下s的枚举：

```c++
[1,L]:s[2][L]~s[1][L-1]+1
[2,L]:s[3][L+1]~s[2][L]+1
............
累加约去相邻的前后项：
([n-L+2]-s[1][L-1])+(n-L+1)
注意到两个括号里都是<=n的，所以最后是O(n^2)
```

![image-20210516115917746](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210516115917746.png)

**扩展：**

以上所给出的状态转移方程只是一种比较一般的，其实，很多状态转移方程都满足四边形不等式优化的条件。

解决这类问题的大概步骤是：

0.证明w满足四边形不等式，这里w是m的附属量，形如m[i,j]=opt{m[i,k]+m[k,j]+w[i,j]}，此时大多要先证明w满足条件才能进一步证明m满足条件

1.证明m满足四边形不等式

2.证明s[i,j-1]≤s[i,j]≤s[i+1,j]

```c++
using namespace std;
/*
 四边形优化，min 可用 max 不可用
*/
const int N=2552;
int dp[N][N];
int DP[N][N];
int w[N];//直接前缀和
int s[N][N];//区间[l,r]的最优断点
int main()
{
    //IOS
    int n;
    while(cin>>n)
    {
    memset(w,0,sizeof w);
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++){
        cin>>w[i];//这里是a[i]
        w[i]+=w[i-1];//这里是前缀和
        dp[i][i]=0;//初始化边界
        s[i][i]=i;//区间[i,i]只有一个断点i
    }
    for(int i=1;i<n;i++){
                //下面为拼接部分
        w[i+n]=w[i+n-1]+(w[i]-w[i-1]);
        dp[i+n][i+n]=0;
        s[i+n][i+n]=i+n;
    }
    for(int len=2;len<=n;len++)//枚举长度，因为边界长度1处理过了所以len从2开始
    {
        for(int i=1;i<=n*2-1;i++)//枚举起点i，注意最后一组起点应该是[2*n-1]。终点就是i+len-1
        {
            int j=i+len-1;
            if(j>n*2-1)continue;
            //四边形优化，减少断点枚举量
            for(int k=s[i][j-1];k<=s[i+1][j];k++)//枚举断点k，找到一个最优断点更新并赋值
            {
                if(dp[i][k]+dp[k+1][j]+(w[j]-w[i-1])<dp[i][j])//找到更优解
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j]+(w[j]-w[i-1]);
                    s[i][j]=k;//更新当前区间最优断点
                }
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++)ans=min(ans,dp[i][i+n-1]);
    cout<<ans<<'\n';
    }
    return 0;
}
```

## [GarsiaWachs算法优化](https://blog.csdn.net/yo_bc/article/details/74852571):[HYSBZ - 3229 石子合并](https://www.lydsy.com/JudgeOnline/problem.php?id=3229)

数据比较大O(n^3)太过勉强，这里引入GarsiaWachs算法。

[GarsiaWachs证明](https://en.m.wikipedia.org/wiki/Garsia%E2%80%93Wachs_algorithm)

GarsiaWachs算法是解决石子合并最优的算法，复杂度是O(n^2)。

它的步骤如下：

设序列是stone[]，从左往右，**找一个满足stone[k-1] <= stone[k+1]的k**，找到后合并stone[k]和stone[k-1]，再从当前位置开始向左找最大的j，使其满足**stone[j] > stone[k]+stone[k-1]**，插到j的后面就行。一直重复，直到只剩下一堆石子就可以了。在这个过程中，可以假设stone[-1]和stone[n]是正无穷的。

举个例子：

186 64 35 32 103

因为35<103，所以最小的k是3，我们先把35和32删除，得到他们的和67，并向前寻找一个第一个超过67的数，把67插入到他后面，得到：186 67 64 103,现在由5个数变为4个数了，继续：186 131 103，现在k=2（别忘了，设A[-1]和A[n]等于正无穷大）234 186，最后得到420。最后的答案呢？就是各次合并的重量之和，即420+234+131+67=852。

基本思想是通过树的最优性得到一个节点间深度的约束，之后证明操作一次之后的解可以和原来的解一一对应，并保证节点移动之后他所在的深度不会改变。具体实现这个算法需要一点技巧，精髓在于不停快速寻找最小的k，即维护一个“2-递减序列”朴素的实现的时间复杂度是O(n*n)，但可以用一个平衡树来优化，使得最终复杂度为O(nlogn)。

```c++
using namespace std;

const int N=1e4+5;
int s[N];
ll ans,t;
void combine(int k)
{
    int temp=s[k]+s[k+1];
    ans+=temp;
    for(int i=k;i<t-1;i++){
        s[i]=s[i+1];
    }
    t--;
    int j=0;
    for(j=k-1;s[j-1]<temp;j--){
        s[j]=s[j-1];
    }
    s[j]=temp;
    while(j>=2&&s[j]>=s[j-2]){
        int d=t-j;
        combine(j-1);
        j=t-d;
    }
}
int main()
{
    int n;cin>>n;
    s[0]=INF;
    s[n+1]=INF-1;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    ans=0,t=3;
    for(int i=3;i<=n+1;i++){
        s[t++]=s[i];
        while(s[t-3]<=s[t-1]){
            combine(t-2);
        }
    }
    while(t>3)combine(t-1);
    cout<<ans<<'\n';
    SYP
    return 0;
}
```



## [POJ - 1738 An old Stone Game](http://poj.org/problem?id=1738)（[GarsiaWachs算法优化](https://blog.csdn.net/yo_bc/article/details/74852571)+平衡树优化，时间复杂度O(n log n)

更大的数据，需要用平衡树优化GarsiaWachs。

```c++

using namespace std;
const int N = 1e5 + 7;
const int inf = 0x3f3f3f3f;
int stone[N],n,ans,t,j;
void init()
{
    ans = 0;
    t = 3;
    stone[0] = inf;
    stone[n + 1] = inf - 1;
}
void combine(int k)
{
    int res = stone[k - 1] + stone[k];
    ans += res;
    for(int i = k;i < t - 1;++i) stone[i] = stone[i + 1];
    t--;j = 0;
    for(j = k - 1;stone[j - 1] < res;--j) stone[j] = stone[j - 1];
    stone[j] = res;
    while(j >= 2 && stone[j] >= stone[j - 2]){
        int d = t - j;
        combine(j - 1);
        j = t - d;
    }
}
int main()
{
    while(scanf("%d",&n) != EOF && n){
        for(int i = 1;i <= n;++i) scanf("%d",&stone[i]);
        init();
        for(int i = 3;i <= n + 1;++i){
            stone[t++] = stone[i];
            while(stone[t - 3] <= stone[t - 1]) combine(t - 2);
        }
        while(t > 3) combine(t - 1);
        printf("%d\n",ans);
    }
    return 0;
}
```

