/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-10 01:33:01
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-10 01:57:57
 * @FilePath: \apricity\k.cpp
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
/*  K. Circle of Life
    构造一个长度为 n 的 01 串，每一次变换的规则如下：
    第 i 位如果为 1，那么变换后第 i+1 和第 i−1 位为 1。最左边和最右边的溢出不需要管。
    如果i 和i+2 位都为 1，那么这两个 1 会在 i+1 发生冲撞抵消，第 i+1 位变换后为 0。
    如果 i 和 i+1 位都为 1，那么变换后 i 和 i+1 位也为 0。
    要求变换前与变换后，串内必须有 1，并且你需要保证构造出的串，可以在 2n 次变换内，出现两个完全相同的串。
    //====
    打表找规律
    发现1001->0110->1001可循环，10001->01010->10001也可循环，
    且由于两头都是1，可拼接
    并且在末尾接上10也合法，或者在开头加上01
    利用这三个即可解决n>=4的构造
    至于n=3，可以特判出无解
*/
void init(){
}
void PX()
{
    string a="1001",b="10001",c="10";
    int n;cin>>n;
    if(n==3){cout<<"Unlucky\n";return ;}
    if(n==2){cout<<"10\n";return ;}
    if(n%4==0){int cnt=n/4;for(int i=1;i<=cnt;i++)cout<<a;cout<<'\n';return ;}
    // if(n%5==0){int cnt=n/5;for(int i=1;i<=cnt;i++)cout<<b;cout<<'\n';return ;}
    int x=n%4,xx=n/4;
    string s="";
    if(x==1){for(int i=1;i<xx;i++)s+=a;s+=b;}
    if(x==2){for(int i=1;i<=xx;i++)s+=a;s+=c;}
    if(x==3){for(int i=1;i<xx;i++)s+=a;s+=b;s+=c;}
    cout<<s<<'\n';
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
