# lowbit运算

## 定义：

lowbit(n)定义为非负整数n在二进制下“**最低位的1及其后面的0**”组成的**二进制数**

## 实现：**lowbit(n)=n&(-n)**

一.假设最低位为1的位数为k（右往左数）

1.n取反：n=~n---------此时k位为0，1~（k-1）位为1。

2.令n=n+1：n=n+1---------因为进位，k位为1，1~（k-1）位为0，（k+1）~MAX位于原来相反。

3.lowbit(n)=n&(~n+1)=n&(-n).

即：**lowbit(n)=n&(-n)**

## GCC提供的内置函数：

```c++
int __builtin_ctz(unsigned int x)
int __builtin_ctz(unsigned long long x)
 //返回x二进制表示下最低位的1后面有几个0
    
int __bulitin_ctz(unsigned int x)
int __bulitin_ctz(unsigned long long x)
 //返回x二进制表示下有几位为1
```

