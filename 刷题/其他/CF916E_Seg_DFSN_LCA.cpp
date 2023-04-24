/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-07-11 00:26:18
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-08-10 15:40:58
 * @FilePath: \apricitye:\桌面\ACM\刷题\其他\CF916E_Seg_DFSN_LCA.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */


#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
typedef long long ll;
typedef unsigned long long ull;
#define UINF ~0ull
#define mod_ 99993
#define vii vector<int>
#define vvii vector<vector<int>>
#define vll vector<ll>
#define fi first
#define se second
const int mod = 1e9+7;
// const int mod = 998244353;
const int N = 1e5+55;
const long double eps=1e-6;
const long double PI=acos(-1.0);
ll mpow(ll a,ll b,ll m){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
#define pdec(t,ans) cout<<std::fixed<<std::setprecision(t)<<(ans)
inline bool _bug(bool _line=0,bool line_=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";if(line_)cout<<'\n';return 1;
#endif
    return 0;
}
/*
    CodeForces - 916E
    https://codeforces.com/problemset/problem/916/E
    线段树维护Dfs序 + LCA + 换根LCA（分类讨论）
*/
// bool multest = 1;
bool multest = 0;
int L[N], R[N]; //  dfs序子树的起点和终点
int dfsn[N];    //  dfs序
int n, q, cnt, root;
//  Template L
namespace SEGTREE {
    struct Segment_Tree //  Seg sum
    {
        ll a[N];
        struct node{ll lazy,sum;int l,r;} tree[N<<2];
        inline void push_up(int i){tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;}
        inline void build(int i,int l,int r)
        {
            tree[i]=node{0,0,l,r};
            if (l==r){tree[i].sum=a[dfsn[l]];return;}
            int mid=(l+r)>>1;
            build(i<<1,l,mid);
            build(i<<1|1,mid+1,r);
            push_up(i);
        }
        inline void push_down(int i)
        {
            tree[i<<1].lazy+=tree[i].lazy;
            tree[i<<1|1].lazy+=tree[i].lazy;
            tree[i<<1].sum+=(tree[i<<1].r-tree[i<<1].l+1)*tree[i].lazy;
            tree[i<<1|1].sum+=(tree[i<<1|1].r-tree[i<<1|1].l+1)*tree[i].lazy;
            tree[i].lazy=0;
        }
        inline void update(int i,int l,int r,ll x)
        {
            if ((tree[i].l==l)&&(tree[i].r==r))
            {
                tree[i].sum+=(r-l+1)*x;
                tree[i].lazy+=x;
                return;
            }
            if (tree[i].lazy!=0) push_down(i);
            int mid=(tree[i].l+tree[i].r)>>1;
            if (mid>=r) update(i<<1,l,r,x);
            else if (mid<l) update(i<<1|1,l,r,x);
            else
            {
                update(i<<1,l,mid,x);
                update(i<<1|1,mid+1,r,x);
            }
            push_up(i);
        }
        inline ll getsum(int i,int l,int r)
        {
            if ((tree[i].l==l)&&(tree[i].r==r)) return tree[i].sum;
            if (tree[i].lazy!=0) push_down(i);
            int mid=(tree[i].l+tree[i].r)>>1;
            if (mid>=r) return getsum(i<<1,l,r);
            else if (mid<l) return getsum(i<<1|1,l,r);
            else return getsum(i<<1,l,mid)+getsum(i<<1|1,mid+1,r);
        }
    };
}
namespace LCA   //  LCA
{
    int dp[N][21],dep[N];
    vector<int> g[N];
    inline void dfs(int x,int fa)
    {
        for(int i=0;i<g[x].size();i++)
        {
            int y=g[x][i];
            if (y==fa) continue;
            dep[y]=dep[x]+1;
            dp[y][0]=x; dfs(y,x);
        }
    }
    void ST()
    {
        for(int j=0;j<19;j++)
            for(int i=1;i<=n;i++)
                dp[i][j+1]=dp[dp[i][j]][j];
    }
    inline int lca(int u,int v)
    {
        if (u==v) return u;
        if (dep[v]>dep[u]) swap(u,v);
        for(int i=18;i>=0;i--)
            if (dep[dp[u][i]]>=dep[v]) u=dp[u][i];
        if (u==v) return u;
        for(int i=18;i>=0;i--)
            if (dp[u][i]!=dp[v][i]) u=dp[u][i],v=dp[v][i];
        return dp[u][0];
    }
}
using namespace LCA;
using namespace SEGTREE;
//  Template R
Segment_Tree seg;
inline void dfs_(int u, int fa) //  dfsn
{
    L[u]=++cnt;
    dfsn[cnt]=u;
    for(auto v:g[u]) {
        if(v==fa) continue;
        dfs_(v, u);
    }
    R[u]=cnt;
}
int getpos(int x,int y)
{
    int r = 18;
    while(r>=0) {
        if(dep[dp[y][r]]<=dep[x]) r--;
        else y=dp[y][r], r--;
    }
    return y;
}
int PX()
{
    root = 1;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> seg.a[i];
    for(int i=1;i<n;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[0]=-1;
    dfs_(1, 0); //  dfsn
    dfs(1, 0);ST(); //  LCA
    seg.build(1, 1, n); //  SegTree
    while(q--) {
        int op;
        cin >> op;
        if(op==1) {
            int u;
            cin >> u;
            root = u;
        }
        else if(op==2) {
            int u, v, val;
            cin >> u >> v >> val;
            //  Sel
            int Lca_a = lca(u, v);
            int Lca_b = lca(u, root);
            int Lca_c = lca(v, root);
            if(dep[Lca_a]>dep[Lca_b]) u=Lca_a;
            else u = Lca_b;
            if(dep[Lca_c]>dep[u]) u=Lca_c;
            v = lca(u, root);
            //
            if(u==v) {
                if(u!=root) {
                    seg.update(1,1,n,val);
                    int id = getpos(u,root);
                    seg.update(1,L[id],R[id],-val);
                    continue;
                }
            }
            if(u!=root) seg.update(1,L[u],R[u],val);
            else seg.update(1,1,n,val);
        }
        else {
            int u;
            cin >> u;
            int lca_ = lca(u, root);
            if(lca_==u) {
                if(u!=root) {
                    int id = getpos(u, root);
                    ll x = seg.getsum(1, 1, n);
                    ll y = seg.getsum(1, L[id], R[id]);
                    ll Ans = x - y;
                    cout << Ans << '\n';
                    continue;
                }
            }
            ll Ans = 0;
            if(u!=root) Ans = seg.getsum(1,L[u],R[u]);
            else Ans = seg.getsum(1, 1, n);
            cout << Ans << '\n';
        }
    }
    return 1;
}
signed main()
{
#ifdef LOCAL
    freopen("E:\\ACMdream\\in.txt", "r", stdin);
    freopen("E:\\ACMdream\\out.txt", "w", stdout);
    clock_t time1 = clock();
#endif
    IOS;
    //==================================================
    int ZPX = 1;
    if (multest)
        cin >> ZPX;
        // scanf("%d", &ZPX);
    // _Init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}