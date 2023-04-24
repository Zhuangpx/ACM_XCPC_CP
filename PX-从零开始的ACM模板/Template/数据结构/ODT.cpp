/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-24 19:40:28
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-08-04 11:21:18
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数据结构\ODT.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
typedef long long ll;
typedef unsigned long long ull;
#define UINF ~0ull
#define mod_ 99993
#define vii vector<int>
#define vvii vector<vector<int>>
#define vll vector<ll>
#define fi first
#define se second
const int mod = 1e9+7;
// const int mod = 998244353;
const int N = 1e6+55;
const long double eps=1e-6;
const long double PI=acos(-1.0);
ll mpow(ll a,ll b,ll m){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
#define pdec(t,ans) cout<<std::fixed<<std::setprecision(t)<<(ans)
inline bool _bug(bool _line=0,bool line_=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";if(line_)cout<<'\n';return 1;
#endif
    return 0;
}
/*
*/
// bool multest = 1;
bool multest = 0;
void _Init(){
}
struct node
{
    int l, r;
    mutable int v; // !mutable
    node(int l, int r, int v) : l(l), r(r), v(v) {} // 构造函数
    bool operator<(const node &o) const { return l < o.l; } // 重载小于运算符
};
set<node> odt;
auto split(int pos) //  节点pos
{
    auto it = odt.lower_bound(node(pos, 0, 0)); // 寻找左端点大于等于pos的第一个节点
    if (it != odt.end() && it->l == pos) // 如果已经存在以pos为左端点的节点，直接返回
        return it;
    it--; // 否则往前数一个节点
    int l = it->l, r = it->r, v = it->v;
    odt.erase(it); // 删除该节点
    odt.insert(node(l, pos - 1, v)); // 插入<l,pos-1,v>和<pos,r,v>
    return odt.insert(node(pos, r, v)).first; // 返回以pos开头的那个节点的迭代器
                                               // insert默认返回值是一个pair，第一个成员是我们要的
}

void odt_assign(ll l, ll r, ll v)
{
    auto end = split(r + 1), begin = split(l); // !顺序必须是r先l后
    odt.erase(begin, end); // 清除一系列节点
    odt.insert(node(l, r, v)); // 插入新的节点
}
void odt_add(ll l, ll r, ll v) {
    auto odt = split(l), end = split(r + 1);  //  [l,r)
    for (auto it = odt; it != end; ++it) {
        it->v += v;
    }
}
ll odt_kth_big(ll l, ll r, ll k) {
    auto begin = split(l), end = split(r + 1);  //  [l,r)
    vector<pair<ll, ll>> v;   //  <val,len>
    for (auto it = begin; it != end; ++it) {
        v.push_back({ it->v,it->r - it->l + 1 });
    }
    sort(v.begin(), v.end());   // !default:upper
    ll s = 0;
    for (ll i = 0; i < v.size(); ++i) {
        s += v[i].second;
        if (s >= k) {
            return v[i].first;  //  kth
        }
    }
    return 0;
}
ll odt_sum_powmod(ll l, ll r, ll x, ll y)
{
    auto begin = split(l), end = split(r + 1);  //  [l,r)
    ll res = 0;
    for(auto it = begin; it != end; ++it) {
        res += (it->r - it->l + 1) * mpow(it->v, x, y) %y;
        res %= y;
    }
    return res;
}
ll n, m, seed, vmax;
ll a[N];
ll rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}
int PX()
{
    cin >> n >> m >> seed >> vmax;
    for(ll i=1;i<=n;i++) {
        a[i] = rnd()%vmax + 1;
        odt.insert(node{i,i,a[i]});
    }
    for(ll i=1;i<=m;i++) {
        ll op = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1, x, y;
        if(l>r) swap(l, r);
        if(op==3) {
            x = rnd()%(r-l+1) + 1;
        } else x = rnd()%vmax + 1;
        if(op==4) y = rnd()%vmax + 1;
        if(op==1) {
            odt_add(l, r, x);   //  [l,r]+=x
        } else if(op==2) {
            odt_assign(l, r, x);    //  [l,r]=x
        } else if(op==3) {
            cout << odt_kth_big(l, r, x) << '\n' ;  //  [l,r]->x th big
        } else cout << odt_sum_powmod(l, r, x, y) << '\n' ; //  [l,r]-sum->a^x%y
    }
    return 1;
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
    int ZPX = 1;
    if (multest)
        cin >> ZPX;
        // scanf("%d", &ZPX);
    _Init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}