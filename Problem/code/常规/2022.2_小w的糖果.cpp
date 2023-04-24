/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-14 21:42:52
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-14 21:42:52
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_小w的糖果.cpp
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
    牛客竞赛数据结构专题班前缀和练习题 小w的糖果 <https://ac.nowcoder.com/acm/contest/19483/H>
    前缀和(多项式)
    考虑如下:
    a:0 0 0 0  0  0  0
    a:0 1 1 1  1  1  1
    a:0 1 2 3  4  5  6
    a:0 1 4 9 16 25 36
    //====
    d:0 0 0 0 0 0 0
    d:0 1 0 0 0 0 0
    d:0 1 1 1 1 1 1 -> dd:0 1 0 0 0 0 0
    d:0 1 3 5 7 9 11-> dd:0 1 2 2 2 2 2 -> ddd:0 1 1 0 0 0 0
    于是可以分别做出若干次的差分与对应次数前缀和还原
    可以拓展到更一般化即多项式
*/

void init(){
}
void PX()
{
    ll n;cin>>n;
    ll m;cin>>m;
    vector<ll>a(n+1,0);
    vector<vector<ll>>d(3,vector<ll>(n+1,0));
    while(m--){
        ll op,pos;cin>>op>>pos;
        d[op-1][pos]++;
        if(op==3&&pos+1<=n)d[op-1][pos+1]++;
    }
    for(int i=0;i<3;i++){
        if(_bug(1))for(auto k:d[i])cout<<k<<' ';
        if(_bug(0))cout<<'\n';
    }
    for(ll i=0;i<3;i++){
        for(ll j=0;j<i+1;j++){
            for(ll k=1;k<=n;k++)d[i][k]=(d[i][k]+d[i][k-1])%mod;
        }
    }
    for(ll i=1;i<=n;i++)cout<<(d[0][i]+d[1][i]+d[2][i])%mod<<' ';
    cout<<'\n';
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
    cin >> ZPX;
    init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}