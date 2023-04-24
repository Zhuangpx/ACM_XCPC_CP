#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define swap(a,b) (a^=b^=a^=b)
const int maxn=3e5+20;
#define ll long long int
#define ull unsigned long long int
#define uint unsigned int
#define format(a) memset(a,0,sizeof(a))
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define dec(x,y,z) for(int x=y;x>=z;x--)
#define mst(x) memset(x,0,sizeof(x))
inline int read()
{
    int ans=0;
    char last=' ',ch=getchar();
    while(ch<'0'|ch>'9')last=ch,ch=getchar();
    while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
    if(last=='-')ans=-ans;
    return ans;
}
int in[maxn],out[maxn],a[maxn],b[maxn],save[maxn];
int n,ans,stamp;
vector<int>node[maxn],node2[maxn];
void init()
{
    rep(i,0,n)node[i].clear(),node2[i].clear(),in[i]=out[i]=0;
    ans=0,stamp=0;
}
void dfs(int cur)
{
    in[cur]=++stamp;save[stamp]=cur;
    for(auto nxt:node[cur])
    {
        dfs(nxt);
    }
    out[cur]=stamp;
}
set<int>s;
void dfs2(int cur)
{
    int del=-1,add=-1;
    auto it=s.upper_bound(in[cur]);
    if(it==s.end()||*it>out[cur])
    {
        if(it!=s.begin())
        {
            it--;
            if(out[save[*it]]>=out[cur])
            {
                del=*it;
                s.erase(del);
            }
        }
        add=in[cur];
        s.insert(add);
    }
    ans=max(ans,(int)s.size());
    for(auto nxt:node2[cur])
    {
        dfs2(nxt);
    }
    if(del!=-1)s.insert(del);
    if(add!=-1)s.erase(add);
}
void solve()
{
    n=read();
    init();
    rep(i,2,n)
    {
        int x=read();
        node2[x].push_back(i);
    }
    rep(i,2,n)
    {
        int x=read();
        node[x].push_back(i);
    }
    dfs(1);
    dfs2(1);
    cout<<ans<<"\n";
}
int main()
{
    int _t;
    _t=read();
    while(_t--)solve();
    return 0;
}
