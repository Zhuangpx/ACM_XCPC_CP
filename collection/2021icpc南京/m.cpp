/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-07 16:03:24
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-10 14:35:21
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
/*  M.  Windblume Festival
    本质上就是构造系数1/-1使得和最大，但第一个系数必须是1，第二个必须是-1
    那么考虑max做第一个，min做第二个，其它可以构造出绝对值贡献
*/
void init(){
}
void PX()
{
    ll n;cin>>n;
    ll s=0;
    vector<ll>a(n);
    for(auto &i:a)cin>>i;sort(a.begin(),a.end());
    if(n==1){cout<<a[0]<<'\n';return;}
    if(n==2){cout<<a[1]-a[0]<<'\n';return;}
    for(int i=1;i<n-1;i++)s+=abs(a[i]);
    s+=a[n-1];s-=a[0];
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
    cin >> ZPX;
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}


