#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
#define uint unsigned int
#define rep(x,y,z) for(int x=y;x<=z;x++)
const int maxn=3e5+25;
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
int ans[maxn],color[maxn],curl[maxn],curr[maxn],tmpl[maxn],tmpr[maxn],s[maxn];
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
int __l[maxn],__r[maxn];
int brute(int l,int r)
{
    int mxx=0;
    rep(i,l,r)
    {
        if(!__l[color[i]])__l[color[i]]=i;
        __r[color[i]]=i;
        mxx=max(mxx,__r[color[i]]-__l[color[i]]);
    }
    rep(i,l,r)__l[color[i]]=0,__r[color[i]]=0;
    return mxx;
}
int main()
{
    n=read();
    memset(tmpl,INF,sizeof(tmpl));
    memset(curl,INF,sizeof(curl));
    block_size=sqrt(n);
    rep(i,1,n)s[i]=color[i]=read();
    sort(s+1,s+n+1);
    int sz=unique(s+1,s+n+1)-s-1;
    rep(i,1,n)color[i]=lower_bound(s+1,s+1+n,color[i])-s;

    m=read();
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
            while(r>=l)curr[color[r]]=0,curl[color[r]]=INF,r--; // reset
            l=(q[i].l/block_size+1)*block_size;r=l-1;
        }
        while(r<q[i].r)
        {
            ++r;
            curl[color[r]]=min(r,curl[color[r]]);
            curr[color[r]]=r;mx=max(mx,curr[color[r]]-curl[color[r]]);
        }
        int curmx=mx;
        rep(j,q[i].l,l-1)
        {
            tmpl[color[j]]=min(tmpl[color[j]],j);
            tmpr[color[j]]=max(tmpr[color[j]],j);
            curmx=max(curmx,max(tmpr[color[j]],curr[color[j]])-min(tmpl[color[j]],curl[color[j]]));
        }
        rep(j,q[i].l,l-1)
        {
            tmpl[color[j]]=INF;
            tmpr[color[j]]=0;
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
