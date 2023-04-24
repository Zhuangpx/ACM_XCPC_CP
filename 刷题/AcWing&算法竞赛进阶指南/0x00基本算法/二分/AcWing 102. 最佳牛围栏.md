# AcWing 102. [最佳牛围栏](https://www.acwing.com/problem/content/description/104/)

一道实数域二分题，很适合做二分训练。

[题解](https://www.acwing.com/solution/content/1148/)

```c++
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
db a[N];
db ans;
ll n,f;
db sum[N];
bool check(ll m)
{
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(a[i]-m);
    db mn=0;
    for(int i=0,j=f;j<=n;j++,i++){
        mn=std::min(mn,sum[i]);
        if(sum[j]-mn>=0)return 1;
    }
    return 0;
}
int main()
{
    IOS
    std::cin>>n>>f;
    ll maxn=0,minn=N;
    db l=0,r=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        r=std::max(r,(double)a[i]);
    }
    while(r-l>1e-5){
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    std::cout<<setprecision(5)<<(ll)(r*1000)<<'\n';
    SYP
    r0
}
```

