/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:23:06
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-14 16:08:25
 * @FilePath: \apricity\i.cpp
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
/*  I. Cloud Retainer’s Game
    如果无挡板，向下部分就是(x+y)%(2H)=k，向上(2H-y+x)%(2H)=k
    设f[k]，碰到金币f[k1]++,f[k2]++(前提是存在)
    碰到挡板，f[k1]=f[k2]=max(f[k1],f[k2])
*/
void init(){}
struct C{
    ll x,y,p;
    bool operator < (const C& c) const { return this->x<c.x; }
}a[N];
void PX()
{
    ll H,n;cin>>H>>n;
    for(ll i=1;i<=n;i++)cin>>a[i].x>>a[i].y,a[i].p=1;
    ll m;cin>>m;
    for(ll i=1;i<=m;i++)cin>>a[n+i].x>>a[n+i].y,a[n+i].p=2;
    sort(a+1,a+1+n+m);
    unordered_map<ll,ll>f;f[0]=1;
    const ll M=2*H;
    ll ans=1;
    for(ll i=1;i<=n+m;i++){
        ll k1=(a[i].x+a[i].y)%M,k2=(M-a[i].y+a[i].x)%M;
        if(a[i].p==1)f[k1]=f[k2]=max(f[k1],f[k2]);
        else {
            if(f[k1])f[k1]++;   if(f[k2])f[k2]++;
        }
        ans=max({ans,f[k1],f[k2]});
    }
    cout<<ans-1<<'\n';
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
