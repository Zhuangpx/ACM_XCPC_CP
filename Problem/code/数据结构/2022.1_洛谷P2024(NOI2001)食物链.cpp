/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-27 02:22:48
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-27 02:22:48
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数据结构\2022.1_洛谷P2024(NOI2001)食物链.cpp
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
    洛谷 P2024 [NOI2001] 食物链
    种类并查集
    在 洛谷P1525(NOIP2010提高组)关押罪犯 的基础上改成三倍
    [1,3*n]
    <i,j> i,j同类
    <i,j+n> i吃j
    <i,j+2*n> j吃i
*/
void init(){}
struct dsu
{
    vector<ll>f;
    dsu(ll n):f(n) { iota(f.begin(),f.end(),0); }
    ll find(ll x){
        if(x==f[x]) return x;
        else return f[x]=find(f[x]);
    }
    void merge(ll x,ll y){
        x=find(x),y=find(y);
        if(x==y) return ;
        f[x]=y;
    }
    bool check(ll x,ll y){
        return find(x)==find(y);
    }
};

void PX()
{
    ll n,m;cin>>n>>m;
    dsu px(3*n+1);
    ll ans=0;
    while(m--){
        ll op;cin>>op;
        ll x,y;cin>>x>>y;
        if(x>n||y>n){
            ans++;
            continue;
        }
        if(op==1){
            if(px.check(x,y+n)||px.check(x,y+2*n))ans++;
            else px.merge(x,y),px.merge(x+n,y+n),px.merge(x+2*n,y+2*n);
        }
        if(op==2){
            if(px.check(x,y+2*n)||px.check(x,y))ans++;
            else px.merge(x,y+n),px.merge(x+n,y+2*n),px.merge(x+2*n,y);
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