/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-06 09:49:31
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-06 17:15:56
 * @FilePath: \apricitye:\桌面\ACM\蓝桥杯\2021省赛B组\直线.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */


#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
typedef long long ll;
#define ull unsigned long long
#define UINF ~0ull
#define mod_ 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 2e5+5;
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
/*  2021省赛B组  直线
    枚举端点，以y=k*x+b形式计算k和b
    排序去重，最终答案是40257
*/
void init(){
}
const int _N=20,_M=21;
const double DINF = 100;
inline bool eql(double a,double b) { return abs(a-b)<=eps; }
void PX()
{
    vector<pair<double,double>>v;
    int ans=0;
    for(int x1=0;x1<_N;x1++)for(int y1=0;y1<_M;y1++)
    for(int x2=0;x2<_N;x2++)for(int y2=0;y2<_M;y2++)
    {
        double k,b;
        if(x1==x2&&y1==y2) continue;
        if(x1==x2) k=DINF,b=x2;
        else k=(1.0*y1-1.0*y2)/(1.0*x1-1.0*x2),b=1.0*y1-k*x1;
        v.push_back({k,b});
    }
    sort(v.begin(),v.end());
    int len=v.size();
    for(int i=0;i<len;i++) {
        if(i==0) ans++;
        else if(!eql(v[i].first,v[i-1].first)||!eql(v[i].second,v[i-1].second)) ans++;
    }
    cout<<ans<<'\n';
}
signed main()
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
