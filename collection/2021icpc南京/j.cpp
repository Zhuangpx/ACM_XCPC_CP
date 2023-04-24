/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:50:27
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-14 17:39:21
 * @FilePath: \apricity\j.cpp
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
/*  J. Xingqiu’s Joke
    给a,b，每次操作同时+1或-1或/p，其中p为同有的质因子，求a=1/b=1的最少次数
    //===
    令a<b，c=b-a，那么若p|a&&p|b则p|c
    枚举c的质因子p，主要将c加减到p的上下倍数取min，然后/p即可
    能够证明p顺序不影响(不会证明)
*/
void init(){
}
vector<ll>vp;   // c的质因子
ll a,b;
unordered_map<ll,ll>f;
ll Hash(ll a,ll c)
{
    return a*1e9+c;
}
ll dfs(ll a,ll c)
{
    if(a==1)return 0;
    if(c==1)return a-1;
    if(f[Hash(a,c)])return f[Hash(a,c)];
    ll minn=a-1;
    for(auto i:vp){
        if(c%i==0){
            ll res=a%i;
            minn=min({minn,res+1+dfs(a/i,c/i),i-res+1+dfs(a/i+1,c/i)});
        }
    }
    return f[Hash(a,c)]=minn;
}
void PX()
{
    cin>>a>>b;
    if(a>b)swap(a,b);
    ll c=b-a;
    vp.clear();
    for(ll i=2;i*i<=c;i++){
        if(c%i==0){
            vp.push_back(i);while(c%i==0)c/=i;
        }
    }
    if(c>1)vp.push_back(c);
    ll ans=dfs(a,b-a);
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
