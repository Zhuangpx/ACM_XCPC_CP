<!--
 * @Autor: violet apricity (zpx)
 * @Date: 2021-09-05 15:37:25
 * @LastEditors: violet apricity (zpx)
 * @LastEditTime: 2021-09-07 19:58:35
 * @FilePath: \apricitye:\桌面\ACM\小技巧\c++函数小技巧.md
 * @Description: Violet && Apricity:/ The warmth of the sun in the winter /
-->

# 收录c++内置函数/STL小技巧

## 去重unique与删除erase的结合

普通的```unique```去重只是**不停地把后面不重复元素移动到前面来，也可以说是用不重复元素占领重复元素的位置。** 所以实际上它并没有把重复元素删除掉。结合上```erase```的话就可以做到**删除重复元素**。
利用```unique```对**左闭右开**区间```[l,r)```去重，返回的是**不含重复元素的最后一个元素的下一个元素**，从这里开始往后```erase```就可以把重复元素删去。
注意到unique第三个bool参数可以自定义相等，可做拓展。
示例代码:

```c++
//bool cmp(int x,int y){return x==y;}
vector<int>a;
sort(a.begin(),a.end());
//sort(a.begin(),a.end(),cmp);
a.erase(unique(a.begin(),a.end()),a.end());
```

## 部分排序partial_sort

通俗的讲，```partial_sort(l,m,r)```，即在```[l,r)```按某种排序寻找前```m-l```个元素排序完移动至```[l,m)```并且其他元素保存相对位置不变。这里```[l,r)```的限定保证寻找时不会越界。
与sort类似，可以自定义cmp比较函数。平均复杂度是```O(nlogm)```。
示例代码:

```c++
//bool cmp(int x,int y){return x>y;}
vector<int>a;
partial_sort(a.begin()+1,a.begin()+5,a.begin()+3);
//partial_sort(a.begin()+1,a.begin()+5,a.begin()+3,cmp);
/*
in:
(a:) 100 88 77 111 66 55 44 3 2 1 (size:10)
out:
100 66 77 88 111 55 44 3 2 1
//100 111 88 77 66 55 44 3 2 1
*/
```

## 元素定位nth_element

与```partial_sort```类似，```nth_element(l,n,r)```，对左闭右开区间```[l,r)```进行一个第n位元素的定位，此后```[l,n)```的元素小于第```n```位元素，```(n,r)```的元素大于第```n```位元素，定位出**第n大元素**。
注意到，左右的元素可能会被打乱。同理比较函数支持自定义。
复杂度上一般都是```O(n)```(少数情况会退化到```O(n^2)```)。

```c++
vector<int>a;
nth_element(a.begin(),a.begin()+1,a.begin()+5);
```

## 反向迭代rbegin,rend

字面意思，与```begin```，```end```对应的反向迭代。

## 多位最值min/max

取最值时元素个数大于2，例如```min({a,b,c})```，在c++11中编译器会视为```initializer_list```即**初始化列表(不是链表)**。

## 寻找最值max_element/min_element

寻找最值位置。

```c++
int a[4]={1,2,3,4};
cout<<min_element(a,a+4)-a<<'\n';
```

## 全排列prev_permutation/next_permutation

全遍历复杂度是```O(!n)```，单次最坏是```O(n)```。

## 128位(无符号)整数__(u)int128/__(u)int128_t

128位的整数，其中__int128_t是__int128的typedef定义版，差别并不大。
注意到它们**并未被c++/c官方所承认**，能否使用也是**取决于编译器**。
其次，它们的输入输出无法用cin/cout，需要自写函数。

```c++
inline __int128_t read()
{
    __int128_t x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x*=10;x+=ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void print(__int128_t x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
```

## 数字转字符串to_string

支持将任一种数字类型转成字符串。

```c++
string PI="pi is "+to_string(3.14159);
//PI:pi is 3.141590
```

## 关于vector的插入：push_back和emplace_back

## __gcd

c++11里内置的__gcd。注意到如果传入有0则返回另一个非0数。

## __lg

通俗的说，__lg(n)返回的是n二进制下最高位的位数，注意**位数从右往左从0数**。
注意到n为0时是未定义行为。复杂度大概是```O(1)```。

```c++
//12--1100  1--1
__lg(12)==3;__lg(1)==0;
```

## rotate旋转

```rotate(l,m,r)```，将区间```[l,r)```视为一个圆，区间```[l,m)```往后旋转，区间```(m,r)```往前旋转，结束之后原本第```m```位元素成为第一位元素。

```c++
vecrot<int>b={1,2,3,4,5,6};
rotate(b.begin(),b.begin()+2,b.begin()+4);
//b:3 4 1 2 5 6
```

## reverse翻转

```reverse(l,r)```把区间```[l,r)```翻转过来。

```c++
vector<int>a={1,2,3,4,5,6};
reverse(a.begin(),a.begin()+3);
//a:3 2 1 4 5 6
```

## __bulitin_popcount

求某个数二进制下1的个数。

```c++
int a=13;//1101
long b=14;//1110
long long c=15;//1111
int x=__builtin_popcount(a);//3
int y=__builtin_popcountl(b);//3
int z=__builtin_popcountll(c);//4
```

## 构造递增iota

`iota(l,r,val)`对区间`[l,r)`按`val`开始依次递增往后填充。

```c++
vector<int>a(5);
iota(a.begin(),a.end(),0);
//a:0 1 2 3 4
```
