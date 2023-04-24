/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-07 10:36:21
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-07 10:36:21
 * @FilePath: \apricitye:\桌面\ACM\蓝桥杯\2021省赛B组\时间显示.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
typedef long long ll;
#define ull unsigned long long
#define UINF ~0ull
#define mod_ 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 1e6+55;
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
/*  2021省赛B组  时间显示
    先除再模
*/
void init(){
}
const ll _S=1000,_M=60*_S,_H=60*_M,_D=24*_H;
void PX()
{
    ll n;cin>>n;
    n%=_D;
    int h=n/_H;n%=_H;
    int m=n/_M;n%=_M;
    int s=n/_S;
    string _h="",_m="",_s="";
    if(h<10) _h="0",_h+=(char)(h+'0'); else _h=(char)((h/10)+'0'),_h+=(char)(h%10+'0');
    if(m<10) _m="0",_m+=(char)(m+'0'); else _m=(char)((m/10)+'0'),_m+=(char)(m%10+'0');
    if(s<10) _s="0",_s+=(char)(s+'0'); else _s=(char)((s/10)+'0'),_s+=(char)(s%10+'0');
    cout<<_h<<":"<<_m<<":"<<_s<<'\n';
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
