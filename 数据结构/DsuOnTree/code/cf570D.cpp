/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-24 19:40:28
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-05-23 19:51:10
 * @FilePath: \apricitye:\桌面\ACM\数据结构\DsuOnTree\code\cf570D.cpp
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
/*  cf570D:<https://codeforces.com/contest/570/problem/D>
    Dsu On Tree
    给一棵有根树，节点上填有一个小写字母，询问给出子树的根v和高度h，考虑子树v高度h的所有节点上的字母能否构成回文串
*/
void init(){}
struct DsuOnTree {
#define MAX 500005
    int n, rot;
    int dep[MAX], sz[MAX], bson[MAX];
    vector<int> e[MAX];
    // ==   Infor
    int a[MAX];
    bool ans[MAX];
    int cnt[MAX][28];
    vector<pair<int,int>> ask[MAX];
    // ==
    inline void dfs_sz(int u,int fa) {
        if(u==rot) dep[u]=1;
        else dep[u]=dep[fa]+1;
        sz[u]=1;
        int ma=0;
        for(auto v:e[u]) {
            if(v==fa) continue;
            dfs_sz(v,u);
            sz[u]+=sz[v];
            if(sz[v]>ma) ma=sz[v], bson[u]=v;
        }
        if(ma==0) bson[u]=-1;
    }
    inline void update(int u,int fa,int Bson, int val) {
        cnt[dep[u]][a[u]]+=val;
        for(auto v:e[u]) {
            if(v!=Bson) update(v,u,Bson,val);
        }
    }
    inline void dfs_cal(int u,int fa,bool keep) {
        for(auto v:e[u]) {
            if(v==fa||v==bson[u]) continue;
            dfs_cal(v,u,0);
        }
        if(bson[u]!=-1) dfs_cal(bson[u],u,1);
        update(u,fa,bson[u],1); //  cal
        // == GetAns
        for(auto [h,id]:ask[u]) {
            int ji=0;
            bool ok=1;
            for(int c=1;c<=26;c++) {
                if(cnt[h][c]%2==1) ji++;
                if(ji>=2) ok=0;
                if(!ok) break;
            }
            ans[id]=ok;
        }
        // ==
        if(!keep) update(u,fa,-1,-1);  //  re cal
    }
};
DsuOnTree px;
void PX()
{
    int n,m;cin>>n>>m;
    px.n=n;
    px.rot=0;
    for(int i=1,d;i<n;i++) {
        cin>>d;d--;
        // if(d==i) continue;
        px.e[d].push_back(i);
        // px.e[i].push_back(d);
    }
    string s;cin>>s;
    for(int i=0;i<n;i++) {
        px.a[i]=s[i]-'a'+1;
    }
    px.dfs_sz(0,-1);
    for(int i=0;i<m;i++) {
        int v,h;cin>>v>>h;
        v--;
        // px.ask[v].push_back({h+px.dep[v]-1,i});
        px.ask[v].push_back({h,i});
    }
    px.dfs_cal(0,-1,0);
    for(int i=0;i<m;i++) cout<<(string)(px.ans[i]?"Yes\n":"No\n");
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