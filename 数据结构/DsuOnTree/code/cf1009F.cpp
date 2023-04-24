/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-24 19:40:28
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-05-25 21:32:19
 * @FilePath: \apricitye:\桌面\ACM\数据结构\DsuOnTree\code\cf1009f.cpp
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
/*  cf1009f:<https://codeforces.com/contest/1009/problem/F>
    Dsu On Tree
    定义d[x,i]:满足 和x相距i条边的子节点 的个数
    求f[x]:满足d[x,k]按k从小到大第一个最大值时的k
*/
void init(){}
struct DsuOnTree {
#define MAX 1000055
    int n, rot;
    int dep[MAX], sz[MAX], bson[MAX];
    vector<int> e[MAX];
    // info
    int ans[MAX];
    int cnt[MAX];
    int maxn_cnt, maxn_id;
    //
    inline void dfs_sz(int u,int fa) {
        sz[u]=1;
        if(fa==-1) dep[u]=1;
        else dep[u]=dep[fa]+1;
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
        // update
        cnt[dep[u]]+=val;
        if(cnt[dep[u]]>maxn_cnt||(cnt[dep[u]]==maxn_cnt&&dep[u]<maxn_id)) {
            maxn_cnt=cnt[dep[u]];
            maxn_id=dep[u];
        }
        //
        for(auto v:e[u]) {
            if(v==fa||v==Bson) continue;
            update(v,u,Bson,val);
        }
    }
    inline void re_update(int u,int fa) {
        update(u,fa,-1,-1);
        maxn_cnt=maxn_id=0;
    }
    inline void dfs_cal(int u,int fa,bool keep) {
        for(auto v:e[u]) {
            if(v==fa||v==bson[u]) continue;
            dfs_cal(v,u,0);
        }
        if(bson[u]!=-1) dfs_cal(bson[u],u,1);
        update(u,fa,bson[u],1);
        // GetAns
        ans[u]=max(0,maxn_id-dep[u]);
        //
        if(!keep) re_update(u,fa);
    }
};
DsuOnTree px;
void PX()
{
    int n;cin>>n;
    px.n=n; px.rot=1;
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;
        px.e[u].push_back(v);
        px.e[v].push_back(u);
    }
    px.dfs_sz(1,-1);
    px.dfs_cal(1,-1,0);
    for(int i=1;i<=n;i++) cout<<px.ans[i]<<"\n";
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