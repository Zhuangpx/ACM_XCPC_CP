/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-06 17:11:51
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-06 17:15:49
 * @FilePath: \apricitye:\桌面\ACM\蓝桥杯\2021省赛B组\杨辉三角形.cpp
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
const int N = 2e5+5;
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
/*  2021省赛B组  杨辉三角形
    以中点C(2*x,x)向左下衍射，定义为直线，显然对于某条直线上的点，一定大于它的左上角所有的点
    某个数n出现在若干条不同直线，显然最低的直线是最先出现的位置
    考虑从下往上枚举直线，二分是直线上否有n
*/
void init(){
}
ll C(ll n,ll m)
{
    ll res=1;
    for(ll i=0;i<m;i++) {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
void PX()
{
    int n;cin>>n;
    if(n==1) {
        cout<<1<<'\n';
        return;
    }
    for(int i=20;i>=1;i--) {
        ll l=2*i, r=n;
        while(l<r) {
            ll mid=(l+r)>>1;
            ll res=C(mid,i);
            if(res>=n) r=mid;
            else l=mid+1;
        }
        if(C(l,i)==n) {
            // cout<<l<<'\n';
            cout<<l*(l+1)/2+i+1<<'\n';
            return;
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
