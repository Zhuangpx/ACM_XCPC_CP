/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-21 12:17:22
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-21 12:17:22
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\动态规划_DP\2022.3_AtCoder_Beginner_Contest_244_E.KingBombee.cpp
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
const int N = 5e4+111;
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
/*  ACB244 E - King Bombee
    无向简单图，s到t，经过k个点且经过点x的次数为偶数的方案数
    数据2000
    dp[i][j][k]:经过i个点(除了起点)，当前点j，x奇偶为k
    枚举i，暴力枚举边u-v进行转移
*/
void init(){
}
ll ans;
ll n,m,k,s,t,x;
ll dp[2222][2222][2];
void PX()
{
    cin>>n>>m>>k>>s>>t>>x;s--,x--,t--;
    vector<pair<ll,ll>>e(m);
    for(auto &[i,j]:e)cin>>i>>j,i--,j--;
    dp[0][s][0]=1;
    for(ll i=0;i<k;i++){    // 走了k步
        for(auto [v,u]:e){  // 枚举边 v-u
            for(auto p:{0ll,1ll}){  // 枚举x的奇偶
                dp[i+1][v][p^(v==x)]+=dp[i][u][p];dp[i+1][v][p^(v==x)]%=_mod;
                dp[i+1][u][p^(u==x)]+=dp[i][v][p];dp[i+1][u][p^(u==x)]%=_mod;
            }
        }
    }
    cout<<dp[k][t][0]%_mod<<'\n';
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