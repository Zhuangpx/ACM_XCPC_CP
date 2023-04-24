/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-14 21:05:02
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-14 21:05:03
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_牛牛的Link_Power_I.cpp
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
const int N = 1e6+7;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline bool _bug(bool _line=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";
    return 1;
#endif
    return 0;
}
#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"

/*
    牛客竞赛数据结构专题班前缀和练习题 牛牛的Link Power I <https://ac.nowcoder.com/acm/contest/19483/G>
    前缀和
    考虑某个1对后续每个位置可能产生的贡献
       x1xxx
    -> x0100 (借助理解)
    -> x0111 (能够产生贡献)
    -> x0123 (每个位置产生的贡献)
    容易发现就是两次前缀和
    每个1都进行两次前缀和即可得到每个位置可能的贡献
    再取考虑每个位置是否能够产生贡献即可
*/

void init(){
}
void PX()
{
    ll n;cin>>n;
    string s;cin>>s;
    vector<ll>a(n+1);
    a[0]=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='1')a[i+1]=1;
    }
    for(ll i=1;i<=n;i++)a[i]=(a[i]+a[i-1])%mod;//vis
    for(ll i=1;i<=n;i++)a[i]=(a[i]+a[i-1])%mod;//add
    ll ans=0;
    for(ll i=1;i<n;i++){
        if(s[i]=='1')ans+=a[i],ans%=mod;
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