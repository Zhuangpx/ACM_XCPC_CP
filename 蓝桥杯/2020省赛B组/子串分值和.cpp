/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-07 14:13:15
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-07 14:13:33
 * @FilePath: \apricitye:\桌面\ACM\蓝桥杯\2020省赛B组\子串分值和.cpp
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
const int N = 1e6+55;
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
/*  2020省赛B组  子串分值和
    考虑每种字母分开处理，枚举每个位置([1,n])，考虑它的贡献
    显然如当前位置l，下一个位置r，那么l位置的贡献就是l*(r-l)，如果r不存在需要置为n+1
*/
void init(){
}
const int _N=2020;
vector<int>v[30];
void PX()
{
    string s;cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++) {
        v[s[i]-'a'].push_back(i+1);
    }
    ll ans=0;
    for(int i=0;i<27;i++) {
        if(v[i].empty())continue;
        for(int j=0;j<v[i].size();j++) {
            int l=v[i][j];
            int r=0;
            if(j+1<v[i].size()) r=v[i][j+1];
            else r=n+1;
            ans+=1ll*l*(r-l);
        }
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
