/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-18 13:14:50
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-23 19:20:18
 * @FilePath: \apricity\Zhuangpx.cpp
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
// #define INF ~0ULL
// #define mod 99993
const int mod = 1e9+7;
const int N = 5e6+7;

ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}

#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"

void init()
{
    
}
ll n;
ll a[22][22];
ll ans=0;
// map<ll,bool>mp;
bool mp[22];
pair<ll,ll> q[22];
ll cnt=0;
void dfs()
{
    bool ok=0;
    for(ll i=1;i<=2*n;i++){
        if(!mp[i]){
            ok=1;
            for(ll j=i+1;j<=2*n;j++){
                if(!mp[j]){
                    mp[i]=mp[j]=1;
                    cnt^=a[i][j];
                    dfs();
                    cnt^=a[i][j];
                    mp[i]=mp[j]=0;
                }
            }
            break;
        }
    }
    if(!ok)ans=max(ans,cnt);
}
void PX()
{
    cin>>n;
    for(ll i=1;i<=n*2-1;i++){
        for(ll j=i+1;j<=2*n;j++){
            cin>>a[i][j];
        }
    }
    // for(ll i=1;i<=n*2;i++){
    //     for(ll j=1;j<=n*2;j++)cout<<a[i][j]<<' ';
    //     cout<<'\n';
    // }
    // cout<<'\n';
    dfs();
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