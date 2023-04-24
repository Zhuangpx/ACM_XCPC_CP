/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-07 11:34:08
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-07 11:34:08
 * @FilePath: \apricitye:\桌面\ACM\蓝桥杯\2020省赛B组\跑步锻炼.cpp
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
/*  2020省赛B组  跑步锻炼
*/
void init(){
}
const int _N=2020;
int a[22][13];
bool f(int x)
{
    return (x==1)||((x==3))||(x==5)||(x==7)||(x==8)||(x==10)||(x==12);
}
bool g(int x)
{
    x+=2000;
    if(x%4==0&&x%100)return 1;
    if(x%100==0&&x%400==0)return 1;
    return 0;
}
void PX()
{
    int ans=0;
    for(int i=0;i<=20;i++) {
        for(int j=1;j<=12;j++) {
            if(j==2) {
                if(g(i)) a[i][j]=29;
                else a[i][j]=28;
            }
            else if(f(j)){
                a[i][j]=31;
            }
            else a[i][j]=30;
        }
    }
    int cnt=5;
    for(int i=0;i<=20;i++) {
        for(int j=1;j<=12;j++) {
            if(i==20&&j==10) {
                ans+=2;
                cout<<ans<<'\n';
                return;
            }
            for(int k=1;k<=a[i][j];k++) {
                if(!cnt||k==1)ans+=2;
                else ans++;
                cnt++;cnt%=7;
            }
        }
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
