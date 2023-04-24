/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-10 01:33:01
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-15 09:25:53
 * @FilePath: \apricitye:\桌面\ACM\collection\2021ccpc桂林\k.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f
typedef long long ll;
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define UINF ~0ull
#define mod_ 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 5e4+111;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll _mpow(ll a,ll b,ll m=_mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline bool _bug(bool _line=0,bool line_=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";if(line_)cout<<'\n';return 1;
#endif
    return 0;
}
#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"
/*  K. Tax
    n个点m条边的无向图，边有公司c[i]，对应w[c[i]]路费，第k次通过c[i]公司路费为k*w[c[i]]
    起点为1，要到达其他点，求满足最短路的最小花费
    //===
    先bfs出最短路，再dfs出最小花费(dis[v]=dis[u]+1时更新花费)
*/
void init(){
}
inline void dfs(ll u,ll cost,const vector<vector<pair<ll,ll>>>& e,vector<ll>& ans,vector<ll>& cnt,const vector<ll>& w,const vector<ll>& dis)
{
    ans[u]=min(ans[u],cost);
    for(auto [_v,_w]:e[u]){
        if(dis[_v]==dis[u]+1){
            ++cnt[_w];
            dfs(_v,cost+cnt[_w]*w[_w],e,ans,cnt,w,dis);
            --cnt[_w];
        }
    }
}
void PX()
{
    ll n,m;cin>>n>>m;
    vector<ll>dis(n,-1);dis[0]=0;
    vector<ll>w(m);for(auto &i:w)cin>>i;
    vector e(n,vector<pair<ll,ll>>());
    // vector<vector<pair<ll,ll>>>e(n,vector<pair<ll,ll>>());
    for(ll i=1;i<=m;i++){
        ll _u,_v,_w;cin>>_u>>_v>>_w;_u--;_v--;_w--;
        e[_u].push_back({_v,_w});e[_v].push_back({_u,_w});
    }
    queue<ll>q;q.push(0);
    while(!q.empty()){
        auto _u=q.front();q.pop();
        for(auto [_v,_w]:e[_u]){
            if(dis[_v]==-1)dis[_v]=dis[_u]+1,q.push(_v);
        }
    }
    vector<ll>ans(n,INF),cnt(m,0);
    dfs(0,0,e,ans,cnt,w,dis);
    for(ll i=1;i<n;i++)cout<<ans[i]<<"\n";
}
int main()
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
