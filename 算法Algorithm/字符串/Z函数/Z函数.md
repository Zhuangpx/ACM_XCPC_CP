<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-10-05 16:57:58
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-10-05 18:11:43
 * @FilePath: \apricitye:\桌面\ACM\算法Algorithm\字符串\Z函数\Z函数.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->

# Z函数

文章：<https://www.cnblogs.com/zhanghanLeo/p/16124263.html>

视频：<https://www.bilibili.com/video/BV1LK4y1X74N>

对于长为n的字符串s，假设下标从1开始。

定义 z[i] 表示 s 和 s[i,n] 的最长公共前缀（LCP）的长度，即为 z函数，并且有 z[1] 需要特定处理，一般是0或n 。

如果要求 t 和 s[i,n] 的LCP则是扩展。

## Z-Box

Z-Box，字符串的区间 [l,r] 满足 s[l,r] 是 s 的前缀，则为Z-Box。

对于位置 i ，维护这样的Z-Box，满足 [l,r] 包含 i ，并且 r 尽可能大。

## 板子

```c++
// s-func
void z_function(string s, int len_s, vector<int> &z, int fir=0)    //  Z-function   z[0]=fir(=0)
{
    z[0] = fir;
    for(int i=1,l=0,r=0; i<len_s; i++) {
        if(i>r) {
            while(i+z[i]<len_s && s[i+z[i]]==s[z[i]]) z[i]++;  //! different to ex-Z-func
            l=i, r=i+z[i]-1;
        }
        else if(z[i-l] < r-i+1) z[i] = z[i-l];  //! different to ex-Z-func
        else {
            z[i] = r-i+1;
            while(i+z[i]<len_s && s[i+z[i]]==s[z[i]]) z[i]++;  //! different to ex-Z-func
            l=i, r=i+z[i]-1;
        }
    }
}
// ex-z-func  t和s的后缀
void ex_z_function(string s, int len_s, string t, int len_t, vector<int> &exz, const vector<int>& z)    //  exZ-function z[i]=LCP(t, s[i..len])
{
    int id = 0;
    while(id < min(len_s, len_t) && s[id]==t[id]) id++;
    exz[0] = id;
    for(int i=1,l=0,r=0; i<len_s; i++) {
        if(i>r) {
            while(i+exz[i]<len_s && exz[i]<len_t && s[i+exz[i]]==t[exz[i]]) exz[i]++;  //! different to Z-func
            l=i, r=i+exz[i]-1;
        }
        else if(z[i-l] < r-i+1) exz[i] = z[i-l];  //! different to Z-func
        else {
            exz[i] = r-i+1;
            while(i+exz[i]<len_s && exz[i]<len_t && s[i+exz[i]]==t[exz[i]]) exz[i]++;  //! different to Z-func
            l=i, r=i+exz[i]-1;
        }
    }
}
```
