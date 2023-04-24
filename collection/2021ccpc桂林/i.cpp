/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:23:06
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-14 18:39:23
 * @FilePath: \apricity\i.cpp
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
/*  I. PTSD
    a[i]=i
    s[i]=1->PTSD
    分组让upset的人最多，某个PTSD在组内排第二即是upset的
    //===
    考虑从后往前枚举存下可作为组内最大的数个数cnt，当前PTSD且cnt>0则从cnt-1并让贡献加1，否则让cnt+1
*/
void init(){}
void PX()
{
    ll n;cin>>n;
    string s;cin>>s;
    ll ans=0;
    ll cnt=0;
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='0')cnt++;
        else if(s[i]=='1'){
            if(cnt==0)cnt++;
            else ans+=i+1,cnt--;
        }
    }
    cout<<ans<<'\n';
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

