/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:23:01
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-07 18:36:35
 * @FilePath: \apricity\h.cpp
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
const int mod = 998244353;
const int _mod = 1;
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
/*  F. Stone
    n堆石子每堆a[i]个 轮流选若干堆取出s[i]个且s[i]为s[i-1]的因数 最后取的获胜 求先手第一次取且获胜的方案数
    考虑如果存在奇数堆 那么先手可以取奇数个 变成偶数堆 后手也只能取奇数个 那么取的次数是奇数 先手必胜 方案数是最小奇数/2+1
    如果全是偶数堆 那么就必须取偶数个 直到存在奇数堆 等价于所有的/2
*/
void init(){
}
void PX()
{
    ll n;cin>>n;
    vector<ll>a(n);
    bool ok=1;
    ll minn=INF;
    for(auto &i:a){
        cin>>i;
        if(i%2==1)ok=0,minn=min(minn,i);
    }
    while(ok)for(auto &i:a)if((i=i/2)%2==1)ok=0,minn=min(minn,i);
    cout<<(minn+1)/2<<'\n';
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
    init();
    //cin >> ZPX;
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}


