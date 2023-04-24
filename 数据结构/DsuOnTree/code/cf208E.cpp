/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-24 19:40:28
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-05-24 15:39:03
 * @FilePath: \apricitye:\桌面\ACM\数据结构\DsuOnTree\code\cf208E.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int ull
// #define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
typedef long long ll;
typedef unsigned long long ull;
#define UINF ~0ull
#define mod_ 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 2e5+55;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll _mpow(ll a,ll b,ll m=_mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline bool _bug(bool _line=0,bool line_=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";if(line_)cout<<'\n';return 1;
#endif
    return 0;
}
/*  cf208E:<https://codeforces.com/contest/208/problem/E>
    Dsu On Tree
    给子树v和深度h，求v深h的节点的兄弟节点权值种类数
    把问题转成父节点某一层子节点权值种类数即可
    预处理出节点的第k个祖先
*/
void init(){}
struct DsuOnTree {
#define MAX 500055
    int n, rot;
    int dep[MAX], sz[MAX], bson[MAX];
    vector<int> e[MAX];
    // ==   Infor
    vector<pair<int,int>> ans;
    vector<pair<int,int>> ask[MAX];
    int cnt[MAX];
    int fat[MAX];
    map<int,int> _fa[MAX];
    map<int,bool> vis[MAX];
    inline int find(int u,int h) {
        if(h==0) return u;
        int dis=dep[u]-h;
        for(int i=20;i>=0;i--) {
            if(dep[_fa[u][i]]>dis) u=_fa[u][i];
        }
        return _fa[u][0];
    }
    // ==
    inline void dfs_sz(int u,int fa) {
        sz[u]=1;
        if(fa==-1) dep[u]=1;
        else dep[u]=dep[fa]+1;
        _fa[u][0]=fa;
        for(int i=1;(1<<i)<=dep[u];i++) _fa[u][i]=_fa[_fa[u][i-1]][i-1];
        int ma=0;
        for(auto v:e[u]) {
            if(v==fa) continue;
            dfs_sz(v,u);
            sz[u]+=sz[v];
            if(sz[v]>ma) ma=sz[v], bson[u]=v;
        }
        if(ma==0) bson[u]=-1;
    }
    inline void update(int u,int fa,int Bson,int val) {
        // == update
        cnt[dep[u]]+=val;
        // ==
        for(auto v:e[u]) {
            if(v==fa||v==Bson) continue;
            update(v,u,Bson,val);
        }
    }
    inline void re_update(int u,int fa) {
        // re update
        update(u,fa,-1,-1);
    }
    inline void dfs_cal(int u,int fa,bool keep) {
        for(auto v:e[u]) {
            if(v==fa||v==bson[u]) continue;
            dfs_cal(v,u,0);
        }
        if(bson[u]!=-1) dfs_cal(bson[u],u,1);
        update(u,fa,bson[u],1);     //  cal
        // == GetAns
        for(auto [h,id]:ask[u]) {
            ans.push_back({id,cnt[h+dep[u]]-1});
        }
        // ==
        if(!keep) re_update(u,fa);   //  re cal
    }
};
DsuOnTree px;
void PX()
{
    int n;cin>>n;
    px.n=n;
    for(int i=1,d;i<=n;i++) {
        cin>>d;
        if(d) px.e[d].push_back(i), px.fat[i]=d;
    }
    for(int i=1;i<=n;i++) {
        if(!px.dep[i]) px.dfs_sz(i,-1);
    }
    int m;cin>>m;
    for(int i=1;i<=m;i++) {
        int v,h;cin>>v>>h;
        if(px.fat[v]==0) {
            px.ans.push_back({i,0});
            continue;
        }
        int u=px.find(v,h);
        // cout<<v<<' '<<h<<":"<<u<<'\n';
        if(u<=0) {
            px.ans.push_back({i,0});
            continue;
        }
        px.ask[u].push_back({h,i});
    }
    for(int i=1;i<=n;i++) {
        if(px.dep[i]==1) px.dfs_cal(i,-1,0);
    }
    sort(px.ans.begin(),px.ans.end());
    // for(auto [i,j]:px.ans) cout<<i<<' '<<j<<'\n';
    for(auto [i,j]:px.ans) cout<<j<<' ';
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
    ll ZPX = 1;
    // cin >> ZPX;
    init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}