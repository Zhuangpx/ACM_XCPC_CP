/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:50:27
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-19 21:57:45
 * @FilePath: \apricity\j.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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
/*  J. Local Minimum
    求满足x是行和列最小值的x个数
    直接暴力即可
*/
void init(){
}
ll a[1111][1111];
ll  row[1100],col[1100];
void PX()
{
    ll n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)row[i]=inf;
    for(int i=1;i<=m;i++)col[i]=inf;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            row[i]=min(row[i],a[i][j]);
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            col[j]=min(col[j],a[i][j]);
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(a[i][j]==row[i]&&a[i][j]==col[j])ans++;
        }
    }
    cout<<ans<<endl;
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