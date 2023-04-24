/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-27 01:39:30
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-27 01:39:30
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数据结构\2022.1_洛谷P1525(NOIP2010提高组)关押罪犯.cpp
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
    洛谷P1525(NOIP2010提高组)关押罪犯
    种类并查集+贪心
    假设同一宿舍为友好关系，不同宿舍为敌对关系
    考虑[0,n)为朋友关系，[n,2*n)为敌人关系
    对于冲突<x,y> 加上<x,y+n> <y,y+n>即x和y互为敌人关系
    由于只有两个友好集合，那么就产生了敌人的敌人就是朋友这一关系
    对敌人关系排序按冲突大到小排序，考虑每次将最大敌人关系分为一个敌对集合，也就分别位于两个友好集合
    由于只有两个友好集合并且冲突已排序，若当前扫描的两个敌人已在一个友好集合，则为贪心下最大值的最小值
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
struct C
{
    ll a,b,w;
    bool operator< (const C& t) const{
        return w>t.w;
    }
};
void PX()
{
    ll n,m;cin>>n>>m;
    dsu px(2*n+1);
    vector<C>c(m);
    for(auto &i:c)cin>>i.a>>i.b>>i.w;
    sort(c.begin(),c.end());    // 按w从大到小排序
    for(auto i:c){
        if(px.check(i.a,i.b)){  // 贪心最大值最小
            cout<<i.w<<'\n';
            return ;
        }
        px.merge(i.a,i.b+n);
        px.merge(i.b,i.a+n);
    }
    cout<<0<<'\n';  // 无冲突
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