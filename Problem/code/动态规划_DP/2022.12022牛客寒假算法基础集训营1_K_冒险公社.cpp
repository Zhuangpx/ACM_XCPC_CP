/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-25 20:36:30
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-25 20:36:31
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\动态规划_DP\2022.12022牛客寒假算法基础集训营1_K_冒险公社.cpp
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
// #define INF ~0ULL
// #define mod 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 1e6+7;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}

#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"

void init()
{
    
}

/*
    假设0-Green,1-Red,2-Back
    dp一下,dp[i][x][y][z]:考虑到当前第i位，且i-1,i-2,i-3分别为x,y,z时G的最大数量，从后往前扫
    分类讨论进行转移即可，注意初始-1，对n位判断进行初始化。
    考虑到x,y,z都有三种情况，3^3=27，可以压到二维，即dp[i][j]，其中j->[0,26]分别表示27中情况，从前往后扫。
*/
//  0-G 1-R 2-B
ll dp[N][27];
inline ll cnt0(ll x)    // cnt->G
{
    return (x%3==0)+(x/3%3==0)+(x/9%3==0);
}
inline ll cnt2(ll x)    // cnt->R
{
    return (x%3==2)+(x/3%3==2)+(x/9%3==2);
}
inline bool check(char c,ll cnt)    //  不合法check
{
    return (c=='G'&&cnt<=0)||(c=='B'&&cnt!=0)||(c=='R'&&cnt>=0);
}
void PX()
{
    ll n;cin>>n;
    string s;cin>>s;s=" "+s;    // G>R-->G  R>G-->R  R==G-->B
    // memset(dp,-1,sizeof dp);
    for(ll i=0;i<=n+5;i++)for(ll j=0;j<=26;j++)dp[i][j]=-INF;
    for(ll j=0;j<=26;j++){
        char c=s[3];
        ll cnt=cnt0(j)-cnt2(j); //  cnt->G-R
        if(check(c,cnt))    continue;
        dp[3][j]=cnt0(j);
    }
    for(ll i=4;i<=n;i++){   // s[0]=s[1]=X   s[3]->init   DP form s[4]
        for(ll j=0;j<=26;j++){  //  3*3*3=27->[0,26]
            char c=s[i];
            ll cnt=cnt0(j)-cnt2(j); //  cnt->G-R
            if(check(c,cnt))    continue;
            for(ll k=0;k<=26;k++){
                // k= x y z  j= y z x   add->(x%3)
                if(k%3==j/3%3&&k/3%3==j/9%3)dp[i][j]=max(dp[i][j],dp[i-1][k]+(j%3==0));
            }
        }
    }
    // ll ans=-1;
    ll ans=-INF;
    for(ll j=0;j<=26;j++)ans=max(ans,dp[n][j]);
    cout<<(ans<0?-1:ans)<<'\n';
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