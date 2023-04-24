/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-14 17:52:28
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-14 17:54:06
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_(NOIP2013)积木大赛.cpp
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
    牛客竞赛数据结构专题班前缀和练习题 [NOIP2013]积木大赛 <https://ac.nowcoder.com/acm/contest/19483/I>
    差分
    考虑每次区间修改对于差分数组都是进行一个d[l]+和d[r+1]-
    那么差分数组正数和就是最小值
*/

void init(){
}
void PX()
{
    ll n;cin>>n;
    vector<ll>a(n),b(n);
    ll ans=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(i)b[i]=a[i]-a[i-1];
        else b[i]=a[i];
        if(b[i]>0)ans+=b[i];
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