/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-25 15:22:23
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-25 15:22:23
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数学\2022.12022牛客寒假算法基础集训营1_D_牛牛做数论.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-18 13:14:50
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-25 15:19:50
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
    欧拉函数f(x)=x*ς(1-1/p[i]) （累乘）
    定义h(x)=f(x)/x  给n求[2,n]最小和最大的h(x)对应的x
    最小：考虑h(x)=f(x)/x=ς(1-1/p[i]) ，显然乘的p越多越小，因此所有质数乘上不超过n即可
    最大：考虑对于质数h(p)=f(p)/p=(p-1)/p，显然这是最大的，因此找到n以内最大的质数p即可
    因此最后结论如下
    最小：前若干个质数的积中不超过n的最大者
    最大：[2,n]中最大的质数
    由于n只有1e9，只要筛出前几十个质数它们的积就能轻松超过1e9，对于1e9以内的质数，最大的两个间隔282，因此最多判断282个数
    注意n=1无解
*/
ll pri[20]={0,2,3,5,7,11,13,17,19,23,29,31,37,41};
bool ispri(ll x)
{
    if(x<=3)return 1;
    for(ll i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}

void PX()
{
    ll n;cin>>n;
    if(n==1){
        cout<<-1<<'\n';
        return ;
    }
    ll ans=1;
    ll cnt=1;
    while(ans*pri[cnt]<=n)ans*=pri[cnt],cnt++;
    while(!ispri(n))n--;
    cout<<ans<<' '<<n<<'\n';
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