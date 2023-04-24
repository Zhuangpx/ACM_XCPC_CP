/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-12 13:27:57
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-12 13:27:57
 * @FilePath: \apricitye:\桌面\ACM\collection\NamomoSpringCamp2021Div1\Day1\CF1637F.Towers.cpp
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
const int N = 1e6+111;
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
/*  CF1637 F.Towers
    <https://codeforces.com/contest/1637/problem/F>
    n个点的树，每个点有高度h
    考虑在点上建塔，花费e得到e的高度,e>=0
    要求使得对于每个点u存在两个点v，w满足u在v，w路径上且有hu<=min(ev,ew)
    构造出这样的最小e总和
    //====
    考虑最大的hu，那么应该有ev=ew=hu，因此先选出ev和ew
    然后考虑hu的子树，子树上任一个节点都能选上面的v/w作为其中一个，那么在内部再选一个大于等于该点的h即可
    那么叶子节点必须有ei>=hi，再往上，如果父节点大于叶子结点，那么应该把最大的叶子结点的e改成父节点的h
    于是就成了子树最大值问题，ev和ew应该去选择最大子树
*/
void init(){
}
ll n;
ll h[N];
ll f[N];
vector<ll>e[N];
ll id;  // max h[i]
void add(ll u,ll v) { e[u].push_back(v);e[v].push_back(u); }
ll ans;
void dfs(ll u,ll fa)
{
    ll res=0;   // 次大
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        if(f[v]>f[u])res=f[u],f[u]=f[v];
        else res=max(res,f[v]);
    }
    if(fa)ans+=max(h[u]-f[u],0ll);
    else ans+=h[u]*2-f[u]-res;
    f[u]=max(f[u],h[u]);
}
void PX()
{
    cin>>n;id=1;
    for(ll i=1;i<=n;i++)cin>>h[i],id=(h[id]<h[i])?i:id;
    for(ll i=1,u,v;i<n;i++)cin>>u>>v,add(u,v);
    dfs(id,0);
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
