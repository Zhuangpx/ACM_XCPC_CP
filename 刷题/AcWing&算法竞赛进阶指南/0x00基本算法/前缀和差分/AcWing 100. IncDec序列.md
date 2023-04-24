# [AcWing 100. IncDec序列](https://www.acwing.com/problem/content/description/102/)

差分一下。

![image-20210420145127176](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210420145127176.png)

![image-20210420145136375](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210420145136375.png)

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
const int N=1e5+5;
ll a[N];
ll b[N];
int main()
{
    //IOS
    ll n;
    ll p=0,q=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-a[i-1];
        if(i>1&&b[i]>0)p+=b[i];
        else if(i>1&&b[i]<0)q-=b[i];
    }
    cout<<max(p,q)<<'\n'<<(ll)abs(p-q)+1<<'\n';
    //SYP
    r0
}
```

