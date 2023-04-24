#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
int ans[maxn],color[maxn],cnt[maxn],cnt2[maxn];
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
int getans(int x,int m)
{
    if(m<=(x+1)/2)return 1;
    return 2*m-x;
}
int __cnt[maxn];
int brute(int l,int r)
{
    int mxx=0;
    rep(i,l,r)__cnt[color[i]]++,mxx=max(mxx,__cnt[color[i]]);
    rep(i,l,r)__cnt[color[i]]--;
    return mxx;
}
int main()
{
    n=read(),m=read();
    block_size=sqrt(n)+3;
    rep(i,1,n)color[i]=read();
    rep(i,0,m-1)
    {
        q[i].l=read(),q[i].r=read();
        q[i].id=i;
    }
    sort(q,q+m);
    rep(i,0,m-1)
    {
        if(q[i].l/block_size==q[i].r/block_size)
        {
            ans[q[i].id]=getans(q[i].r-q[i].l+1,brute(q[i].l,q[i].r));
            continue;
        }
        if((q[i].l/block_size+1)*block_size!=l)
        {
            mx=0;
            while(r>=l)cnt[color[r--]]--;
            l=(q[i].l/block_size+1)*block_size;r=l-1;
        }
        while(r<q[i].r)
        {
            ++r;cnt[color[r]]++;mx=max(mx,cnt[color[r]]);
        }
        int curmx=mx;
        rep(j,q[i].l,l-1)
        {
            cnt2[color[j]]++;curmx=max(curmx,cnt[color[j]]+cnt2[color[j]]);
        }
        rep(j,q[i].l,l-1)
        {
            cnt2[color[j]]--;
        }
        ans[q[i].id]=getans(q[i].r-q[i].l+1,curmx);
    }
    rep(i,0,m-1)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}
/*
6 6
1 2 3 3 2 1
2 6
3 4
1 3
2 5
1 6
2 6

6 6
3 3 3 3 3 3
1 1
2 2
3 3
4 4
5 5
6 6


*/
