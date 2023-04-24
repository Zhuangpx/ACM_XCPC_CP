/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-25 14:52:06
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-25 14:52:06
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数学\2022.12022牛客寒假算法基础集训营1_I_B站与各唱各的.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-18 13:14:50
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-25 14:50:10
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
const int _mod = 998244353;
const int N = 1e6+7;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}

#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"

void init()
{
    
}

/*
    n个up主，m句歌词，每局歌词同时唱或同时不唱则失败，否则成功，求成功的歌词数量的数学期望
    m句歌词是独立的，因此答案就是m乘以一句歌词成功的期望
    一句歌词的成功期望就是2^n-2/2^n
    答案取模，快速幂求个逆元即可
    最后答案：m*(2^n-2)/2^n
*/


void PX()
{
    ll n,m;cin>>n>>m;
    ll d=mpow(2,n,mod);
    cout<<((m*(d-2)%mod)*(mpow(d,mod-2,mod)))%mod<<'\n';
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