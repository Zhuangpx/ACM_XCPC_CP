#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define maxn 2000005
#define minn -105
#define ll long long
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
int ans[maxn],color[maxn],cnt[maxn],pos[maxn],nxt[maxn];
int l=1,r=0,sum=0,n,m,t=0,tot=0,newval;
char trans;
struct Query
{
    int l,r,id,t;
    int posl,posr;
    bool operator<(const Query& sec)const
    {
        if(posl!=sec.posl)return l<sec.l;
        if(posr!=sec.posr)return r<sec.r;
        return t<sec.t;
    }
}q[maxn];
inline void add(int cur)
{
    if(++cnt[cur]==1)sum++;
}
inline void del(int cur)
{
    if(--cnt[cur]==0)sum--;
}
inline void work(int cur)
{
    if(l<=pos[cur]&&pos[cur]<=r)
    {
        if(--cnt[color[pos[cur]]]==0)sum--;
        if(++cnt[nxt[cur]]==1)sum++;
    }
    std::swap(nxt[cur],color[pos[cur]]);
}
int main()
{
    n=read(),m=read();
    block_size=pow(n,0.667);
    for(register int i=1;i<=n;i++)
        color[i]=read();
    for(register int i=0;i<m;i++)
    {
        std::cin>>trans;
        if(trans=='Q')
        {
            q[tot].l=read(),q[tot].r=read();
            q[tot].posl=q[tot].l/block_size;
            q[tot].posr=q[tot].r/block_size;
            q[tot].id=tot;q[tot].t=t;
            tot++;
        }
        else
        {
            t++;
            pos[t]=read(); // 记录版本号为t的更新的位置号
            nxt[t]=read(); // 暂存该版本对换信息，新换旧要把旧的存回来，旧换新要把新的存回来
        }
    }
    std::sort(q,q+tot);
    t=0;
    for(register int i=0;i<tot;i++)
    {
        while(l>q[i].l)add(color[--l]);
        while(r<q[i].r)add(color[++r]);
        while(l<q[i].l)del(color[l++]);
        while(r>q[i].r)del(color[r--]);
        while(t<q[i].t)work(++t);
        while(t>q[i].t)work(t--);
        ans[q[i].id]=sum;
    }
    for(register int i=0;i<tot;i++)printf("%d\n",ans[i]);
    return 0;
}
