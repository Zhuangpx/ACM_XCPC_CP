<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-10-24 16:17:08
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-10-24 19:01:30
 * @FilePath: \apricitye:\桌面\ACM\其他\CDQ分治\CDQ分治.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->

# CDQ分治

[陈丹琦的论文](https://www.cs.princeton.edu/~danqic/papers/divide-and-conquer.pdf)

[oiwiki](https://oi-wiki.org/misc/cdq-divide/)

[知乎](https://zhuanlan.zhihu.com/p/332996578)

一种类似归并/分治的思想，应用场景例如：

- 解决点对问题
- 1D/1D动态规划的优化与转移
- 利用CDQ分治把动态问题转为静态问题
- 二维/三维偏序问题

## 解决点对问题

例如区间 `[l,r]` 询问满足某些性质的点对 `<i,j>` 的数量或函数值，进行区间分治：

1. 区间二分：`l-mid-r`
2. 把点对分成三类：
   1. `i:[l,mid]` ， `j:[l,mid]`
   2. `i:[l,mid]` ， `j:[mid+1,r]`
   3. `i:[mid+1,r]` ， `j:[mid+1,r]`
3. 递归解决类1和类3，再设法解决类2

### 例题：动态删除维护逆序对

<https://www.luogu.com.cn/problem/P3157>

```c++
struct Node {
    int val, del, cnt;
};
struct BIT {
    int n;
    int bit[N];
    inline void low_up(int &x) { x+=x&(-x); }
    inline void low_down(int &x) { x-=x&(-x); }
    inline void add(int x, int d) {
        while(x<=n+1) bit[x]+=d, low_up(x);
    }
    inline int query(int x) {
        int res = 0;
        while(x>0) res+=bit[x], low_down(x);
        return res;
    }
} T;
int PX()
{
    /*
        CDQ 分治 动态删除维护逆序对
        转成静态的三维偏序问题 CDD分治预处理
    */
    int n, m;
    cin >> n >> m;
    T.n = max(n, m);
    Ve(Node) a(n+1);
    map<int,int> mp;
    int ans = 0;
    for(int i=1; i<=n; i++) cin >> a[i].val, a[i].del = m+1, mp[a[i].val] = i;
    for(int i=1,d; i<=m; i++) {
        cin >> d;
        int pos = mp[d];
        a[pos].del = i;
    }
    //  先算初始的逆序对
    for(int i=1;i<=n;i++) {
        ans += (T.query(n+1) - T.query(a[i].val));  // 大于的
        T.add(a[i].val, 1);
    }
    //  撤销
    for(int i=1;i<=n;i++) T.add(a[i].val, -1);
        function<bool(Node&,Node&)> cmp_val = [&](Node& x, Node& y) -> bool {
            return x.val < y.val;
        };
        function<bool(Node&,Node&)> cmp_del = [&](Node& x, Node& y) -> bool {
            return x.del < y.del;
        };
        function<void(int,int)> CDQ_divide = [&](int l, int r) -> void {
            //  CDQ_divide(l, r) -> (l,r] 左闭右开
            if(r-l<=1) return ;
            int mid = (l+r)/2, nl, nr;
            CDQ_divide(l, mid);  CDQ_divide(mid, r);
            //  cal (l,mid]
            nl = l+1, nr = mid+1;
            while(nl<=mid) {
                //  (mid,r] 找小于 nl 的
                while(a[nl].val>a[nr].val && nr<=r) T.add(a[nr].del, 1), nr++;
                //  query 当前的 nl
                a[nl].cnt += (T.query(m+1) - T.query(a[nl].del));
                nl++;
            }
            //  撤销
            nl = l+1, nr = mid+1;
            while(nl<=mid) {
                while(a[nl].val>a[nr].val && nr<=r) T.add(a[nr].del, -1), nr++;
                nl++;
            }
            //  cal (mid,r]
            nl = mid, nr = r;
            while(nr>mid) {
                //  (l,mid] 找大于 nr 的
                while(a[nl].val>a[nr].val && nl>l) T.add(a[nl].del, 1), nl--;
                //  query 当前的 nr
                a[nr].cnt += (T.query(m+1) - T.query(a[nr].del));
                nr--;
            }
            nl = mid, nr = r;
            while(nr>mid) {
                while(a[nl].val>a[nr].val && nl>l) T.add(a[nl].del, -1), nl--;
                nr--;
            }
            // sort & up
            sort(a.begin()+l+1, a.begin()+r+1, cmp_val);
        };
    CDQ_divide(0, n);   //  cal
    sort(a.begin()+1, a.end(), cmp_del);
    for(int i=1;i<=m;i++) {
        cout << ans << '\n';
        ans -= a[i].cnt;
    }
    return 1;
}
```

## 1D/1D动态规划的优化与转移

1D/1D动态规划就是状态和转移都是一维的DP，朴素是 `O(n^2)` 的，有时能通过CDQ分治优化到 `O(nlogn^2)` 。

例如求LIS的DP问题。
