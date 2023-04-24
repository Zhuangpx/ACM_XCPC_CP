/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:57
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-07 16:27:01
 * @FilePath: \apricitye:\桌面\ACM\collection\2021ccpc威海\g.cpp
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
/*  G. Desserts
    a的和sum<=1e5   k对应答案ans[k]=mul{C(a[i],k)}
    本质上a的种类最多sqrt(sum)  相同进行快速幂合并 其他枚举即可
    复杂度是O(m*sqrt(sum)*logn)
*/

ll a[N];
const int _N=1e5+6;
ll jie[_N],tow[_N];
void init()
{
    jie[0]=1;
    for(int i=1;i<_N;i++)jie[i]=jie[i-1]*i%_mod;
    tow[_N-1]=mpow(jie[_N-1],_mod-2,_mod);
    for(int i=_N-2;i>=0;i--) tow[i]=tow[i+1]*(i+1)%_mod;
}
ll cal(ll n,ll m){if(m>n) return 0; return jie[n]*tow[m]%_mod*tow[n-m]%_mod; }
void PX()
{
    ll n,m;cin>>n>>m;
    init();
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    for(int i=1;i<=m;i++){
        if(i<a[n-1]){   //  无方案
            cout<<0<<'\n';
            continue;
        }
        else{
            ll ans=1;
            for(auto x:mp){
                ans=ans*mpow(cal(i,x.first),x.second)%mod;
            }
            cout<<ans<<'\n';
        }

    }
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


