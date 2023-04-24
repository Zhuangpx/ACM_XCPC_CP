# [AcWing 99. 激光炸弹 ](https://www.acwing.com/problem/content/101/)

二维前缀和模拟即可。

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
const int N=5011;
int a[N][N];
int main()
{
    //IOS
    //memset(a,0,sizeof a);
    int t,r;cin>>t>>r;
    int n=r,m=r;
    for(int i=0;i<t;i++){
        int x,y,z;cin>>x>>y>>z;
        x++,y++;
        a[x][y]+=z;//注意有可能重复同一个点 所以要+=
        n=max(n,x);
        m=max(m,y);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=(a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j]);
        }
    }
    int ans=0;
    for(int i=r;i<=n;i++){
        for(int j=r;j<=m;j++){
            ans=max(ans,a[i][j]-a[i-r][j]-a[i][j-r]+a[i-r][j-r]);
        }
    }
    cout<<ans<<'\n';
    SYP
    r0
}
```

