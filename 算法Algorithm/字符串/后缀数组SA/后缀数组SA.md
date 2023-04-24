<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-08-31 11:53:12
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-10-07 11:40:18
 * @FilePath: \apricitye:\桌面\ACM\算法Algorithm\字符串\后缀数组SA\后缀数组SA.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->
# 后缀数组SA

后缀suf[i]：闭区间[i,n]

后缀数组SA[i]：n个后缀小到大排序

每次数组rank[i]：后缀suf[i]的排名

## 倍增优化O(nlogn)

用倍增的方法对每个字符开始的长度为 2^k 的子字符串进行排序，求出排名，即 rank 值。k从0开始每次+=1。

每一次排序都利用上次长度为 2^(k-1) 的字符串的 rank 值，那么长度为 2^k 的字符串就可以用两个长度为 2^(k-1) 的字符串的排名作为关键字表示，然后进行基数排序，便得出了长度为 2^k的字符串的 rank 值。

[模板](https://loj.ac/p/111)

```c++
const int N = 1e6+6;
// string s;
int n;
int maxn, p;
int cnt[N], rk[N], sa[N], id[N], sork[N], prerk[N<<2];
//  计数 后缀->rk rk->后缀 sork[i]=rk[id[i]]
int height[N];
bool rk_cmp(int x, int y, int w)
{
    return prerk[x]==prerk[y] && prerk[x+w]==prerk[y+w];
}
int SA(string s)
{
    // cin >> s;
    n = s.size();
    s = " "+s;  //  s:[1,n]
    // 基数+计数排序 1st->rk[i] 2nd->rk[i+w] (outside is min)
    maxn = 300;
    for(int i=1;i<=n;i++) ++cnt[rk[i] = s[i]];  //  初始序
    for(int i=1;i<=maxn;i++) cnt[i] += cnt[i-1];
    for(int i=n;i>=1;i--) sa[cnt[ rk[i] ]--] = i;
    // SA maxn=p->优化计数排序的值域
    int w = 1;
    while(1) {
        //  排2nd
        p = 0;
        for(int i=n;i>n-w;i--) id[++p] = i;
        for(int i=1;i<=n;i++) {
            if(sa[i]>w) id[++p] = sa[i] - w;
        }
        //  基数排序
        for(int i=0;i<=maxn;i++) cnt[i] = 0;    // reset
        for(int i=1;i<=n;i++) ++cnt[sork[i] = rk[id[i]]];   //  先存一遍 卡常
        for(int i=1;i<=maxn;i++) cnt[i] += cnt[i-1];
        for(int i=n;i>=1;i--) sa[cnt[ sork[i] ]--] = id[i];
        //  Cal sa
        p = 0;
        //  去重
        for(int i=1;i<=n;i++) prerk[i] = rk[i]; // copy
        for(int i=1;i<=n;i++) {
            rk[sa[i]] = rk_cmp(sa[i], sa[i-1], w)? p : ++p;
        }
        //  值域=n
        if(p==n) {
            for(int i=1;i<=n;i++) sa[rk[i]] = i;
            break;
        }
        // w->长度倍增 m=p值域优化
        w<<=1;  maxn = p;
    }
    //  height
    for(int i=1, k=0;i<=n;i++) {
        if(rk[i]==0) continue;
        if(k) --k;
        while(s[i+k]==s[sa[rk[i]-1]+k]) ++k;
        height[rk[i]] = k;
    }
    for(int i=1;i<=n;i++) cout << sa[i] << " \n"[i==n];
    return 1;
}
```

## 一些板子

```c++
class SuffixArray {
public:
    using size_type = unsigned;
    using pointer = size_type*;
    using const_pointer = const size_type*;
    const_pointer sa, rk, ht;
 
private:
    std::unique_ptr<size_type[]> data;
 
private:
    template<typename S>
    inline static bool substring_equal(const S& s, size_type p1, size_type p2, size_type len) {
        for (size_type i = 0;i < len;++i)
            if (s[p1 + i] != s[p2 + i])
                return false;
        return true;
    }
 
    template<typename S>
    inline static void induced_sort(
        const S& s,
        pointer sa,
        bool* type,
        pointer pos,
        pointer lbuk,
        pointer sbuk,
        size_type n,
        size_type m,
        size_type n0) {
        std::fill_n(sa, n, 0);
        lbuk[0] = 0;
        for (size_type i = 1;i < m;++i)
            lbuk[i] = sbuk[i - 1];
        for (size_type i = n0;i-- > 0;)
            sa[--sbuk[s[pos[i]]]] = pos[i];
        sbuk[m - 1] = n;
        for (size_type i = 1;i < m;++i)
            sbuk[i - 1] = lbuk[i];
        sa[lbuk[s[n - 1]]++] = n - 1;
        for (size_type i = 0;i < n;++i)
            if (sa[i] > 0 && !type[sa[i] - 1])
                sa[lbuk[s[sa[i] - 1]]++] = sa[i] - 1;
        lbuk[0] = 0;
        for (size_type i = 1;i < m;++i)
            lbuk[i] = sbuk[i - 1];
        for (size_type i = n;i-- > 0;)
            if (sa[i] > 0 && type[sa[i] - 1])
                sa[--sbuk[s[sa[i] - 1]]] = sa[i] - 1;
    }
 
    template<typename S>
    static void sais(
        const S& s,
        pointer sa,
        bool* type,
        pointer len,
        pointer pos,
        pointer lbuk,
        pointer sbuk,
        size_type n,
        size_type m) {
        type[n - 1] = false;
        for (size_type i = n - 1;i-- > 0;)
            type[i] = s[i] != s[i + 1] ? s[i] < s[i + 1] : type[i + 1];
        size_type n0 = 0;
        for (size_type i = 1;i < n;++i)
            if (!type[i - 1] && type[i])
                pos[n0++] = i;
        std::fill_n(len, n, 0);
        for (size_type p = n - 1, i = n0;i-- > 0;p = pos[i])
            len[pos[i]] = p - pos[i] + 1;
        std::fill_n(sbuk, m, 0);
        for (size_type i = 0;i < n;++i)
            ++sbuk[s[i]];
        for (size_type i = 1;i < m;++i)
            sbuk[i] += sbuk[i - 1];
        induced_sort(s, sa, type, pos, lbuk, sbuk, n, m, n0);
        sbuk[m - 1] = n;
        for (size_type i = 1;i < m;++i)
            sbuk[i - 1] = lbuk[i];
        size_type m0 = -1;
        size_type ppos = -1, plen = 0;
        for (size_type i = 0;i < n;++i) {
            if (len[sa[i]] == 0) continue;
            if (len[sa[i]] != plen || !substring_equal(s, sa[i], ppos, plen)) ++m0;
            plen = len[sa[i]];
            len[sa[i]] = m0;
            ppos = sa[i];
        }
        const pointer s0 = sa;
        const pointer sa0 = sa + n0;
        for (size_type i = 0;i < n0;++i)
            s0[i] = len[pos[i]];
        if (++m0 < n0)
            sais(s0, sa0, type + n, len, pos + n0, lbuk, lbuk + n0, n0, m0);
        else for (size_type i = 0;i < n0;++i)
            sa0[s0[i]] = i;
        for (size_type i = 0;i < n0;++i)
            pos[i + n0] = pos[sa0[i]];
        induced_sort(s, sa, type, pos + n0, lbuk, sbuk, n, m, n0);
    }
 
public:
    template<typename S>
    SuffixArray(const S& s, size_type n, size_type m)
        : data(std::make_unique<size_type[]>(3 * n)) {
        const auto type = std::make_unique<bool[]>(2 * n);
        const auto lbuk = std::make_unique<size_type[]>(std::max(n, m));
        const auto sbuk = std::make_unique<size_type[]>(m);
        const pointer sa = data.get(), rk = sa + n, ht = rk + n;
        sais(s, sa, type.get(), rk, ht, lbuk.get(), sbuk.get(), n, m);
        for (size_type i = 0;i < n;++i)
            rk[sa[i]] = i;
        for (size_type k = 0, i = 0;i < n;++i) {
            if (rk[i] == 0) continue;
            if (k > 0) --k;
            for (size_type j = sa[rk[i] - 1], l = n - std::max(i, j);k < l;++k)
                if (s[i + k] != s[j + k]) break;
            ht[rk[i]] = k;
        }
        this->sa = sa;
        this->rk = rk;
        this->ht = ht;
    }
 
    inline size_type suffix(size_type p) const {
        return sa[p];
    }
 
    inline size_type rank(size_type p) const {
        return rk[p];
    }
 
    // height start from 1
    inline size_type height(size_type p) const {
        return ht[p];
    }
};
```

## DC3算法O(n)

## height数组

定义height数组：

```c++
height[i] = LCP( suffix(sa[i-1]) , suffix(sa[i]) )
```

即排名相邻的两个后缀的最长公共前缀

有以下性质：

假设rk[j] < rk[k]

```c++
LCP( suffix(j) , suffix(k) ) = min( height[rk[j]+1] , height[rk[j]+2] ..., height[rk[k]] )
```

假设h[i] = height[ rk[i] ]

```c++
h[i] >= h[i-1]-1
// h[rk[i]] >= h[rk[i-1]]-1
```

求height：

```c++
//  O(n)
for(int i=1, k=0;i<=n;i++) {
    if(rk[i]==0) continue;
    if(k) --k;
    while(s[i+k]==s[sa[rk[i]-1]+k]) ++k;
    height[rk[i]] = k;
}
```

## 应用

### 单串问题

#### 串循环移动求最小位置

复制为两倍，处理一下SA，顺序的`sa<=len`者

```c++
string s;
int n;
int maxn, p;
int cnt[N], rk[N], sa[N], id[N], sork[N], prerk[N<<2];
//  计数 后缀->rk rk->后缀 sork[i]=rk[id[i]]
bool rk_cmp(int x, int y, int w)
{
    return prerk[x]==prerk[y] && prerk[x+w]==prerk[y+w];
}
int SA()
{
    // cin >> s;
    n = s.size();
    // s = " "+s;  //  s:[1,n]
    // 基数+计数排序 1st->rk[i] 2nd->rk[i+w] (outside is min)
    maxn = 300;
    for(int i=1;i<=n;i++) ++cnt[rk[i] = s[i]];  //  初始序
    for(int i=1;i<=maxn;i++) cnt[i] += cnt[i-1];
    for(int i=n;i>=1;i--) sa[cnt[ rk[i] ]--] = i;
    // SA maxn=p->优化计数排序的值域
    int w = 1;
    while(1) {
        //  排2nd
        p = 0;
        for(int i=n;i>n-w;i--) id[++p] = i;
        for(int i=1;i<=n;i++) {
            if(sa[i]>w) id[++p] = sa[i] - w;
        }
        //  基数排序
        for(int i=0;i<=maxn;i++) cnt[i] = 0;    // reset
        for(int i=1;i<=n;i++) ++cnt[sork[i] = rk[id[i]]];   //  先存一遍 卡常
        for(int i=1;i<=maxn;i++) cnt[i] += cnt[i-1];
        for(int i=n;i>=1;i--) sa[cnt[ sork[i] ]--] = id[i];
        //  Cal sa
        p = 0;
        //  去重
        for(int i=1;i<=n;i++) prerk[i] = rk[i]; // copy
        for(int i=1;i<=n;i++) {
            rk[sa[i]] = rk_cmp(sa[i], sa[i-1], w)? p : ++p;
        }
        //  值域=n
        if(p==n) {
            for(int i=1;i<=n;i++) sa[rk[i]] = i;
            break;
        }
        // w->长度倍增 m=p值域优化
        w<<=1;  maxn = p;
    }
    // for(int i=1;i<=n;i++) cout << sa[i] << " \n"[i==n];
    return 1;
}
int PX()
{
    cin >> s;
    int len = s.size();
    s=" "+s+s;  //  copy
    SA();   //  求后缀数组
    for(int i=1;i<=n;i++) if(sa[i]<=len) cout << s[sa[i]+len-1];    //  >len的在第二部分
    return 1;
}
```

#### 最长公共前缀LCP

根据height数组，若rk[i] < rk[j]，lcp(suf[i], suf[j]) = min{height[ rk[i+1],..rk[j] ]}，于是就是RMQ问题

#### 最长重复子串

##### 可重叠求最长

求height数组的最大值即可

##### 不可重叠求最长

二分答案x，把sa按相邻差（也就是height）>=x分组，维护组内max和min，判断位置差是否大于x（不重叠）

##### 可重叠的k次最长重复子串

求最少出现k次的最长重复子串，可重叠

二分答案x，把sa按相邻差（也就是height）>=x分组，判断是否有一个组的后缀个数不小于k

<https://www.luogu.com.cn/problem/P2852>

#### 不相同的子串个数

子串是后缀的前缀，问题转成所有后缀的不同前缀的个数
按`suf[sa[i]],suf[sa[i+1]]`的顺序枚举，每次新来的`suf[sa[k]]`会产生n-sa[k]+1个前缀，其中有height[k]个是和前面相同的，因此贡献是n-sa[k]+1-height[k]

<https://www.spoj.com/problems/SUBST1/>

#### 最长回文子串

相当于求两个相邻位置，左前缀和右后缀的LCP。把原串反过来插到后面（中间用一个特殊字符隔开），把求前缀转成求后端的后缀。于是就可以求两个后缀的LCP。

<https://www.acwing.com/problem/content/141/>

#### 连续重复子串

字符串L由字符串S重复R次得到，求最大的R

枚举S的长度k。先判断L长度能否被k整除，再看LCP(suf[1], suf[k+1])是否等于n-k。

<http://poj.org/problem?id=2406>

#### 重复次数最多的连续重复子串

枚举长度L。记rk[L*i]和rk[L*(i+1)]往前和后匹配多远，总长度K，那么连续出现的次数就是K/L+1，最后取max。

### 双串问题

常用做法是连接两个串，然后求出SA和height，再根据height求解

#### 求两个串的最长公共子串

<http://poj.org/problem?id=2774>

#### 求两个串长度>=k的公共子串的个数

<http://poj.org/problem?id=3415>

如A='xx'，B='xx'，k=1，则ANS=5

### 多串问题

常用做法是连接两个串，然后求出SA和height，再根据height求解，并且经常需要二分答案。

#### 求多个串的最长公共子串

<https://www.luogu.com.cn/problem/P5546>

#### 求n个串中出现>=k次(一个串一次)的最长子串

<http://poj.org/problem?id=3294>

#### 每个字符串至少出现两次且不重叠的最长子串

<https://www.spoj.com/problems/PHRASES/>

#### 出现或反转后出现在每个字符串中的最长子串

<http://poj.org/problem?id=3294>
