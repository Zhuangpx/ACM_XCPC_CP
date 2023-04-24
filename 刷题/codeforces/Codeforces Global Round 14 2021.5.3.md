# [Codeforces Global Round 14](https://codeforces.com/contest/1515)
闲话：这场一小时切了abc，直接突到2k+名，不过d罚坐一小时，模拟了一大堆师兄说是贪心，于是就跑路了，最后是掉到4k，然后上绿了。绿了绿了绿了，小里程碑，还要继续加油，还没切过4题呢。
# [A. Phoenix and Gold](https://codeforces.com/contest/1515/problem/A)
## 题意
t组，每组给出整数n和x，再给出长为n的序列，判断是否存在某种排列使该序列任意前缀和不为x。注意任意两个数都是不同的。
不存在输出NO，存在输出YES和任意合题排列。
## 题解
首先找到NO的情况，因为这里排列任意且每个数不同，所以只有当总和为x才是NO。
再来找出YES的排列，可以将序列排序，然后依次选择，并一边记录前缀和，当某个数加入后前缀和为x说明不能在这个时候加入，那么可以先把这个数拿出来，选择后面的数放进答案里，因为每个数不同并且序列有序，所以这种情况最多只会出现一次，可以把答案存起来也可以一边输出一边读。
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
const ll N=102;
ll a[N];
ll b[N];
int main()
{
    IOS
    int t;cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll all=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            all+=a[i];
            //if(i==0)b[i]=a[i];
            //else b[i]=a[i]+b[i-1];
        }
        ll t=0;
        vector<ll>res;
        if(all==x)cout<<"NO\n";
        else {
            cout<<"YES\n";
            all=0;
            for(ll i=0;i<n;i++){
                all+=a[i];
                if(all!=x)cout<<a[i]<<' ';
                else {
                    all-=a[i];
                    res.push_back(a[i]);
                }
            }
            for(auto i:res)cout<<i<<' ';
            cout<<'\n';
        }
    }
    //SYP
    r0
}
```
# [B. Phoenix and Puzzle](https://codeforces.com/contest/1515/problem/B)
## 题意
给n个相等的等腰直角三角形，判断是否能组成一个正方形。
中间不能有空，n个都要用到。
## 题解
首先找到最小子问题，等腰直角三角形组成最小正方形需要2个或者4个，组成之后就可以用这种正方形组成更大的正方形。我们可以这么看，先组成一个小正方形，然后排列成m行m列形式，那么总共需要m^2个小正方形。至于这个最小正方形就是由2个或者4个三角形组成。
那么问题就解决了，有2和4两种情况，先判断n能否被2和4整除，再对其整除结果判断是否是平方数。
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
bool IsSquare(ll num)
{
    if(num==1)return 1;
	for(ll i=1; num>0; i+=2){num -= i;}
	if(num==0){return true;}
	else{return false;}
}
int main()
{
    IOS
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll a=n/2,b=n/4;
        if(n==1||n==3||n==0)cout<<"NO\n";
        else if((n%2==0&&IsSquare(a))||(n%4==0&&IsSquare(b)))cout<<"YES\n";
        else cout<<"NO\n";
    }
    //SYP
    r0
}
```
# [C. Phoenix and Towers](https://codeforces.com/contest/1515/problem/C)
## 题意
t组，n个石块和目标m个塔，每个石块有个高度h，要用石块搭m个塔，并且任意两个塔高度差不能大于x。
不存在一种方案输出NO，否则输出YES，然后按输入顺序输出每个石块对应塔的编号。
## 题解
结构体cc存下每个石块，三个属性为高度va，输入序号no，对应塔编号ans。用贪心来放，先对石块按va排序，然后按顺序放进每个塔，超过了就回头，每次放的时候判断一下当前塔与下一个塔的高度差，如果大于x说明不合题意，直接break输出no，否则重新按no排序，然后按顺序输出其ans。
正确性在于石块已经排好序，左边的必定高度低点，每次放上之后还比右边的大说明不合题了。

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
const ll N=1e5+5;
struct cc
{
    ll va;
    ll no;
    ll ans;
}a[N];
ll b[N];
bool cmp(cc x,cc y){return x.va<y.va;}
bool cmppp(cc x,cc y){return x.no<y.no;}
int main()
{
    IOS
    int t;cin>>t;
    while(t--){
        ll n,m,x;
        cin>>n>>m>>x;
        memset(b,0,sizeof b);
        for(ll i=0;i<n;i++)cin>>a[i].va,a[i].no=i;
        sort(a,a+n,cmp);
        bool flag=1;
        ll p=0;
        for(ll i=0;i<n;i++){
            if((ll)abs(b[p]+a[i].va-b[(p+1)%m])>x){
                flag=0;break;
            }
            else {
                a[i].ans=p;
                b[p]+=a[i].va;
            }
            p++;p%=m;
        }
        if(flag==0)cout<<"NO\n";
        else {
            cout<<"YES\n";
            sort(a,a+n,cmppp);
            for(ll i=0;i<n;i++)cout<<a[i].ans+1<<' ';
            cout<<'\n';
        }
    }
    //SYP
    r0
}
```
# [D. Phoenix and Socks](https://codeforces.com/contest/1515/problem/D)
## 题意
t组，有n个袜子，l个左r个右，每个袜子有一种颜色。
要求使用最少花费配对出n/2对同颜色的袜子。每次花费可以选择以下一种操作：

 - 变换某个袜子的颜色
 - 把左袜变右袜
 - 把右袜变左袜

## 题解
贪心。首先考虑到原本就有一些已经匹配好的袜子，我们可以读完把这些去掉。然后再考虑袜子不同的情况，因为换边和换颜色我们肯定要先换边。那么换边的时候我们应该贪心地把多的那边有重复颜色的往另一边放，因为这样子主要换边之后其颜色也是匹配的，只要花费1，而不需要花上换颜色的花费。
这里偷一下师兄的码
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/trie_policy.hpp>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define inf std::numeric_limits<int>::max()
#define in read()
#define pb push_back
#define out(x) write(x);
using namespace __gnu_pbds;
using namespace std;
const double PI = acos(-1.0);
#define Please return
#define AC 0

struct _IO
{
    _IO()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
} _io;
inline void write(ll x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline ll read()
{
    ll s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

ll qpow(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = x * ans;
        x = x * x;
        y >>= 1;
    }
    return ans;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,l,r;
        cin>>n>>l>>r;
        int ttt=max(l,r)-min(l,r);
        int a[n+1],c=0;
        for(int i=0;i<=n;i++){
            a[i]=0;
        }
        for(int i=1;i<=l;i++){
            int g;
            cin>>g;
            a[g]++;
        }
        for(int i=1;i<=r;i++){
            int g;
            cin>>g;
            a[g]--;
        }
        ll ans=0,xx=0,yy=0;
        for(int i=1;i<=n;i++){
            c+=(abs(a[i])/2)*2;
            if(a[i]>0){
                xx+=a[i];
            }
            if(a[i]<0){
                yy-=a[i];
            }
        }
        /*for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;*/
        int g=abs(yy-xx);
        if(yy>xx){
            for(int i=1;i<=n;i++){
                if(g==0){
                    break;
                }
                if(a[i]<0){
                    ll gg=abs(a[i])/2;
                    ll ggg=min(gg,(yy-xx)/2);
                    ans+=ggg;
                    yy-=ggg*2;
                }
                else
                {
                    continue;
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(g==0){
                    break;
                }
                if(a[i]>0){
                    ll gg=abs(a[i])/2;
                    ll ggg=min(gg,(xx-yy)/2);
                    ans+=ggg;
                    xx-=ggg*2;
                }
                else
                {
                    continue;
                }
            }
        }
        cout<<ans+(xx+yy)/2+abs(yy-xx)/2<<endl;
    }
}
```
