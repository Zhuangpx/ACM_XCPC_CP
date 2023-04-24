# [AcWing109. 天才ACM](https://www.acwing.com/problem/content/description/111/)

一道非常好的倍增题。相对于二分，倍增在增量跨度很大的时候非常使用，其与二分某种程度上也算正反关系。

## 题意

![image-20210514191204226](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210514191204226.png)

## 题解

最优的算法是倍增判区间，合并时归并。

[这里](https://www.acwing.com/solution/content/15458/)有篇非常好的题解，搬来借鉴一下。

### 1(贪心 + 二分) O(n2log⁡n)

首先，根据校验值的定义，要快速求出校验值，首先想到的办法肯定是爆搜贪心。

结论：将 S排序，每次取到 S 中的最大值和最小值，最后计算出来的结果即为 S 的校验值

贪心证明：

![image-20210514191800625](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210514191800625.png)

时间复杂度

![image-20210514191834975](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210514191834975.png)

![image-20210514191849120](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210514191849120.png)

![image-20210514191930658](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210514191930658.png)

![image-20210514191940767](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210514191940767.png)

C++ 代码

```c++
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 500005;

int n, m;
int ans;              // 存答案
ll T;                 // 题目中的 T
ll w[N], t[N];        // w 是输入的数组，t 是用于求校验值的数组

ll sq(ll x)           // 返回 x 的平方
{
    return x * x;
}

ll get(int l, int r)  // 求原数组区间 [l, r] 的校验值
{
    int k = 0;        // 要先把 w 的 [l, r] 这段复制到 t 中，用 k 记录 t 的长度。
    for (int i = l; i <= r; i ++ ) // 从 l 到 r 枚举一遍，将 w 数组复制到 t 数组中
        t[k ++ ] = w[i];
    sort(t, t + k);   // 将复制过来的数排序
    ll sum = 0;       // 存返回的校验值
    for (int i = 0; i < m && i < k; i ++ , k -- )
        sum += sq(t[i] - t[k - 1]); // 双指针，i 指向当前集合中剩余的最小数，k 指向当前集合中剩余的最大数
    return sum;
}

int main()
{
    int K;            // 测试数据组数
    cin >> K;
    while (K -- )     // 不写奇怪的 for 循环了qwq
    {
        cin >> n >> m >> T;
        for (int i = 0; i < n; i ++ ) cin >> w[i];
        ans = 0;      // 答案归零
        int start = 0;    // start 记录当前剩余的区间左端点
        while (start < n) // start < n 说明当前数组还有值，需要继续划分。结束时 start 应等于 n 
        {
            int l = start, r = n, mid; // 二分求出当前能划分的最长的区间
            while (l < r) // 二分板子
            {
                mid = l + r >> 1;
                if (get(start, mid) > T) r = mid;
                else    l = mid + 1;
            }
            start = r;    // 二分完后，r 即当前可划分的最长区间的下一个位置，将 start 制为 r。
            ans ++ ;      // 每次划分完一个区间，ans ++ 
        }
        printf("%d\n", ans);
    }
    return 0;
}
```

### 2(倍增) O(nlog2n)O(nlog2⁡n)

![image-20210514191958896](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210514191958896.png)
C++ 代码

```c++
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 500005;

int n, m;
int ans;
ll T;
ll w[N], t[N];

ll sq(ll x)
{
    return x * x;
}

ll get(int l, int r)  // 计算原数组左闭右开区间 [l, r) 的校验值
{
    int k = 0;
    for (int i = l; i < r; i ++ )
        t[k ++ ] = w[i];
    sort(t, t + k);
    ll sum = 0;
    for (int i = 0; i < m && i < k; i ++ , k -- )
        sum += sq(t[i] - t[k - 1]);
    return sum;
}

int main()
{
    int K;
    scanf("%d", &K);
    while (K -- )
    {
        scanf("%d %d %lld\n", &n, &m, &T); // 不用 scanf 的话，这么做有一个点会 TLE
        for (int i = 0; i < n; i ++ )
            scanf("%lld", &w[i]);
        ans = 0;
        int start = 0, end = 0;            // start 记录剩余区间开头节点，end 记录当前考虑区间的尾结点（左闭右开）
        while (end < n)
        {
            int len = 1;                   // len 初始化为 1
            while (len)                    // len 为 0 自动跳出
            {
                if (end + len <= n && get(start, end + len) <= T) // 如果说 len + end 还在 n 以内，且区间 [start, end + len) 的校验值不大于 T
                    end += len, len <<= 1; // 那么 end += len，len *= 2
                else    len >>= 1;         // 否则 len /= 2
            }
            start = end;                   // 让 start 指向当前区间末尾结点的下一个位置，由于区间是左闭右开的，所以直接指向 end 就可以了
            ans ++ ;                       // 每次循环都找到了一个区间，所以让 ans ++ 
        }
        printf("%d\n", ans);
    }
    return 0;
}
```

### 3(倍增 + 归并) O(nlog⁡n)

![image-20210514192015225](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210514192015225.png)
C++代码

```c++
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 500005;

int n, m;
int ans;
ll T;
ll w[N], t[N];
ll tmp[N];

ll sq(ll x)
{
    return x * x;
}

bool check(int l, int mid, int r)           // 判断区间 [l, r) 是否合法，并将 t 中的 [l, mid) 区间和 [mid, r) 区间合并到 tmp 中
{
    for (int i = mid; i < r; i ++ )         // 将 w 数组的 [l, r) 区间复制到 t 的 [l, r) 区间中
        t[i] = w[i];
    sort(t + mid, t + r);                   // 将 t 的 [mid, r) 排序
    int i = l, j = mid, k = 0;              // 双指针进行区间合并
    while (i != mid && j != r)              // 当 i 不到 mid 且 j 不到 r 时，执行循环
        if (t[i] < t[j])                    // 如果 t[i] 比 t[j] 小，那么将 t[i] 放入 tmp 中
            tmp[k ++ ] = t[i ++ ]; 
        else                                // 否则将 t[j] 放入 tmp 中
            tmp[k ++ ] = t[j ++ ];
    while (i != mid) tmp[k ++ ] = t[i ++ ]; // 处理剩下的元素
    while (j != r) tmp[k ++ ] = t[j ++ ];
    ll sum = 0;                             // 计算校验值
    for (i = 0; i < m && i < k; i ++ , k -- )
        sum += sq(tmp[i] - tmp[k - 1]);
    return sum <= T;                        // 返回当前区间 [l, r) 是否合法
}

int main()
{
    int K;
    scanf("%d", &K);
    while (K -- )
    {
        scanf("%d %d %lld\n", &n, &m, &T);
        for (int i = 0; i < n; i ++ )
            scanf("%lld", &w[i]);
        ans = 0;
        int len;
        int start = 0, end = 0;
        while (end < n)
        {
            len = 1;
            while (len)
            {
                if (end + len <= n && check(start, end, end + len)) // 如果 w 的 [start, end + len) 区间合法
                {
                    end += len, len <<= 1;
                    if (end >= n) break ;               // 一个小剪枝，如果 end >= n，那么直接跳出
                    for (int i = start; i < end; i ++ ) // 在 check 时，已经将 t 数组的 [start, end + len) 这段区间归并在 tmp 中了。现在只需要将 tmp 中的有序数组复制到 t 中即可
                        t[i] = tmp[i - start];          // 复制的时候注意下标变换，tmp 是从 0 开始存的，t 是从 start 开始存的
                }
                else    len >>= 1;
            }
            start = end;
            ans ++ ;
        }
        printf("%d\n", ans);
    }
    return 0;
}
```


