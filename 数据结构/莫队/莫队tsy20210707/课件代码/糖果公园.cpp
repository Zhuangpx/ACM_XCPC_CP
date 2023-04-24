#include<bits/stdc++.h>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 2005005
#define minn -105
#define ll long long int
#define ull unsigned long long int
#define uint unsigned int
using namespace std;
inline ll read()
{
    ll ans=0;
    char last=' ',ch=getchar();
    while(ch<'0'|ch>'9')last=ch,ch=getchar();
    while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
    if(last=='-')ans=-ans;
    return ans;
}
struct treenode
{
    int fa,hson,sz,depth,top;
    vector<int>nxt;
}t[maxn];
struct Query
{
    int l,r,id,version;
    int posl,posr;
    bool operator<(const Query& sec)const
    {
        if(posl!=sec.posl)return l<sec.l;
        if(posr!=sec.posr)return r<sec.r;
        return version<sec.version;
    }
}q[maxn];
int block_size,Q;
int color[maxn],cnt[maxn],ver[maxn],save[maxn],v[maxn],w[maxn],c[maxn],vis[maxn];
int in[maxn],out[maxn],id[maxn]; //tree_to_array
int l=1,r=0,n,m,version=0,tot=0,pos,newval,x,y,tmp1,tmp2,trans,stamp=1;
ll sum=0,ans[maxn];
void dfs1(int pos)
{
    in[pos]=++stamp;id[stamp]=pos;
    t[pos].hson=-1; //heavyson shoule be -1
    t[pos].sz=1;
    for(int k:t[pos].nxt)
    {
        if(!t[k].depth)
        {
            t[k].depth=t[pos].depth+1;
            t[k].fa=pos;
            dfs1(k);
            t[pos].sz+=t[k].sz;
            if(t[pos].hson==-1||t[k].sz>t[t[pos].hson].sz)
            {
                t[pos].hson=k;
            }
        }
    }
    out[pos]=++stamp;id[stamp]=pos;
}
void dfs2(int pos,int top)
{
    t[pos].top=top;
    if(t[pos].hson==-1)return;
    dfs2(t[pos].hson,top); //to visit heavy_son first
    for(int k:t[pos].nxt)
    {
        if(k!=t[pos].fa&&k!=t[pos].hson)dfs2(k,k);
    }
}
int query_LCA(int a,int b)
{
    while(t[a].top!=t[b].top)
    {
        if(t[t[a].top].depth<t[t[b].top].depth)swap(a,b);
        a=t[t[a].top].fa;
    }
    return t[a].depth<t[b].depth?a:b;
}
inline void add(int cur) //cur: the number of node, in xor, add and del are equivalent
{
    if(vis[cur]==0)
    {
        sum+=1ll*v[color[cur]]*w[++cnt[color[cur]]];
    }
    else
    {
        sum-=1ll*v[color[cur]]*w[cnt[color[cur]]--];
    }
    vis[cur]^=1;
}
inline void work(int cur) //cur: the version
{
    int num=ver[cur],clr=save[cur]; // clr:color
    if((l<=in[num]&&in[num]<=r)^(l<=out[num]&&out[num]<=r))
    {
        sum+=1ll*v[clr]*w[++cnt[clr]];
        sum-=1ll*v[color[num]]*w[cnt[color[num]]--];
    }
    swap(save[cur],color[num]);
}
int main()
{
    n=read(),m=read(),Q=read();
    block_size=pow((n<<1),0.667);
    for(register int i=1;i<=m;i++)
    {
        v[i]=read();
    }
    for(register int i=1;i<=n;i++)
    {
        w[i]=read();
    }
    for(int i=0;i<n-1;i++)
    {
        tmp1=read(),tmp2=read();
        t[tmp1].nxt.push_back(tmp2);
        t[tmp2].nxt.push_back(tmp1);
    }
    t[1].depth=1;
    dfs1(1);
    dfs2(1,1);
    for(int i=1;i<=n;i++)
        color[i]=read();
    for(register int i=0;i<Q;i++)
    {
        trans=read();
        if(trans==1)
        {
            tmp1=read(),tmp2=read();
            if(in[tmp1]>in[tmp2])swap(tmp1,tmp2);
            if(out[tmp1]<out[tmp2])q[tot].l=out[tmp1];
            else q[tot].l=in[tmp1];
            q[tot].r=in[tmp2];
            q[tot].posl=q[tot].l/block_size;
            q[tot].posr=q[tot].r/block_size;
            q[tot].id=tot;q[tot].version=version;
            tot++;
        }
        else
        {
            version++;
            ver[version]=read();
            save[version]=read();
        }
    }
    sort(q,q+tot);
    version=0;
    for(register int i=0;i<tot;i++)
    {
        while(l>q[i].l)add(id[--l]);
        while(r<q[i].r)add(id[++r]);
        while(l<q[i].l)add(id[l++]);
        while(r>q[i].r)add(id[r--]);
        while(version<q[i].version)work(++version);
        while(version>q[i].version)work(version--);
        x=id[l],y=id[r];
        int f=query_LCA(x,y);
        if(f!=x&&f!=y)
        {
            add(f);
            ans[q[i].id]=sum;
            add(f);
        }
        else ans[q[i].id]=sum;
    }
    for(register int i=0;i<tot;i++)printf("%lld\n",ans[i]);
    return 0;
}
