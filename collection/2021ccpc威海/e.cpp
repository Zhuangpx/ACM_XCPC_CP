/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:49
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-07 14:05:25
 * @FilePath: \apricity\e.cpp
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
/*  E. CHASE!
    n个数随机选两个，并且有k次重选机会 求和的最大期望
    以及当前选了x和y并且有c次重选机会  判断是否重选
    用dp[k]表示进行k次重选的期望
    首先考虑k=0时的期望，dp[0] = 2*(n-2)*sum / (n*(n-1))   (考虑方案数和每次方案的和)
    此外考虑i>=1，当前dp[i]从dp[i-1]下重选和不重选转移来
        重选后>dp[i-1] 则进行重选 并记下总和
        重选后<=dp[i-1] 不需重选 贡献应该是dp[i-1] 并记下方案数 贡献和就是方案数*dp[i-1]
        两种情况方案和 / 方案数 = 当前最大期望
*/
void init(){
}
#define double long double
void PX()
{
    ll n,k,q;cin>>n>>k>>q;
    vector<ll>a(n+1,0),b(n+1,0),sum(n+2,0);
    ll s=0;
    for(ll i=1;i<=n;i++)cin>>a[i],b[i]=a[i],s+=a[i];
    sort(a.begin()+1,a.end());  // 小到大
    for(ll i=n;i>=1;i--)sum[i]=sum[i+1]+a[i];   //  后缀和
        if(_bug(1,1))for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
        if(_bug(1,1))for(int i=1;i<=n;i++)cout<<b[i]<<" \n"[i==n];
        if(_bug(1,1))for(int i=1;i<=n;i++)cout<<sum[i]<<" \n"[i==n];
    vector<double>dp(k+2);
    // ll C=n*(n-1);   //选两个的方案数
    dp[0]=(double)2*(n-1)*s/(n*(n-1));  // init k==0
    for(ll i=1;i<=k;i++){
        ll l=1,r=n;     //  选两个分别为a[l],a[r]
        ll s1=0,s2=0;   //  s1为>dp[i-1]部分的和 s2为重选与不重选的方案数
        while(r>=1&&l<=n){  //  定r判l
            //  选a[r] 再找出满足a[l]+a[r]>d[i-1]的最小a[l] 那么[l,r-1]任意一个都满足
            while(l<=n&&a[l]+a[r]<=dp[i-1])l++;
            if(l>n)break;
            if(l<=r){
                //  a[l,n] + a[r] 且 l<=r<=n [l,r]每个与a[r]配对 再减去a[r]-a[r]本身配对 而sum[l]是[l,r]的和
                //  因此贡献是sum[l,n]+len[l,n]*a[r]-cnt*a[r]  而cnt=2 即重复计算的部分
                s1+=sum[l]+(n-l+1)*a[r]-2*a[r];s2+=n-l; //  此时方案是len[l,n]-len[r]
            }
            else {
                //  a[r,n] + a[l] 且 r<l<=n [l,r]每个与a[r]配对
                //  因此贡献是sum[l,n]+len[l,n]*a[r]
                s1+=sum[l]+(n-l+1)*a[r];s2+=n-l+1;  //  此时方案是len[l,n]
            }
            r--;
        }
        s2=n*(n-1)-s2;  // 重选+不重选=方案数
        // 重选后>dp[i-1] 则进行重选 并记下总和
        // 重选后<=dp[i-1] 不需重选 贡献应该是dp[i-1] 并记下方案数 贡献和就是方案数*dp[i-1]
        // 两种情况方案和 / 方案数 = 当前最大期望
        dp[i]=(double)s1/(n*(n-1))+(double)(s2*dp[i-1])/(n*(n-1));
    }
        if(_bug(1,1))for(ll i=0;i<=k;i++)cout<<dp[i]<<" \n"[i==k];
    cout<<fixed<<setprecision(10)<<dp[k]<<'\n';
    while(q--){
        ll x,y,c;cin>>x>>y>>c;
        if(c==0){   //  无重选机会 必然accept
            cout<<"accept\n";continue;
        }
        c--;    //  注意应该跟dp[c-1]比较
        if(b[x]+b[y]>dp[c])cout<<"accept\n";    // 大于期望
        else if(fabs(b[x]+b[y]-dp[c])<=1e-4)cout<<"both\n"; // 约等于期望
        else cout<<"reselect\n";    //  小于期望
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
