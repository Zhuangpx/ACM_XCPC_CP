/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:27
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-19 22:01:34
 * @FilePath: \apricity\b.cpp
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
/*  B. Magical Subsequence
    找出最长子序列满足两两组合的和相等
    枚举两两的和，贪心组合
    注意记录just为上一次选的，那么后续选的需在just后面
*/
void init(){
}
int a[N];
unordered_map<int,int>cnt;
void PX()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    int maxn=0;
    int just=0;
    for(int i=2;i<=200;i++){
        ans=0;
        cnt.clear();
        just=0;
        for(int j=1;j<=n;j++){
            if(cnt[max(0,i-a[j])]>just){
                ans+=2;
                just=j;
            }
            else {
                cnt[a[j]]=j;
            }
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn<<'\n';
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
