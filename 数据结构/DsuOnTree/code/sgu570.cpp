/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-24 19:40:28
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-05-23 19:55:35
 * @FilePath: \apricitye:\桌面\ACM\数据结构\DsuOnTree\code\sgu570.cpp
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
/*  SGU - 507:<https://vjudge.net/problem/SGU-507>(vj)
    Dsu On Tree + map
    有根数n个点m个叶子结点，其中[n-m+1,n]为叶子结点，每个叶子节点有权值a[i]
    求每个非叶子结点v的子树中，不同的叶子节点权值差的绝对值的最小值
    启发式合并，维护map[i,j]:权值i出现次数j
        若map[i]>1，显然ans==0
        若map[i]==1，需要去找map里<i的第一个数L和>i的第一个数R，那么ans=min(i-L,R-i)
*/
void init(){}
struct DsuOnTree {
#define MAX 50055
    int n, rot;
    int dep[MAX], sz[MAX], bson[MAX];
    vector<int> e[MAX];
    // ==   Infor
#define MAX_ANS INT_MAX
    int m;
    int a[MAX];     //  val
    int ans[MAX];
    int res=MAX_ANS;
    map<int,int> mp;
    // ==
    inline void dfs_sz(int u,int fa) {
        sz[u]=1;
        if(u==rot) dep[u]=1;
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
        if(val==-1) {mp.clear(), res=MAX_ANS;return ;}
        if(u>=n-m+1) {
            mp[a[u]]++;
            if(mp[a[u]]==1) {   //  res = min(a[u]-l, r-a[u])
                auto lt=mp.find(a[u]);
                auto rt=lt;
                if(lt!=mp.begin()) lt--, res=min(res,abs(a[u]-(*lt).first));
                auto last=mp.end();
                last--;
                if(rt!=last) rt++, res=min(res,abs(a[u]-(*rt).first));
            }
            else res=0;     //  res = a[u]-a[u]==0
        }
        for(auto v:e[u]) {
            if(v==fa||v==Bson) continue;
            update(v,u,Bson,val);
        }
    }
    inline void re_update(int u,int fa) {
        update(u,fa,-1,-1);
    }
    inline void dfs_cal(int u,int fa,bool keep) {
        for(auto v:e[u]) {
            if(v==fa||v==bson[u]) continue;
            dfs_cal(v,u,0);
        }
        if(bson[u]!=-1) dfs_cal(bson[u],u,1);
        update(u,fa,bson[u],1); //  cal
        // == GetAns
        ans[u]=res;
        //
        if(!keep) re_update(u,fa);   //  re cal
    }
};
DsuOnTree px;
void PX()
{
    int n,m;
    cin>>n>>m;
    px.n=n, px.rot=1, px.m=m;
    for(int i=2;i<=n;i++) {
        int d;cin>>d;
        px.e[d].push_back(i);
        // px.e[i].push_back(d);
    }
    for(int i=n-m+1;i<=n;i++) cin>>px.a[i];
    px.dfs_sz(1,-1);
    px.dfs_cal(1,-1,0);
    for(int i=1;i<=n-m;i++) cout<<px.ans[i]<<" \n"[i==n-m];
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