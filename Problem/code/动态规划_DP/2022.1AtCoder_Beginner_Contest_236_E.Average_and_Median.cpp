/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-18 13:14:50
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-23 19:20:18
 * @FilePath: \apricity\Zhuangpx.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

//  二分+DP

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
const int N = 1e6+7;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}

#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"

void init()
{
    
}
ll n;
long double dp[N][2];
long double a[N];
vector<long double>v_check;
void init_check()
{
    v_check.clear();
    memset(dp,0,sizeof dp);
}
// check最大值是否大于0
bool check()
{
    //  dp[x][0]:[1,x]区间不选v[x]的最大值
    //  dp[x][1]:[1,x]区间选v[x]的最大值
    //  相邻必须有一个选
    dp[0][1]=v_check[0];
    for(ll i=1;i<n;i++){
        dp[i][0]=dp[i-1][1];//不选
        dp[i][1]=max(dp[i-1][0],dp[i-1][1])+v_check[i];//选
    }
    long double res=max(dp[n-1][0],dp[n-1][1]);
    return res>0;
}
void PX()
{
    cin>>n;
    long double maxn=0,minn=0,l=0,r=0;
    for(ll i=0;i<n;i++){
        ll d;cin>>d;
        a[i]=d;
        maxn=max(maxn,(long double)1.0*a[i]);
    }
    l=minn,r=maxn;
    while(r-l>eps){
        // 二分平均数 取a[i]-mid作为有效值check 当最大值大于0说明存在方案
        long double mid=(r+l)/2;
        init_check();
        for(ll i=0;i<n;i++){
            v_check.push_back(a[i]-mid);
        }
        if(check()) l=mid;
        else r=mid;
    }
    cout<<(l+r)/2<<'\n';    // 最大平均值
    ll _l=minn,_r=maxn;
    while(_r-_l>=0){
        //  二分中位数  取{a[i]是否大于等于mid->1/-1}作为有效值check  当最大值大于0说明存在方案
        ll mid=(_l+_r)/2;
        init_check();
        for(ll i=0;i<n;i++){
            v_check.push_back(a[i]>=mid?1:-1);
        }
        if(check()) _l=mid+1;
        else _r=mid-1;
    }
    cout<<_r<<'\n';     //最大中位数
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