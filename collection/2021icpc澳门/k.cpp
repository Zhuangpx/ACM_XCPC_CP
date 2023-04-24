/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-05 17:45:53
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-05 17:45:54
 * @FilePath: \apricitye:\桌面\ACM\collection\2021icpc澳门\k.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */


#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int ll
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
/*  K. Link-Cut Tree
    显然2^n>sum{2^i,i<n}，按顺序加边第一次出现环即可
    并查集维护连通块，当新边的端点在一个连通块即成环，dfs找出环
*/
void init(){
}
vector<pair<int,int>>e[N];
int f[N];
int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
int ans[N],cnt;
int res,fg;
int flag;
int len;
void dfs(int u,int fa)
{
    if(flag)return;
    for(auto [x,i]:e[u])
    {
        if(x==fa)continue;
        if(x==res)
        {
            ++cnt;
            ans[cnt]=fg;
            ++cnt;
            ans[cnt]=i;
            flag=1;
            len=cnt;
            return;
        }
        if(flag)return;
        ++cnt;
        ans[cnt]=i;
        dfs(x,u);
        --cnt;
    }
}
void PX()
{
    int n,m;
    cin>>n>>m;
    cnt=0;fg=0;flag=0;
    for(int i=1;i<=n;i++)e[i].clear(),f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(flag)continue;
        if(find(u)==find(v))
        {
            fg=i;
            res=v;
            dfs(u,-1);
        }
        else{
            e[u].push_back({v,i}),e[v].push_back({u,i});
            int fx=find(u),fy=find(v);
            f[fx]=fy;
        }
    }
    if(!flag){cout<<-1<<endl;return;}
    sort(ans+1,ans+1+len);
    for(int i=1;i<=len;i++){
        cout<<ans[i]<<" \n"[i==len];
    }
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
    cin >> ZPX;
    init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}
