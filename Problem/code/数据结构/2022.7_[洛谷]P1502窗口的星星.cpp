/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-24 19:40:28
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-07-22 15:22:07
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数据结构\2022.7_[洛谷]P1502窗口的星星.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int ll
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
const int _mod = 998244353;
const int N = 1e5+55;
const long double eps=1e-8;
const long double PI=acos(-1.0);
ll mpow(ll a,ll b,ll m){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline bool _bug(bool _line=0,bool line_=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";if(line_)cout<<'\n';return 1;
#endif
    return 0;
}
/*
    洛谷    P1502 窗口的星星    扫描线/线段树
    <https://www.luogu.com.cn/problem/P1502>
    每个星星可以用一个矩形代替,每个矩形有权值
    求二维空间某点最大权值
*/
bool multest = 1;
// bool multest = 0;
void _Init(){
}
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define ls rt<<1
#define rs rt<<1|1
#define mid ((l+r)>>1)
int n, w, h;
ll ans = 0;
ll T[N];            //  T放的是y上区间的端点
struct Segment {    //  y轴建点 每个点有一个h即x坐标,类似时间戳
    ll l, r, h;
    //  h是x坐标
    ll val;
    //  进是abs(val) 出是-abs(val)
    bool operator <(const Segment& x) const {
        if(h!=x.h) return h<x.h;    //  先按x排
        return val>x.val;           //  再按val排
    }
}Seg[N<<2];
struct SegmentTree {
    ll l, r;
    ll maxn, lazy_add;
    #define l(x) tr[x].l
    #define r(x) tr[x].r
    #define ma(x) tr[x].maxn
    #define lz(x) tr[x].lazy_add
}tr[N<<2];
inline void build(ll rt, ll l, ll r)
{
    l(rt) = l, r(rt) = r, ma(rt) = lz(rt) = 0;
    if(l==r) return ;
    build(lson);
    build(rson);
}
inline void pushdown(int rt)
{
    ma(ls)+=lz(rt);
    ma(rs)+=lz(rt);
    lz(ls)+=lz(rt);
    lz(rs)+=lz(rt);
    lz(rt)=0;
}
inline void pushup(int rt)
{
    ma(rt) = max(ma(ls), ma(rs));
}
inline int update(int rt, ll ql, ll qr, ll x)
{
    ll l = l(rt), r = r(rt);
    if(ql<=l && r<=qr) return ma(rt)+=x, lz(rt)+=x, 0;
    pushdown(rt);
    if(ql<=mid) update(ls, ql, qr, x);
    if(qr>mid) update(rs, ql, qr, x);
    pushup(rt);
    return 1;
}
int PX()
{
    memset(Seg, 0, sizeof(Seg));
    memset(tr, 0, sizeof(tr));
    ans = 0;
    cin >> n >> w >> h;
    for(int i=1;i<=n;i++) {
        ll x, y, l;
        cin >> x >> y >> l;
        int L = (i<<1)-1, R = (i<<1);
        T[L] = y;
        T[R] = y+h-1;
        Seg[L] = (Segment){y, y+h-1, x, l};
        Seg[R] = (Segment){y, y+h-1, x+w-1, -l};
    }
    n<<=1;
    //  离散化
    sort(T+1, T+1+n);
    ll cnt = unique(T+1, T+1+n) - T -1;
    sort(Seg+1, Seg+1+n);
    for(int i=1;i<=n;i++) {
        ll L = lower_bound(T+1, T+1+cnt, Seg[i].l) - T;
        ll R = lower_bound(T+1, T+1+cnt, Seg[i].r) - T;
        Seg[i].l = L;
        Seg[i].r = R;
    }
    build(1, 1, cnt);
    for(int i=1;i<=n;i++) {
        update(1, Seg[i].l, Seg[i].r, Seg[i].val);
        ans = max(ans, ma(1));
    }
    cout << ans << '\n';
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
    ll ZPX = 1;
    if (multest)
        cin >> ZPX;
    _Init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}