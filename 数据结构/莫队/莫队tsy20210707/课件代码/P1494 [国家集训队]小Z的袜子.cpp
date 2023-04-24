#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 0x3f3f3f3f
#define max(a,b) (a>b ? a:b)
#define min(a,b) (a<b ? a:b)
#define swap(a,b) (a^=b^=a^=b)
#define maxn 50005
#define minn -105
#define ll long long int
#define ull unsigned long long int
#define uint unsigned int
inline int read()
{
    int ans=0;
    char last=' ',ch=getchar();
    while(ch<'0'|ch>'9')last=ch,ch=getchar();
    while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
    if(last=='-')ans=-ans;
    return ans;
}
int block_size;
ll ans1[maxn],ans2[maxn];
int color[maxn];
int cnt[maxn];
int l=1,r=0;
int sum=0,n,m;
struct Query
{
    int l,r,id;
    bool operator<(const Query& sec)const
    {
        if(l/block_size!=sec.l/block_size)return l<sec.l;
        return r<sec.r;
    }
}q[maxn];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
void add(int cur)
{
    sum+=cnt[cur];
    cnt[cur]++;
}
void del(int cur)
{
    --cnt[cur];
    sum-=cnt[cur];
}
int main()
{
    cin>>n>>m;
    block_size=sqrt(n);
    for(int i=1;i<=n;i++)
        cin>>color[i];
    for(int i=0;i<m;i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q,q+m);
    for(int i=0;i<m;i++)
    {
        if(q[i].l==q[i].r)
            continue;
        while(l>q[i].l)add(color[--l]);
        while(r<q[i].r)add(color[++r]);
        while(l<q[i].l)del(color[l++]);
        while(r>q[i].r)del(color[r--]);
        ans1[q[i].id]=sum;
        ans2[q[i].id]=1ll*(r-l+1)*(r-l)/2;
    }
    for(int i=0;i<m;i++)
    {
        if(ans1[i])
        {
            ll g=gcd(ans1[i],ans2[i]);
            cout<<ans1[i]/g<<"/"<<ans2[i]/g<<"\n";
        }
        else
            cout<<"0/1\n";
    }
    return 0;
}
