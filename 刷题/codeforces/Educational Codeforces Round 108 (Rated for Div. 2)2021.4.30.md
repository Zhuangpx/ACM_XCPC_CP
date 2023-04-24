# [Educational Codeforces Round 108 (Rated for Div. 2)](https://codeforces.com/contest/1519)
闲话：很久没打cf了（其实就几天），很怀念。开前立下4题flag，结果是ab。想试试用STL做做c，没想到写了一个小时给我整出二十多个bug，于是下线走人。这场几道题觉得挺有意思的，好好研究一下。
# [A. Red and Blue Beans](https://codeforces.com/contest/1519/problem/A)
## 题意：
t组测试样例，每组给出三个整数r，b，d。r和b为两种糖果数量，将通过放若干个袋子里，要求每个袋子每种糖果都要有，并且相差不超过d。即：
![A. Red and Blue Beans](https://img-blog.csdnimg.cn/20210430092834798.png)
## 题解：
这题可以用贪心的思想。我们可以将糖果分在放在尽量多的袋子里，假设少的糖果为a，多的为b，那么我们让每个a尽量多的和b放在一起，也就是1个a和(1+d)放在一起，如果这种最大化放置方法的结果可以使a分配的b数量大于b原本的数量，那么我们可以选若干个袋子，将b的数量减少一点，直到b数量和原来的相等。
也就是说每个a分配(1+d)，结果大于等于b数量即可。
```cpp
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
#include<numeric>
#include<queue>
#include<iomanip>

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
int main()
{
    //IOS
    ll t;
    cin>>t;
    while(t--){
    ll a,b,d;
    cin>>a>>b>>d;
    ll x=max(a,b);
    ll y=min(a,b);
    d++;
    if(x==y)cout<<"YES\n";
    else if(d==0){
        if(x==y)cout<<"YES\n";
        else if(x!=y)cout<<"NO\n";
    }
    else if(y*d<x)cout<<"NO\n";
    else cout<<"YES\n";
    }
    //SYP
    r0
}
```
# [B. The Cake Is a Lie](https://codeforces.com/contest/1519/problem/B)
## 题意：
跑图问题，起点(1,1)，终点(n,m)，可以向下或者向右跑，消耗代价：

 - (x,y)--->(x,y+1)      cost:x
 - (x,y)--->(x+1,y)      cost:y

t组测试，每组给出n,m,k。判断代价是否等于k。
## 题解：
上来分析先打表
```cpp
for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(i==1&&j==1)continue;
            if(j==1)x[i][j]=i-1;
            else if(i==1)x[i][j]=j-1;
            else if(j>=i)x[i][j]=x[i-1][j]+j;
        }
    }
```
打表后发现：

```cpp
x[i][j]=i*j-1
```
答案出来了。
```cpp
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
#include<numeric>
#include<queue>
#include<iomanip>

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
int main()
{
    IOS
    ll t;
    cin>>t;
/*
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(i==1&&j==1)continue;
            if(j==1)x[i][j]=i-1;
            else if(i==1)x[i][j]=j-1;
            else if(j>=i)x[i][j]=x[i-1][j]+j;
            else if(j<i)x[i][j]=x[i][j-1]+i;
        }
    }
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        ll d=x[n][m];
        if(d==k)cout<<"YES\n";
        else cout<<"NO\n";
    }
*/
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a*b-1==c)puts("YES");
        else puts("NO");
    }
    //SYP
    r0
}
```
不严谨的证明（分析）：

首先，x和y得移动是相互独立的，因为无论怎么移动都必须经历n次x到x+1,y同理。并且无论怎么走答案都是一样的。我们先选一直通用走法，就是先往右走到m再往下都到n，之后考虑换一种走法。
假设先要到(3,4)，第一种走法如下：
```cpp
(1,1)---(1,2)---(1,3)---(1,4)---(2,4)---(3,4)
      +1      +1      +1      +4      +4      11
x     1       1       1                       3
y                             4       4       8
```
第二种：
```cpp
(1,1)---(1,2)---(1,3)---(2,3)---(3,3)---(3,4)
      +1      +1      +3      +3      +3      11
x     1       1                       3       5 (+2)
y                     3       3               6 (-2)
```
我们发现，总费用是不会变的，先走了x会使x总和减少，同时y总和会增加，其变化的差值为0。
这就说明了路径的任意性。
这里再说一下另一种稍微严谨一点的证明方法。
假设现在有四个点

```cpp
(x,y)      (x,y+1)
(x+1,y)    (x+1,y+1)
```
容易知道向右和向下都是一样的费用，那么对角线呢？对于两种方案计算得到费用都是x+y+1，所以得出了**跨到对角线的费用也是一定的**这一结论。
我们再往右推广：
```cpp
(x,y)      (x,y+1)      (x,y+2)
(x+1,y)    (x+1,y+1)    (x+1,y+2)
```
容易知道，要到右下角有三种方案，分别是（右 右 下）（右 下 右）（下 右 右），由上面对角线结论可知1=2，2=3，因为其首或尾相同。那么就有1=2=3，那么我们可以无限推广，对每个点其上一个点要不是左要不是右，而它们都是定值，这点也是定值。于是便能得出到每个点的路径费用是一定的。
对于结论，我们可以选第一种作为归纳证明，向右走(m-1)步，总和为(m-1)，再向下走(n-1)步，因为最后到了(1,m)，所以接下来要加上(n-1)*m，那么答案就是二者相加，即ans=(m-1)+(n-1) *m=n *m-1。
这就得出了答案。

# [C. Berland Regional](https://codeforces.com/contest/1519/problem/C)
## 题意：
太长了直接给题面吧。
![C. Berland Regional](https://img-blog.csdnimg.cn/20210430094856684.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
## 题解：
就硬模拟，没什么好说的，记得用上前缀和。

```cpp
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
#include<numeric>
#include<queue>
#include<iomanip>

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
const int N=2e5+5;
vector<ll>sch[N];//学校和该学校的学生的实力。
int a[N],b[N];//记下编号i的学校和学生实力。
ll ans[N],sum[N];//ans打印i人一组的答案即存下每个k的答案，sum存某个学校学生实力排序后的前缀和。
bool cmp(ll a,ll b){return a>b;}//大于
int main()
{
    //IOS
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        for(ll i=1;i<=n;++i){
            cin>>a[i];//记下编号i对应的学校a[i]
            sch[i].clear();//先把每个学校的学生实力清空
        }
        for(ll i=1;i<=n;++i){
            cin>>b[i];
            ans[i]=0;//先对每种答案清0
            sch[a[i]].push_back(b[i]);//学生i实力b[i]压入学校a[i]中
        }
        for(ll i=1;i<=n;++i){//枚举学校i
            int len=sch[i].size();//取出学校i的学生数量
            if(len==0)continue;//没有学生直接跳过
            sort(sch[i].begin(),sch[i].end(),cmp);//因为要优先选实力强的所以实力大到小排序
            sum[0]=0;//实力前缀和，第一位特殊处理
            for(ll j=1;j<=len;j++)sum[j]=sum[j-1]+sch[i][j-1];//学生是0开始的，前缀和是1开始的
            for(ll j=1;j<=len;j++){//枚举学校i的学生数量，因为每种数量都要作个答案，所以这里也枚举了k
                ll can=len/j*j;//只取了实力靠前的j个
                ans[j]+=sum[can];//k=j的答案加上这些学生的实力
            }
        }
        for(ll i=1;i<=n;i++)cout<<ans[i]<<' ';//每种k输出
        cout<<'\n';
    }
    //SYP
    r0
}
```
# [D. Maximum Sum of Products](https://codeforces.com/contest/1519/problem/D)
## 题意：
给一个整数n和两个长为n的整数序列a和b，至多翻转一次a的某部分，使$\sum_{i=1}^{n}a[i]*b[i]$最大。输出这个答案。
## 题解：
存一下乘积前缀和，暴力枚举翻转子序列的断点和长度，然后更新答案为最大值即可。这里翻转的子序列可以是奇数和偶数，所以要分开处理。
```cpp
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
#include<numeric>
#include<queue>
#include<iomanip>

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
const int N=5002;
ll a[N],b[N],s[N];
int main()
{
    //IOS
    ll n;cin>>n;
    ll ans=0;
    for(ll i=0;i<n;++i)cin>>a[i];
    for(ll i=0;i<n;++i)cin>>b[i],s[i]=a[i]*b[i],ans+=s[i];
    ll maxn=ans;
    for(ll i=0;i<n;i++){//断点
        ll t=ans;
        ll l=i-1,r=i+1;//奇数情况，之间那应该不参与翻转，所以变化的是i-1和i+1
        while(l>=0&&r<n){//向外扩充
           t=t-(s[l]+s[r]);//减掉原来不翻转的
           t+=(a[l]*b[r]+a[r]*b[l]);//加上翻转以后的
           maxn=max(maxn,t);//更新最大值
           l--,r++;
        }
    }
    for(ll i=0;i<n;i++){
        ll t=ans;
        ll l=i,r=i+1;//偶数情况，两个数相邻，都有贡献
        while(l>=0&&r<n){
           t=t-(s[l]+s[r]);
           t+=(a[l]*b[r]+a[r]*b[l]);
           l--,r++;
           maxn=max(maxn,t);
        }
    }
    cout<<maxn<<'\n';
    //SYP
    r0
}
```
