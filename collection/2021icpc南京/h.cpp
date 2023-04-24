/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:23:01
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-12 09:33:22
 * @FilePath: \apricity\h.cpp
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
const int N = 1e5+111;
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
/*  H. Crystalfly
    cfgym:<https://codeforces.com/gym/103470/problem/H>
    有根树，每个点若干个蝴蝶，初始在1，每次到达某点，相邻点i的蝴蝶会在ti秒后归0(ti=1/2/3)
    要求能抓到的蝴蝶最大值
    //===
    每个子树有三种情况，抓根然后往下f(u)，根空然后往下g(u)，抓根然后折返再往下h(u)
    h[u] = a[u] + sum{g[v]}
    f[u] = g[u] + a[u]
    1:g[u] = f[vi] + sum{g[vj]}
           = sum{g[v]} + max{a[v]} (i!=j)
    2:g[u] = h[vi] + f[vj] + sum{g[vk]} (i!=j!=k)
           = h[vi] + sum{g[vj]} + max{a[j]} (i!=j) & (tj==3)
    容易发现只要存g即可
*/
void init(){
}
ll n;
ll a[N];
ll t[N];
ll s[N],g[N];
vector<ll>e[N];
inline void add(ll u,ll v) { e[u].push_back(v);e[v].push_back(u); }
void dfs(ll u,ll fa)    //  求g
{
    for(auto v:e[u])if(v!=fa)dfs(v,u);
    for(auto v:e[u])if(v!=fa)s[u]+=g[v];    //  s[u]=sum{g[v]}
    ll ma=0,id;
    for(auto v:e[u]){   //1:g[u] : sum{g[v]} + max{a[v]}
        if(v==fa)continue;
        if(t[v]==3&&a[v]>ma)ma=a[v],id=v; //  找最大
        g[u]=max(g[u],s[u]+a[v]);
    }
    if(ma==0)return;   //无v
    //2:g[u] : h[vi] + sum{g[vj]} + max{a[j]} (i!=j) & (tj==3)
    for(auto v:e[u]){   //a[j]=次大
        if(v==fa||v==id||t[v]!=3)continue;
        // h[vi] = a[id] + s[id]
        // sum{g[vj]} = s[u] - g[id]
        // max{a[j]} = max{a[v]}
        g[u]=max(g[u],a[id]+s[id] +s[u]-g[id] + a[v]);
    }
    if(t[id]!=3)return;
    for(auto v:e[u]){   //a[j]=最大
        if(v==fa||v==id)continue;
        // h[vi] = a[v] + s[v]
        // sum{g[vj]} = s[u] - g[v]
        // max{a[j]} = a[id]
        g[u]=max(g[u],a[v]+s[v] + s[u]-g[v] + a[id]);
    }
    return ;
}
void PX()
{
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i],e[i].clear(),s[i]=g[i]=0;
    for(ll i=1;i<=n;i++)cin>>t[i];
    for(ll i=1,u,v;i<n;i++)cin>>u>>v,add(u,v);
    dfs(1,0);
    ll ans=g[1]+a[1]; // f[1] = a[1] + g[1]
    cout<<ans<<'\n';
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
    init();
    cin >> ZPX;
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}


