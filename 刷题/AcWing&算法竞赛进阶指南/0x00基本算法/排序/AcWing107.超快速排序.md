# [AcWing 107. 超快速排序](https://www.acwing.com/problem/content/109/)

要求冒泡排序交换次数，实际上就是逆序对数，因为每一对都是冒泡时需要进行的交换。

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
using namespace std;
const ll N=5e5+5;
ll ans;
ll a[N],c[N];
void merge(int x,int y)
{
    if(x==y)return ;
    int mid=(x+y)/2,i=x,j=mid+1,k=x;
    merge(x,mid),merge(mid+1,y);
    while(i<=mid&&j<=y)
        if(a[i]<=a[j])c[k++]=a[i++];
        else c[k++]=a[j++],ans+=mid-i+1;
    while(i<=mid)c[k++]=a[i++];
    while(j<=y)c[k++]=a[j++];
    for(int p=x;p<=y;p++)a[p]=c[p];
    return ;
}
int main()
{
    IOS
    ll n;
    while(cin>>n&&n){
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        merge(1,n);
        cout<<ans<<'\n';
    }
    //system("pause");
    return 0;
}
```

