/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-30 13:58:10
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-10-07 11:43:31
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数据结构\SegmentTree.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*  SegmentTree 线段树

Here form SEGTREE1 to SEGTREE
using namespace

*/

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6+111;

namespace SEGTREE1{
/*
    加&乘&覆盖&区间pow和 板子集成
    op1 add
    op2 mul
    op3 change
    op4 sum{pow}   p=[1,3]可以直接存下来
    lazy优先级:覆盖>乘>加
*/
struct Seg {
#define MAX 400005  //  N*4
#define Iinf 1e9+7
#define Linf 1e18+7
#define Mod 10007   //  Mod
#define ls rt<<1
#define rs rt<<1|1
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
    //  T[x]->pow(val,x+1)   lazy: add < mul < change
    int T[MAX][3], _add[MAX], _mul[MAX], _change[MAX];
    // ll a[MAX/4];
    int n;
    inline void build(int rt,int l,int r) {
        for(int i=0;i<3;i++) T[rt][i]=0;
        _add[rt]=0;
        _change[rt]=-1;
        _mul[rt]=1;
        if(l==r) return ;
        int m=(l+r)>>1;
        build(lson);
        build(rson);
    }
    inline void pushup(int rt) {
        for(int i=0;i<3;i++) T[rt][i] = T[ls][i] + T[rs][i];
        for(int i=0;i<3;i++) T[rt][i]%=Mod;
    }
    inline void pushdown_add(int rt,int l,int r,int v) {
        int len=r-l+1;
        int v2=( (v%Mod)*(v%Mod) )%Mod;
        int v3=( (v2%Mod)*(v%Mod) )%Mod;
        //  注意顺序
        T[rt][2] = T[rt][2] + 3*v*T[rt][1]%Mod + 3*v2*T[rt][0]%Mod + len*v3%Mod;
        T[rt][1] = T[rt][1] + 2*v*T[rt][0]%Mod + len*v2%Mod;
        T[rt][0] = T[rt][0] + len*v%Mod;
        for(int i=0;i<3;i++) T[rt][i]%=Mod;
        _add[rt] = (_add[rt]+v)%Mod;
    }
    inline void pushdown_mul(int rt,int l,int r,int v) {
        int v2=( (v%Mod)*(v%Mod) )%Mod;
        int v3=( (v2%Mod)*(v%Mod) )%Mod;
        T[rt][0] = T[rt][0]*v ;
        T[rt][1] = T[rt][1]*v2 ;
        T[rt][2] = T[rt][2]*v3 ;
        for(int i=0;i<3;i++) T[rt][i]%=Mod;
        _add[rt] = _add[rt]*v %Mod;
        _mul[rt] = _mul[rt]*v %Mod;
    }
    inline void pushdown_change(int rt,int l,int r,int v) {
        int len=r-l+1;
        int v2=( (v%Mod)*(v%Mod) )%Mod;
        int v3=( (v2%Mod)*(v%Mod) )%Mod;
        T[rt][0] = v*len ;
        T[rt][1] = v2*len ;
        T[rt][2] = v3*len ;
        for(int i=0;i<3;i++) T[rt][i]%=Mod;
        _add[rt] = 0;
        _mul[rt] = 1;
        _change[rt] = v;
    }
    inline void pushdown(int rt,int l,int r) {
        int m=(l+r)>>1;
        if(_change[rt]!=-1) {
            pushdown_change(lson,_change[rt]);
            pushdown_change(rson,_change[rt]);
            _change[rt]=-1;
        }
        if(_mul[rt]!=1) {
            pushdown_mul(lson,_mul[rt]);
            pushdown_mul(rson,_mul[rt]);
            _mul[rt]=1;
        }
        if(_add[rt]!=0) {
            pushdown_add(lson,_add[rt]);
            pushdown_add(rson,_add[rt]);
            _add[rt]=0;
        }
    }
    inline void Add(int rt,int l,int r,int ql,int qr,int x) {
        if(ql<=l&&r<=qr) {
            pushdown_add(rt,l,r,x);
            return ;
        }
        pushdown(rt,l,r);
        int m=(l+r)>>1;
        if(ql<=m) Add(lson,ql,qr,x);
        if(qr>m) Add(rson,ql,qr,x);
        pushup(rt);
    }
    inline void Mul(int rt,int l,int r,int ql,int qr,int x) {
        if(ql<=l&&r<=qr) {
            pushdown_mul(rt,l,r,x);
            return ;
        }
        pushdown(rt,l,r);
        int m=(l+r)>>1;
        if(ql<=m) Mul(lson,ql,qr,x);
        if(qr>m) Mul(rson,ql,qr,x);
        pushup(rt);
    }
    inline void Change(int rt,int l,int r,int ql,int qr,int x) {
        if(ql<=l&&r<=qr) {
            pushdown_change(rt,l,r,x);
            return ;
        }
        pushdown(rt,l,r);
        int m=(l+r)>>1;
        if(ql<=m) Change(lson,ql,qr,x);
        if(qr>m) Change(rson,ql,qr,x);
        pushup(rt);
    }
    inline int Askpow(int rt,int l,int r,int ql,int qr,int x) {
        if(ql<=l&&r<=qr) return T[rt][x];
        pushdown(rt,l,r);
        int m=(l+r)>>1;
        int res=0;
        if(ql<=m) res+=Askpow(lson,ql,qr,x);
        res%=Mod;
        if(qr>m) res+=Askpow(rson,ql,qr,x);
        res%=Mod;
        return res;
    }
    inline void ope(int op,int l,int r,int x) {
        if(op==1) Add(1,1,n,l,r,x);
        else if(op==2) Mul(1,1,n,l,r,x);
        else if(op==3) Change(1,1,n,l,r,x);
        else cout<<Askpow(1,1,n,l,r,x-1)<<'\n';
    }
};
}   //  namespace SEGTREE1

namespace SEGTREE2{
//  静态开点线段树  带懒标记 区间和，区间加
//  SegTree with lazy tag for add and sum
struct SegNode{     //  point : po
    int l,r,val;    //  [l,r] , val
    int lazy;       //  lazy tag
};           //  size : N*4
inline void pushup(SegNode *v, int po)          //  pushup
{
    v[po].val = v[po*2].val + v[po*2+1].val;  //sum
    // v[po].val = max(v[po*2].val, v[po*2+1].val);  //max
    // v[po].val = min(v[po*2].val, v[po*2+1].val);  //min
}
inline void pushdown(SegNode *v, int po)        //  pushdown
{
    if(v[po].lazy) {        //  lazy tag pushdown
        int lson = po*2, rson = po*2+1;
        v[lson].val += v[po].lazy*(v[lson].r - v[lson].l + 1); v[rson].val += v[po].lazy*(v[rson].r - v[rson].l + 1);
        v[lson].lazy += v[po].lazy; v[rson].lazy += v[po].lazy;
        v[po].lazy = 0;
    }
}
void build(SegNode *v, int *arr, int po, int l, int r)      // build : arr , po->[l,r]
{
    v[po].l = l, v[po].r = r, v[po].lazy = 0;
    if (l == r) {
        v[po].val = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(v, arr, po*2, l, mid);       // build L: po*2->[l,mid]
    build(v, arr, po*2+1, mid+1, r);   // build R: po*2+1->[mid+1,r]
    pushup(v, po);                     // pushup
}
void update(SegNode *v, int po, int L, int R, int k)           //  update : po->[l,r] , k
{
    if(L <= v[po].l && v[po].r <= R) {
        v[po].val += k*(v[po].r - v[po].l + 1), v[po].lazy +=k;      // add k
        return ;
    }
    pushdown(v, po);                   //  pushdown
    int mid = (v[po].l + v[po].r) / 2;
    if(R <= mid) update(v, po*2, L, R, k);
    else if(L > mid) update(v, po*2+1, L, R, k);
    else update(v, po*2, L, R, k), update(v, po*2+1, L, R, k);
    pushup(v, po);                     //  pushup
}
int query(SegNode *v, int po, int L, int R)             //  query : [L,R] , now->po
{
    if(L <= v[po].l && v[po].r <= R) {
        return v[po].val;
    }
    pushdown(v, po);                   //  pushdown
    int mid = (v[po].l + v[po].r) / 2;
    if(R <= mid) return query(v, po*2, L, R);
    else if(L > mid) return query(v, po*2+1, L, R);
    else {
        int lque = query(v, po*2, L, R);
        int rque = query(v, po*2+1, L, R);
        int res = lque + rque;  //sum
        // int res = max(lque, rque);  //max
        // int res = min(lque, rque);  //min
        return res;
    }
}
//=====
int a[N];
SegNode v[N<<2];
void Zhuangpx()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(v,a,1,1,n);
    while(m--){
        int op,L,R,k;cin>>op;
        if(op==1) {
            cin>>L>>R>>k;
            update(v,1,L,R,k);
        } else {
            cin>>L>>R;
            cout<<query(v,1,L,R)<<'\n';
        }
    }
}
//=====
}   //  namespace SEGTREE2

namespace SEGTREE3{
//  线段树  类封装 区间最值 更新(加) 覆盖(修改)
//  SegmentTree as template for max or min, update(add), cover(new val)
template <typename T> struct SegmentTree {
    struct SegNode {
        int l, r;
        T val, change, cover;
        //  val:value, change:add val, cover:cover val
        SegNode() {}
    };
    int n;
    vector<SegNode> v;
    vector<bool> covered;
    SegmentTree(int sn) : n(sn), v(sn<<2+1), covered(sn<<2+1) {}
    inline void pushup(int po)
    {
        int mid = (v[po].l + v[po].r) / 2;
        // v[po].val = v[po*2].val + v[po*2+1].val;  //sum
        v[po].val = max(query(po*2, v[po].l, mid), query(po*2+1, mid+1, v[po].r));  //max
        // v[po].val = min(query(po*2, v[po].l, mid), query(po*2+1, mid+1, v[po].r));  //min
    }
    inline void pushdown(int po)
    {
        if(covered[po]) {
            int lson = po*2, rson = po*2+1;
            v[po].val = v[po].cover;
            v[lson].cover = v[rson].cover = v[po].cover;
            covered[lson] = covered[rson] = 1;
            covered[po] = 0;
        }
        if(v[po].change) {
            v[po].val += v[po].change;
            int lson = po*2, rson = po*2+1;
            v[lson].change += v[po].change;
            v[rson].change += v[po].change;
            v[po].change = 0;
        }
    }
    void build(const T arr[], int po, int l, int r)
    {
        v[po].l = l, v[po].r = r, v[po].change = 0, v[po].cover = 0;
        if(l==r) {
            v[po].val = arr[po];
            return ;
        }
        int mid = (l + r) / 2;
        build(arr, po*2, l, mid);
        build(arr, po*2+1, mid+1, r);
        v[po].val = max(v[po*2].val, v[po*2+1].val);    //max
        // v[po].val = min(v[po*2].val, v[po*2+1].val);    //min
    }
    void update(int po, int L, int R, const T &k)
    {
        if(L <= v[po].l && v[po].r <= R) {
            v[po].change += k;
            return ;
        }
        pushdown(po);
        int mid = (v[po].l + v[po].r) / 2;
        if(R <= mid) update(po*2, L, R, k);
        else if(mid < L) update(po*2+1, L, R, k);
        else update(po*2, L, R, k), update(po*2+1, L, R, k);
        pushup(po);
    }
    void modify(int po, int L, int R, const T &k)
    {
        if(L <= v[po].l && v[po].r <= R) {
            v[po].change = 0;
            v[po].cover = k;
            covered[po] = 1;
            return ;
        }
        pushdown(po);
        int mid = (v[po].l + v[po].r) / 2;
        if(R <= mid) modify(po*2, L, R, k);
        else if(mid < L) modify(po*2+1, L, R, k);
        else modify(po*2, L, R, k), modify(po*2+1, L, R, k), pushup(po);
    }
    T query(int po, int L, int R)
    {
        if(v[po].l == L && v[po].r == R) {
            if(covered[po]) return v[po].cover;
            return v[po].val + v[po].change;
        }
        pushdown(po);
        int mid = (v[po].l + v[po].r) / 2;
        if(R <= mid) return query(po*2, L, R);
        else if(mid < L) return query(po*2+1, L, R);
        else return /*min*/max(query(po*2, L, mid) , query(po*2+1, mid+1, R));
    }
};
}

namespace SEGTREE4{
//  静态开点线段树 区间最值 区间修改
    int n,m,a[N];

struct node {
    int l, r, num, lazy;
};

struct segment_tree {
    node t[N << 2];

    void push_down(int root) {
        if(t[root].lazy != 0) {
            //cal_lazy
            t[root].num += t[root].lazy;
            if(t[root].l != t[root].r) {
                //union_lazy
                int ch = root << 1;
                t[ch].lazy += t[root].lazy;
                t[ch + 1].lazy += t[root].lazy;
            }
            //init_lazy
            t[root].lazy = 0;
        }
    }


    void push_up(int root) {
        int ch = root << 1;
        push_down(ch);
        push_down(ch + 1);
        t[root].num = min(t[ch].num, t[ch + 1].num);
    }

    void build(int root, int l, int r) {
        t[root].l = l, t[root].r = r, t[root].lazy = 0;
        if(l != r) {
            int ch = root << 1;
            int mid = (l + r) >> 1;
            build(ch, l, mid);
            build(ch + 1, mid + 1, r);
            push_up(root);
        } else {
            t[root].num = a[l];
        }
    }

    void update(int root, int l, int r, int add) {
        push_down(root);
        if(t[root].l >= l && t[root].r <= r) {
            t[root].lazy += add;
            return;
        }
        int ch = root << 1;
        int mid = t[root].l + t[root].r >> 1;
        if(r <= mid) update(ch, l, r, add);
        else if(l > mid) update(ch + 1, l, r, add);
        else update(ch, l, mid, add), update(ch + 1, mid + 1, r, add);
        push_up(root);
    }

    int query(int root, int l, int r) {
        push_down(root);
        if(t[root].l >= l && t[root].r <= r) {
            return t[root].num;
        }
        int ch = root << 1;
        int mid = t[root].l + t[root].r >> 1;
        if(r <= mid) return query(ch, l, r);
        else if(l > mid) return query(ch + 1, l, r);
        else return min(query(ch, l, mid), query(ch + 1, mid + 1, r));
    }
};
}


namespace SEGTREE5{
//  静态开点线段树  带懒标记 区间和，区间加，区间乘，结果取模
//  SegTree with lazy tag for sum, add, mul and mod
int mod;
struct SegNode{     //  point : po
    int l,r,val;    //  [l,r] , val
    int lazy_add, lazy_mul;       //  lazy tag for add and mul
};           //  size : N*4
//  evaluate v.评估 先乘后加
inline void eval(SegNode *v, int po, int m_add, int m_mul)                   //  mul first and then add
{
    int l = v[po].l, r = v[po].r;
    v[po].val = ( (v[po].val * m_mul) % mod+ ((r - l + 1) * m_add) % mod ) % mod;
    v[po].lazy_mul = ( (v[po].lazy_mul) % mod * (m_mul) % mod ) % mod;
    v[po].lazy_add = ( v[po].lazy_add * m_mul + m_add) % mod;
}
inline void pushup(SegNode *v, int po)          //  pushup
{
    v[po].val = (v[po*2].val + v[po*2+1].val) % mod;  //sum % mod
}
inline void pushdown(SegNode *v, int po)        //  pushdown
{
    int lson = po*2, rson = po*2+1;
    eval(v, lson, v[po].lazy_add, v[po].lazy_mul);
    eval(v, rson, v[po].lazy_add, v[po].lazy_mul);
    v[po].lazy_add = 0, v[po].lazy_mul = 1;
}
void build(SegNode *v, int *arr, int po, int l, int r)      // build : arr , po->[l,r]
{
    v[po].l = l, v[po].r = r, v[po].lazy_add = 0, v[po].lazy_mul = 1;
    if (l == r) {
        v[po].val = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(v, arr, po*2, l, mid);       // build L: po*2->[l,mid]
    build(v, arr, po*2+1, mid+1, r);   // build R: po*2+1->[mid+1,r]
    pushup(v, po);                     // pushup
}
void update(SegNode *v, int po, int L, int R, int m_add = 0, int m_mul = 1)           //  update : po->[l,r] , + k_add, * k_mul
{
    if(L <= v[po].l && v[po].r <= R) {
        eval(v, po, m_add, m_mul);     //  evaluate v.评估
        return ;
    }
    pushdown(v, po);                   //  pushdown
    int mid = (v[po].l + v[po].r) / 2;
    if(R <= mid) update(v, po*2, L, R, m_add, m_mul);
    else if(L > mid) update(v, po*2+1, L, R, m_add, m_mul);
    else update(v, po*2, L, R, m_add, m_mul), update(v, po*2+1, L, R, m_add, m_mul);
    pushup(v, po);                     //  pushup
}
inline void update_add(SegNode *v, int po, int L, int R, int k)              //  update_add : po->[l,r] , + k
{
    update(v, po, L, R, k, 1);
}
inline void update_mul(SegNode *v, int po, int L, int R, int k)              //  update_mul : po->[l,r] , * k
{
    update(v, po, L, R, 0, k);
}
int query(SegNode *v, int po, int L, int R)             //  query : [L,R] , now->po
{
    if(L <= v[po].l && v[po].r <= R) {
        return v[po].val;
    }
    pushdown(v, po);                   //  pushdown
    int mid = (v[po].l + v[po].r) / 2;
    if(R <= mid) return query(v, po*2, L, R);
    else if(L > mid) return query(v, po*2+1, L, R);
    else {
        int lque = query(v, po*2, L, R);
        int rque = query(v, po*2+1, L, R);
        int res = ( lque + rque ) % mod;      //sum % mod
        return res;
    }
}
//=====
int a[N];
SegNode v[N<<2];
void Zhuangpx()
{
    int n,m;
    cin>>n>>m>>mod;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(v,a,1,1,n);
    while(m--) {
        int op;cin>>op;
        if(op==1){  //  mul
            int l,r,k;cin>>l>>r>>k;
            update_mul(v,1,l,r,k);
        }
        else if(op==2){ //  add
            int l,r,k;cin>>l>>r>>k;
            update_add(v,1,l,r,k);
        }
        else {  //  query sum of [l,r]
            int l,r;cin>>l>>r;
            cout<<query(v,1,l,r)<<'\n';
        }
    }
}
//=====
}   //  namespace SEGTREE4


//
// S: return type, op: how to merge at return, e: S default constructor
// F: value type of lazy value
// mapping: called on apply() to each item, mapping(F f, S item)
// composition: called on apply() to lazy value of a seg, composition(F f, F lazy)
// id: default falue of lazy value
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while ((1 << log) < _n) ++log;
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

