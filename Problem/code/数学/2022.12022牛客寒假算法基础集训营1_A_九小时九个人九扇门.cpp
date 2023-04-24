/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-25 14:27:39
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-25 14:27:39
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.12022牛客寒假算法基础集训营1_A_九小时九个人九扇门.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-18 13:14:50
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-25 14:22:11
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
    九余数定理(同余定理):一个数的数字根等于它对9取余得到的余数，特别地，余数为0则数字根为9
    因此有：
    1.f(f(a)+f(b))=f(a+b)
    2.f(f(a)*f(b))=f(a*b)
    3.f(f(a)^n)=f(a^n)
    问题转化为{a[1~n]}选若干个数使得其和摸9得到0,1,2,3,4,5,6,7,8有多少种取法，每个数只能取一个。
    经典01背包问题。
    转移方程dp[i][j]:考虑前i个数模9得j的方案数
    注意最后的dp[n][0]应该是比答案多1
*/

ll dp[N][10];

void PX()
{
    ll n;cin>>n;
    // vector<vector<ll>>dp(10,vector<ll>(n+1,0));
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        ll d;cin>>d;d%=9;
        for(ll j=0;j<9;j++){
            dp[i][(j+d)%9] = (dp[i][(j+d)%9] +dp[i-1][j] )%_mod;
            dp[i][j] = (dp[i][j] + dp[i-1][j])%_mod;
        }
    }
    for(ll i=0;i<9;i++)cout<<(i==8ll?dp[n][(i+1)%9]-1:dp[n][(i+1)%9])<<' ';
    cout<<'\n';
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