/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-27 17:16:10
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-27 17:16:11
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数据结构\2022.1_洛谷P3958(NOIP2017提高组)奶酪.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

//#pragma GCC optimize(2)
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
    洛谷 P3958 [NOIP2017 提高组] 奶酪
    并查集
*/
void init(){}
ll r,h;
struct dsu
{
    vector<ll>f;
    dsu(ll n):f(n) { iota(f.begin(),f.end(),0); }
    ll find(ll x){
        if(f[x]==x)return x;
        else return f[x]=find(f[x]);
    }
    void merge(ll x,ll y){
        x=find(x),y=find(y);
        if(x==y)return ;
        else f[x]=y;
    }
    bool check(ll x,ll y){
        return find(x)==find(y);
    }
};
struct C{
    ll x,y,z;
};
inline bool next_to(C a,C b)    // a 和 b 是否相切或相交
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)<=4*r*r;
}
void PX()
{
    ll n;cin>>n;
    dsu px(n+2);
    vector<C>c(n);
    cin>>h>>r;
    for(auto &i:c)cin>>i.x>>i.y>>i.z;
    for(ll i=0;i<n;i++){
        if(c[i].z<=r)   px.merge(i,n);   // n表示底部
        if(c[i].z+r>=h) px.merge(i,n+1); // n+1表示顶部
    }
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(next_to(c[i],c[j])) px.merge(i,j);   //  相切或相交合并
        }
    }
    //顶部和底部是否在一个集合
    if(px.check(n,n+1))cout<<"Yes\n";
    else cout<<"No\n";
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