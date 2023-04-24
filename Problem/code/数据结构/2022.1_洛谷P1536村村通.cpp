/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-27 00:42:54
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-27 00:44:04
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数据结构\2022.1_洛谷P1536村村通.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

// #pragma GCC optimize(2)
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
const int N = 1e7+7;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}

#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"


/*
*/
void init(){}
ll f[N],n;
ll find(ll x)
{
    if(x==f[x]) return x;
    else return f[x]=find(f[x]);
}
void merge(ll x,ll y)
{
    x=find(x),y=find(y);
    if(x==y) return ;
    else f[x]=y;
}
void PX()
{
    ll m;cin>>m;
    for(ll i=1;i<=n;i++)f[i]=i;
    while(m--){
        ll x,y;cin>>x>>y;
        merge(x,y);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(find(i)==i) ans++;
    }
    cout<<ans-1<<'\n';
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
    while (cin>>n&&n)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}