# 线性DP

线性动态规划，是较常见的一类动态规划问题，其是在**线性结构**上进行状态转移，这类问题不像背包问题、区间DP等有固定的模板。

线性动态规划的目标函数为特定变量的线性函数，约束是这些变量的线性不等式或等式，目的是求目标函数的最大值或最小值。

因此，除了少量问题（如：LIS、LCS、LCIS等）有固定的模板外，大部分都要根据实际问题来推导得出答案。

个人认为这种DP相比于其它已经有一定套路的dp反而是最难的，可以是一眼看出结果，也可以是惊呼不可思议。它更加考验思维和创造性，并且也是需要训练出手感和思维的。

下面谈谈经典的几种线性dp问题，以此作为理解。

参考文章：[线性dp题单](https://blog.csdn.net/u011815404/article/details/81870275)

## 序列问题

### LIS

LIS 问题（Longest Increasing Subsequence），最长上升子序列，其一般为求最长下降子序列或是最长上升子序列。

问题可以是长度或具体序列，并且可以衍生到最长不上升子序列和最长不下降子序列，实际上是同理。

转移方程：

```c++
dp[i]=max(dp[j]+1),0<=j<i&&a[j]<a[i]
```

简单模板：

```c++
for(int i=2;i<n;i++){
    int num=0;
    for(int j=i-1;j>=1;j--){
        if(a[i]>a[j])num=max(num,dp[j]);
    }
    d[i]=num+1;
}
```



### LCS

LCS问题（Longest Common Subsequence），最长公共子序列。

转移方程：

![C[i,j]=\left\{\begin{matrix}0, &i=0|j=0 \\ C[i-1,j-1]+1,&i,j>0,x_i=y_j \\ max\{C[i,j-1],C[i-1,j]\},&i,j>0,x_i \neq y_j \end{matrix}\right.](https://private.codecogs.com/gif.latex?C%5Bi%2Cj%5D%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D0%2C%20%26i%3D0%7Cj%3D0%20%5C%5C%20C%5Bi-1%2Cj-1%5D&plus;1%2C%26i%2Cj%3E0%2Cx_i%3Dy_j%20%5C%5C%20max%5C%7BC%5Bi%2Cj-1%5D%2CC%5Bi-1%2Cj%5D%5C%7D%2C%26i%2Cj%3E0%2Cx_i%20%5Cneq%20y_j%20%5Cend%7Bmatrix%7D%5Cright.)

简单模板：

```c++
char s[MAX],t[MAX];  
scanf("%s%s",s,t);  
int x=strlen(s),y=strlen(t);  
for(i=0;i<x;i++)  
{  
    for(j=0;j<y;j++)  
    {
        if(s[i]==t[j])  
            dp[i][j]=dp[i-1][j-1]+1;  
        else  
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);  
    }  
    printf("%d\n",dp[i][j]);              
}
```

 

### LCIS

LCIS问题（Longest Common Increasing Subsequence），最长公共上升子序列。顾名思义，由以上两种问题结合而成。

转移方程：

![\left\{\begin{matrix} dp[i][j] = dp[i-1][j],&a[i] \neq b[j] \\ dp[i][j] = max(dp[i-1][k]+1) ,&1 \leq k \leq j-1,a[i] =b[j], b[j] > b[k] \end{matrix}\right.](https://private.codecogs.com/gif.latex?%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20dp%5Bi%5D%5Bj%5D%20%3D%20dp%5Bi-1%5D%5Bj%5D%2C%26a%5Bi%5D%20%5Cneq%20b%5Bj%5D%20%5C%5C%20dp%5Bi%5D%5Bj%5D%20%3D%20max%28dp%5Bi-1%5D%5Bk%5D&plus;1%29%20%2C%261%20%5Cleq%20k%20%5Cleq%20j-1%2Ca%5Bi%5D%20%3Db%5Bj%5D%2C%20b%5Bj%5D%20%3E%20b%5Bk%5D%20%5Cend%7Bmatrix%7D%5Cright.)

其中用 F[i,j] 表示 A[1~j] 与 B[1~j] 可以构成的以 B[j] 为结尾的 LCIS 的长度。

简单模板：

```c++
for (int i=1;i<=n;++i)
{
    int val=0;//val是决策集合S(i,j)中f[i-1][k]的最大值 
    for(int j=1;j<=m;++j)
    {
        //原来的k循环+判断+状态转移 
 
        if (a[i]==b[j]) 
            f[i][j]=val+1;
        else 
            f[i][j]=f[i-1][j];
 
        if (b[j]<a[i]) 
            val=max(val,f[i-1][j]);
 
        //j即将增大为j+1,检查j能否进入新的决策集合 
    }
}
```

### 转化

诸如上面的LIS，LCS都可以相互转化。

## 字符串编辑问题

**编辑距离**是针对二个[字符串](https://www.hk.jwchfzu.top/baike-字符串)（例如英文字）的差异程度的量化量测，量测方式是看至少需要多少次的处理才能将一个字符串变成另一个字符串。编辑距离可以用在[自然语言处理](https://www.hk.jwchfzu.top/baike-自然语言处理)中，例如[拼写检查](https://www.hk.jwchfzu.top/baike-拼寫檢查)可以根据一个拼错的字和其他正确的字的编辑距离，判断哪一个（或哪几个）是比较可能的字。[DNA](https://www.hk.jwchfzu.top/baike-去氧核糖核酸)也可以视为用A、C、G和T组成的字符串，因此编辑距离也用在[生物信息学](https://www.hk.jwchfzu.top/baike-生物信息学)中，判断二个DNA的类似程度。[Unix](https://www.hk.jwchfzu.top/baike-Unix) 下的 [diff](https://www.hk.jwchfzu.top/baike-Diff) 及 [patch](https://www.hk.jwchfzu.top/baike-Patch) 即是利用编辑距离来进行文本编辑对比的例子。

事实上，编译距离的定义并不唯一，一般来说指的是**莱文斯坦距离（Levenshtein）**。

其实也存在如**Jaro距离**和**汉明距离**，以及**Damerau-Levenshtein 距离**（Levenshtein的变种）等定义方式。

### Levenshtein 算法

 Levenshtein 距离，是俄国科学家 Vladimir Levenshtein 提出的概念，是指从一个字符串修改到另一个字符串时，编辑单个字符所需的最少次数，编辑单个字符允许的操作有：替换、插入、删除。

基于Levenshtein距离的**Levenshtein 算法**，又称编辑距离（Edit Distance）算法，用于求两个长度分别为 n、m的字符串 a、b 的 Levenshtein 距离，其是一个线性动态规划的算法，时空复杂度均为 O(nm)。

#### 状态转移方程

当两个字符串都为空串，那么编辑距离为0；
当其中一个字符串为空串时，那么编辑距离为另一个非空字符串的长度；
当两个字符串均为非空时(长度分别为 i 和 j )，取以下三种情况最小值即可：
1、长度分别为 i-1 和 j 的字符串的编辑距离已知，那么加1即可；
2、长度分别为 i 和 j-1 的字符串的编辑距离已知，那么加1即可；
3、长度分别为 i-1 和 j-1 的字符串的编辑距离已知，此时考虑两种情况，若第i个字符和第j个字符不同，那么 加1即可；如果不同，那么不需要加1。

![image-20200218144922087.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9zMy5jbi1ub3J0aHdlc3QtMS5hbWF6b25hd3MuY29tLmNuL3NoYW5ub24tYm9va3N0YWNrL3VwbG9hZHMvaW1hZ2VzL2dhbGxlcnkvMjAyMC0wMi9zY2FsZWQtMTY4MC0vaW1hZ2UtMjAyMDAyMTgxNDQ5MjIwODcucG5n?x-oss-process=image/format,png)

或者这样子

![image-20210714112019259](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210714112019259.png)

![lev_{a,b}(|a|,|b|)=\left\{\begin{matrix}max(i,j) & min(i,j)=0 \\ min\left\{\begin{matrix} lev_{a,b}(i-1,j)+1 \\ lev_{a,b}(i,j-1)+1 \\ lev_{a,b}(i-1,j-1)+(a_i \neq b_j?1:0) \end{matrix}\right. & otherwise \end{matrix}\right.](https://private.codecogs.com/gif.latex?lev_%7Ba%2Cb%7D%28%7Ca%7C%2C%7Cb%7C%29%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7Dmax%28i%2Cj%29%20%26%20min%28i%2Cj%29%3D0%20%5C%5C%20min%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20lev_%7Ba%2Cb%7D%28i-1%2Cj%29&plus;1%20%5C%5C%20lev_%7Ba%2Cb%7D%28i%2Cj-1%29&plus;1%20%5C%5C%20lev_%7Ba%2Cb%7D%28i-1%2Cj-1%29&plus;%28a_i%20%5Cneq%20b_j%3F1%3A0%29%20%5Cend%7Bmatrix%7D%5Cright.%20%26%20otherwise%20%5Cend%7Bmatrix%7D%5Cright.)



这里的lev[i,j]指a的前i个和b的前j个。

有了编辑距离，a和b的相似度定义为![sim_{a,b}=1-\frac{lev_{a,b}(|a|,|b|)}{max(|a|,|b|)}](https://private.codecogs.com/gif.latex?sim_%7Ba%2Cb%7D%3D1-%5Cfrac%7Blev_%7Ba%2Cb%7D%28%7Ca%7C%2C%7Cb%7C%29%7D%7Bmax%28%7Ca%7C%2C%7Cb%7C%29%7D)

#### 实现

伪代码

```c++
int LevenshteinDistcance(string str1[1..lenStr1], string str2[1..lenStr2])
    int d[0..lenStr1, 0..lenStr2]
    int i, j, cost
 
    for i = 0 to lenStr2
       d[i, 0] := i
    for j = 0 to lenStr1
       d[0, j] := j
 
    for i = 1 to lenStr2
        for j = 1 to lenStr1
            if str2[i] = str1[j] 
                cost := 0
            else 
                cost := 1
            d[i, j] := min(
                                d[i-1, j  ] + 1,     // 删除
                                d[i  , j-1] + 1,     // 插入
                                d[i-1, j-1] + cost   // 替換
                            )
 
   return d[lenStr1, lenStr2]
```



```c++

int dp[N][N];
int lenvenshtein_distance(string a,string b)
{
    int lena=a.length(),lenb=b.length();
    for(int i=0;i<=lena;i++)dp[i][0]=i;
    for(int j=0;j<=lenb;j++)dp[0][j]=j;
    for(int i=1;i<lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i-1]==b[j-1])dp[i][j]=d[i-1][j-1];
            else dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
        }
    }
    return dp[lena][lenb];
}
```

#### 优化

二维[lena+1,lenb+1]明显很占内存,我们发现计算当前项时依赖的只有前三项,因此容易想到优化空间.

这里使用两个一维2*[len+1]来解决问题(也可以离散化放一起)

这里选择开lena或者lenb都是同理,无非空间时间互相差异.

具体转移见图

初始化同上:

![image-20210518143551723](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210518143551723.png)

建两个数组:

![image-20210518143559455](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210518143559455.png)

状态转移:

![image-20210518143735497](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210518143735497.png)

数组转移:

![image-20210518144037823](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210518144037823.png)

最后答案放回v[len].

## 求和问题

求和问题,或者最大和问题.

### 最大子序列和

因为是序列,所以判断正负加入即可.

```c++
for(int i=2;i<=n;i++)
{
    if(dp[i-1]>=0)
        dp[i]=dp[i-1]+a[i];
    else
        dp[i]=a[i];
}
```

### 最大连续序列和/子串和

要求是连续的，也称为最大子段和。

#### 暴力枚举 O(n^3)+前缀和优化 O(n^2)

显然我们可以O(n^3)枚举起点终点，计算子序列和,计算时可以使用前缀和减少一层,从而压至O(n^2).

#### 分治 O(n log n)

还可以采用分治法压至O(n log n)

#### DP O(n)

DP来解十分简单，dp[i]表示a[i]作为末尾的最大连续子序列和，那么只要比较a[i]和a[i]接上a[i-1]即可，这里接上a[i-1]指的是前面还有别的元素，而因为上一位是a[i-1]并且dp[i-1]表示以a[i-1]结尾的状态，也即接上a[i-1]的状态，因此对于a[i]的两个转移就确定了.

至于答案的话就是取每个a[i]结尾的dp权值中最大的一个.

```c++
dp[i]=max(a[i],dp[i-1]+a[i])
OPS:dp[0]=a[0]
```

我们换一种思维方式，依旧是dp[i]表示以a[i]结尾的状态,对于当前a[i]有两种选择方法，一种是自己单独作为子序列，一种是和之前元素拼接，第二种状态必须加上以a[i-1]结尾的状态，因此dp[i-1]表示的就是之前元素拼接的最佳状态，如果dp[i-1]大于0那么肯定选后者,如果小于等于0那么之前元素对当前状态没有贡献,加上0代表没贡献，因为这里要求的是一整个序列最优子状态，可以一边操作一遍取答案.

这样子做的目的在于节省空间。

大体就是这样子:

```c++
转移:p[n] = max(0, dp[n-1]) + num[n]
答案:max(dp[m]) | m∈[1, N]
    num[0] = 0;
    cin>>N>>num[1~N];
    int ans = num[1];
    for(int i = 1; i <= N; i++) {
        if(num[i - 1] > 0) num[i] += num[i - 1];
        else num[i] += 0;
        if(num[i] > ans) ans = num[i];
    }
```

#### 前缀和再优化 O(n)

考虑我们之前O(N^2)的算法，将其再优化
我们已知一个sum数组，`sum[i]`表示第1个数到第i个数的和，于是`sum[j] - sum[i-1]`表示第i个数到第j个数的和。
那么，以第n个数为结尾的最大子数列和有什么特点？假设这个子数列的起点是m，于是结果为`sum[n] - sum[m-1]`。并且，`sum[m]`必然是`sum[1],sum[2]...sum[n-1]`中的最小值！这样，我们如果在维护计算sum数组的时候，同时维护之前的最小值， 那么答案也就出来了！为了节省内存，我们还是只用一个num数组。

将序列处理成前缀和，那么问题就类似于序列最优匹配了。

代码如下：

```c++
//计算数组前缀和，并在此过程中得到答案
    num[0] = 0;
    int ans = num[1], lmin = 0;
    for(int i = 1; i <= N; i++) {
        num[i] += num[i - 1];
        if(num[i] - lmin > ans)
            ans = num[i] - lmin;
        if(num[i] < lmin)
            lmin = num[i];
    }
```

#### 最优压缩

再分析我们发现sum数组也是不需要的，还可以把空间再压缩

```c++
scanf("%d%d", &N, &n); //读取数组长度和数列中的第一个数
    ans = s = n; //把ans初始化为数列中的的第一个数
    for(int i = 1; i < N; i++) {
        if(s < m) m = s;
        scanf("%d", &n);
        s += n;
        if(s - m > ans)
            ans = s - m;
    }
    printf("%d\n", ans);
```

### 最大子矩阵和

可以把上一个问题看成一维，这一个问题看成二维。

把多维分成多个一维来计算即可。

参考文章：[最大矩阵和](https://blog.csdn.net/beiyeqingteng/article/details/7056687)

小模版：

```c++
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        int temp;
        scanf("%d",&temp);//in
        a[i][j]=a[i-1][j]+t;//一维前缀和
    }
}
int ans=-INF;
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        int sum=0;
        for(int k=1;k<=m;k++){
            sum=sum+(a[j][k]-a[i-1][k]);
            if(sum<0) 
                sum=0;
            if(sum>ans) 
                ans=sum;
        }
    }
}
```

### 数字三角形

一个数字三角形，从顶点往下走，每次只能走到相邻点，到达某个目的点，要求某种路径使经过点的总和最大。

一点只能由两个点走过来，很容易能得到dp转移方程。

可以有多种推导方式。

参考文章：[数字三角形](https://www.cnblogs.com/huashanqingzhu/p/7326837.html)

```c++
dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1])
```

```c++

#include <stdio.h>
#define maxN 101
int N;
int D[maxN][maxN];      //D[i][j]表示第i行第 j 个数字。其中i、j从1开始算
int maxSum[maxN][maxN]; //maxSum[i][j]表示从D(i,j)到底边的各条路径中，最佳路径的数字之和。
//代码一：纯粹递归。当N达到100是绝对是超时的。因为复杂度是O(2^N)
int fun1(int i,int j)//返回从（i，j）到达最底层的最大路径之和
{
    if(i==N) return D[i][j];
    else
    {
        int x=fun1(i+1,j);
        int y=fun1(i+1,j+1);
        return D[i][j]+(x>y?x:y);
    }
}
//代码二：记忆型递归，避免重复计算。时间复杂度O(n*n)
int fun2(int i,int j)//返回从（i，j）到达最底层的最大路径之和
{
    if(maxSum[i][j]!=-1) return maxSum[i][j];

    if(i==N) maxSum[i][j]=D[i][j];
    else
    {
        int x=fun2(i+1,j);
        int y=fun2(i+1,j+1);
        maxSum[i][j]=D[i][j]+(x>y?x:y);
    }

    return maxSum[i][j];
}
//代码三：递归变递推
int fun3()
{
    int i,j;
    for(j=1;j<=N;j++) maxSum[N][j]=D[N][j];

    for(i=N-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            int max=(maxSum[i+1][j]>maxSum[i+1][j+1]?maxSum[i+1][j]:maxSum[i+1][j+1]);
            maxSum[i][j]=D[i][j]+max;
        }
    }
    return maxSum[1][1];
}
//代码四：递归变递推并在空间上做优化
int fun4()
{
    int i,j;

    for(i=N-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            int max=(D[i+1][j]>D[i+1][j+1]?D[i+1][j]:D[i+1][j+1]);
            D[i][j]=D[i][j]+max;
        }
    }
    return D[1][1];
}

int main(int argc, char *argv[])
{
    int i,j;
    freopen("001.in","r",stdin);
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=i;j++)
        {
            scanf("%d",&D[i][j]);
            maxSum[i][j]=-1;
        }
    }
    //printf("%d\n",fun1(1,1));
    //printf("%d\n",fun2(1,1));
    //printf("%d\n",fun3());
    printf("%d\n",fun4());
    return 0;
}

```



------------

-------待更新----------

---------

