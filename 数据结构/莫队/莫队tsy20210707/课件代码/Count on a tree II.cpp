#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
#define uint unsigned int
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
int block_size; // 莫队块大小
int ans[maxn],color[maxn],cnt[maxn],in[maxn],out[maxn],save[maxn],appr[maxn];
int l=1,r=0,sum=0,n,m,mx,stamp=0,num=0,mapcnt=0;
vector<int>node[maxn];
map<int,int>ma;
struct Query
{
    int l,r,id,lca;
    bool operator<(const Query& sec)const
    {
        if(l/block_size!=sec.l/block_size)return l<sec.l;
        return r<sec.r;
    }
}q[maxn];
struct treenode
{
    int fa,hson,sz,depth,top;
    vector<int>nxt;
}t[maxn];
void dfs1(int pos,int fa)
{
    in[pos]=++stamp;save[stamp]=pos;
    t[pos].hson=-1; //heavyson shoule be -1
    t[pos].sz=1;
    for(int k:t[pos].nxt)
    {
        if(k==fa)continue;
        if(!t[k].depth)
        {
            t[k].depth=t[pos].depth+1;
            t[k].fa=pos;
            dfs1(k,pos);
            t[pos].sz+=t[k].sz;
            if(t[pos].hson==-1||t[k].sz>t[t[pos].hson].sz)
            {
                t[pos].hson=k;
            }
        }
    }
    out[pos]=++stamp;save[stamp]=pos;
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

// 因为是采用异或思想，add与del实质一样
void add(int cur)
{
    if(appr[cur])
    {
        cnt[color[cur]]--;
        if(cnt[color[cur]]==0)num--;
    }
    else
    {
        cnt[color[cur]]++;
        if(cnt[color[cur]]==1)num++;
    }
    appr[cur]^=1;
}
void del(int cur)
{
    add(cur);
}
int main()
{
    n=read(),m=read();
    block_size=sqrt(2*n)+1;
    for(int i=1;i<=n;i++)
    {
        color[i]=read();
        if(!ma[color[i]])ma[color[i]]=++mapcnt;
        color[i]=ma[color[i]];
    }
    for(int i=0;i<n-1;i++)
    {
        int x=read(),y=read();
        t[x].nxt.push_back(y);
        t[y].nxt.push_back(x);
    }
    dfs1(1,0);dfs2(1,1);
    for(int i=0;i<m;i++)
    {
        int x=read(),y=read(),lca=query_LCA(x,y);
        if(x==lca||y==lca)
        {
            if(y==lca)swap(x,y);
            q[i].l=in[x],q[i].r=in[y];
        }
        else
        {
            if(in[y]<in[x])swap(x,y);
            q[i].lca=lca;
            q[i].l=out[x],q[i].r=in[y];
        }
        q[i].id=i;
    }
    sort(q,q+m);
    for(int i=0;i<m;i++)
    {
        while(l>q[i].l)add(save[--l]);
        while(r<q[i].r)add(save[++r]);
        while(l<q[i].l)del(save[l++]);
        while(r>q[i].r)del(save[r--]);
        ans[q[i].id]=num;
        if(q[i].lca)
        {
            if(cnt[color[q[i].lca]]==0)ans[q[i].id]++;
            /*
                也可以写成：
                add(lca);
                ans[q[i].id]=num;
                add(lca);
            */
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}
/*
8 2
105 2 9 3 8 5 7 7
1 2
1 3
1 4
3 5
3 6
3 7
4 8
2 5
7 8
*/
