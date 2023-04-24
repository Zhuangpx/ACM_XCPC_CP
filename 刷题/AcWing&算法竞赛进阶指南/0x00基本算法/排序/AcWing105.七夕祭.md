# [七夕祭](https://www.acwing.com/problem/content/107/)

有n*m个点，其中t个是感兴趣的，要求通过交换相邻位置的点使得每行/每列感兴趣的点一样多。特殊的，最后一个和第一个也认为是相邻的。

容易发现行和列的交换的独立的，因此我们可以分开处理，那么对于每行/每列就是环形均分纸牌(糖果传递)的问题了。

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int u=100010; 
long long b[u],c[u],f[u];
long long n,m,t,i,j,x,y;

long long calc(long long a[u],int n)
{
    long long ans=0; int i;
    for(i=1;i<=n;i++)
    {
        a[i]-=a[0]/n;
        f[i]=f[i-1]+a[i];
    }
    sort(f+1,f+n+1);
    for(i=1;i<=n;i++) ans+=abs(f[i]-f[n+1>>1]);
    return ans;
}

int main()
{
    cin>>n>>m>>t;
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&x,&y);
        b[x]++,c[y]++; 
    }
    for(i=1;i<=n;i++) b[0]+=b[i];
    for(i=1;i<=m;i++) c[0]+=c[i];
    if(b[0]%n==0&&c[0]%m==0)
        printf("both %lld\n",calc(b,n)+calc(c,m));
    else if(b[0]%n==0)
        printf("row %lld\n",calc(b,n));
    else if(c[0]%m==0)
        printf("column %lld\n",calc(c,m));
    else puts("impossible");
    return 0;
}
```

