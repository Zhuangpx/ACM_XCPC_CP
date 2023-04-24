/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:31
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-14 12:27:58
 * @FilePath: \apricity\c.cpp
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
/*   C. Klee in Solitary Confinement
    给定数组a[n]和k，考虑将区间[l,r]+=k，求最大众数次数
    //===
    枚举众数x，那么主要考虑x和x-k的数量
    设s[i][0]表示前i的数里x的个数，s[i][1]表示x-k的个数，那么[l,r]的贡献就是:
        s[n][0] - (s[r][0]-s[l-1][0]) + (s[r][1]-s[l-1][1])
    即  s[n][0] - (s[r][1]-s[r][0]) + (s[l-1][0]-s[l-1][1])
    那么只要线性枚举，维护最大的(s[l-1][0]-s[l-1][1])，再用当前i作为r维护最大ans即可
*/
void init(){
}
const int _N=2e6;    // 偏移量，离散化区间[0,4e6]
int s[N][2];
int a[N];
vector<int>v[N*4+5];   // [0,4e6]
void PX()
{
    int n,k;cin>>n>>k;
    int ans=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];a[i]+=_N;
        v[a[i]].push_back(a[i]);
        v[a[i]+k].push_back(a[i]);
        // v[x] 存 x-k 和 x
        ans=max(ans,max((int)v[a[i]].size(),(int)v[a[i]+k].size()));
    }
    if(k==0){ cout<<ans/2<<'\n';return; }
    ans=0;
    for(int i=0;i<=4e6;i++){
        int now=v[i].size();
        if(now==0)continue;
        for(int j=0;j<now;j++){
            s[j+1][0]=s[j][0]+(v[i][j]==i);
            s[j+1][1]=s[j][1]+(v[i][j]!=i);
        }
            if(_bug(1,1))cout<<i<<'\n';
            if(_bug(1,1))for(ll j=0;j<=now;j++)cout<<s[j][0]<<' '<<s[j][1]<<'\n';
        ans=max(ans,s[now][0]);
        int maxn=0;
        for(int j=1;j<=now;j++){
            maxn=max(maxn,s[j-1][0]-s[j-1][1]);
                if(_bug(1))cout<<j<<' '<<maxn<<' '<<s[now][0] +(s[j][1]-s[j][0]) +maxn<<'\n';
            ans=max(ans,s[now][0] +(s[j][1]-s[j][0]) +maxn );
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
