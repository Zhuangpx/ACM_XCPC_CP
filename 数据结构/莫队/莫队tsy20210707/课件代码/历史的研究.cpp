#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
#define int long long
#define uint unsigned int
#define rep(x,y,z) for(int x=y;x<=z;x++)
const int maxn=2e5+25;
inline int read()
{
    int ans=0;
    char last=' ',ch=getchar();
    while(ch<'0'|ch>'9')last=ch,ch=getchar();
    while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
    if(last=='-')ans=-ans;
    return ans;
}
int block_size; // Äª¶Ó¿é´óÐ¡
int ans[maxn],color[maxn],cnt[maxn],tmpcnt[maxn],val[maxn],s[maxn];
int l=1,r=0,sum=0,n,m,mx;
struct Query
{
    int l,r,id;
    bool operator<(const Query& sec)const
    {
        if(l/block_size!=sec.l/block_size)return l<sec.l;
        return r<sec.r;
    }
}q[maxn];
int __cnt[maxn];
int brute(int l,int r)
{
    int mxx=0;
    rep(i,l,r)
    {
        __cnt[color[i]]++;
        mxx=max(mxx,__cnt[color[i]]*val[i]);
    }
    rep(i,l,r)__cnt[color[i]]=0;
    return mxx;
}
signed main()
{
    n=read(),m=read();
    block_size=sqrt(n);
    rep(i,1,n)s[i]=val[i]=color[i]=read();
    sort(s+1,s+n+1);
    int sz=unique(s+1,s+n+1)-s-1;
    rep(i,1,n)color[i]=lower_bound(s+1,s+1+n,color[i])-s;

    rep(i,0,m-1)
    {
        q[i].l=read(),q[i].r=read();
        q[i].id=i;
    }
    sort(q,q+m);

    rep(i,0,m-1)
    {
        if(q[i].l/block_size==q[i].r/block_size) // l,r are in the same block, then brute
        {
            ans[q[i].id]=brute(q[i].l,q[i].r);
            continue;
        }
        if((q[i].l/block_size+1)*block_size!=l) // l goes into another block
        {
            mx=0;
            while(r>=l)cnt[color[r]]=0,r--; // reset
            l=(q[i].l/block_size+1)*block_size;r=l-1;
        }
        while(r<q[i].r)
        {
            ++r;
            cnt[color[r]]++;
            mx=max(mx,cnt[color[r]]*val[r]);
        }

        int curmx=mx;
        rep(j,q[i].l,l-1)
        {
            tmpcnt[color[j]]++;
            curmx=max(curmx,(cnt[color[j]]+tmpcnt[color[j]])*val[j]);
        }
        rep(j,q[i].l,l-1)
        {
            tmpcnt[color[j]]=0;
        }
        ans[q[i].id]=curmx;
    }
    rep(i,0,m-1)cout<<ans[i]<<"\n";
    return 0;
}
/*
8
1 6 2 2 3 3 1 6
5
1 4
2 5
2 8
5 6
1 7

*/
