/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-07 16:03:24
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-07 16:51:30
 * @FilePath: \apricity\m.cpp
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
/*  M. 810975
    n个数有m个1且连续最长1数量为k
    考虑这样一个问题 m个数 大小[0,n-1] 总和k 的方案数 一个经典组合问题
    变成了n-m+1个数，大小[0,k]且最大恰好为k 总和为m
    然后上容斥 [0,k]-[0,k-1]==[k,k] 先求恰好k个再减去恰好k-1个
*/

const int _N=1e6+6;
ll jie[_N],tow[_N];
void init()
{
    jie[0]=1;
    for(int i=1;i<_N;i++)jie[i]=jie[i-1]*i%_mod;
    tow[_N-1]=mpow(jie[_N-1],_mod-2,_mod);
    for(int i=_N-2;i>=0;i--) tow[i]=tow[i+1]*(i+1)%_mod;
}
ll cal(ll n,ll m){if(m>n) return 0; return jie[n]*tow[m]%_mod*tow[n-m]%_mod; }
ll _cal(ll m,ll n,ll k)     // m个数 大小在[0,n-1] 总和k 的方案数 (若n-1恰好选一个则要容斥*t)
{
    ll res=0;
    for(ll i=0,t=1;i<=m&&i*n<=k;i++,t=-t){   //  i个大小>=n
        // res+=t*(x*y)%_mod;res%=mod;
        res+=t*(cal(m,i)*cal(k-i*n+m-1,m-1))%_mod;res%=_mod;
    }
    return res%_mod;
}
void PX()
{
    init();
    ll n,m,k;cin>>n>>m>>k;
        if(_bug(1,1))cout<<_cal(n-m+1,k+1,m)<<'\n';
        if(_bug(1,1))cout<<_cal(n-m+1,k,m)<<'\n';
    cout<<(_cal(n-m+1,k+1,m)-_cal(n-m+1,k,m)+_mod)%_mod<<'\n';
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
    //cin >> ZPX;
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}


