# Manacher马拉车

Manacher(马拉车)是一种处理**最长回文字符串**的O(n)算法。

Manacher(马拉车)在暴力的中心匹配上做了预处理同时对拓展进行加速，将复杂度压到O(N)。

参考：[民间博客:Manacher算法详解](https://www.cnblogs.com/cloudplankroader/p/10988844.html)

## 预处理

首先，这里的预处理指的是在每两个字符和首尾位置(首尾可不加，后续操作相应变化即可)加上一个无关的字符，那么此时所有回文串都会变成奇串。并且注意到有效字符和无关字符的位置奇偶性不同，那么无论匹配中心在何处，匹配字符奇偶性都是一样的，也就是说有效字符只会和有效字符匹配，无关字符只会和无关字符匹配，从而不影响匹配。

## 扩展

首先作几个定义。

- **回文半径 `r` 和回文直径 `d`** ：通过预处理将回文串处理成奇串，考虑长度 `len` (len为奇数)，定义回文半径 `r=len/2+1` (向上取整，包括中心)，回文直径 `d=len=r*2-1` 。
- **最右回文边界 `R`** ：考虑到扫描时从左向右，因此当前字符左边的情况应该是已处理的。每个中心向右扩展都会达到一个右边界，维护一个最右边界 `R` (显然单调增)。
- **回文中心 `C`** ：每个 `R` (最右边界)都是某个中心扩展而来的，维护 `C` 为当前 `R` 第一次更新的回文中心。此时在 `C` 左边就会有 `R` 的一个**对称点 `L`** 。
- **回文半径数组**：记录每个原字符每个字符对应的最长回文半径。
- **回文区域**：某个点的回文区域即以其为中心的回文串。

做完预处理后(初始化R和C为-1)扫描字符串，当扫描到位置 `i` 时与 `R` 作对比，考虑下面匹配情况：

- `i>R`
  - 以i为中心扩展匹配，同时维护C和R。==> `O(n)`
- `i<=R`
  - 考虑中心C，R和对称点L，i和对称点i'(i'=2*C-i)。作L关于i'的对称点L'，R关于i的对称点R'。容易发现i'的回文区域是已经处理过的，考虑对i和i'的回文区域情况判断。
    1. **i'的回文区域在[L,R]内**，此时i的回文区域也在[L,R]内且回文半径和**i'的相同**。 ==> `O(1)`

    2. **i'的回文区域左边界超过了L**，(因为L往左和R往右是一样的) 此时i的回文区域是[R',R]，**回文半径是[i~R]**。 ==> `O(1)`

    3. **i'的回文区域左边界正好是L**，此时i的回文区域右边界**至少是R**，考虑对其向外匹配，同时维护C和R。 ==> `O(n)`

总体上看R和i都只需要O(n)地扫，总的复杂度可视为是O(n)的。

```c++
/*
    回文子串最大长度：https://www.acwing.com/problem/content/141/
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), st''d::cout.tie(0)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f
typedef long long ll;
#define ull unsigned long long
//#define INF ~0ULL
#define mod 99993

int solve(string s)
{
    int res=1;
    string rs;
    if(s.size()<=1)
    {
        cout<<s<<'\n';
        return s.size();
    }
    int len=s.size()*2+1;   //manacher串长度
    string str;             //manacher
    vector<int>ans(len+1,0);//回文半径数组
    int R=-1,C=-1;          //初始化-1
    for(int i=0;i<len;i++)  //处理manacher
    {
        if(i&1)str+=s[i/2];
        else str+='#';
    }
    for(int i=0;i<len;i++)  //枚举中心i
    {
        //int ii=2*C-i      //i关于C对称点ii
        //先处理出最短的可能
        if(i>R) ans[i]=1;
        else ans[i]=min(R-i,ans[2*C-i]);
        //取完最小值后直接进行第三种情况的匹配 省去情况判断
        while(i+ans[i]<len && i-ans[i]>=0)
        {
            if(str[i+ans[i]]==str[i-ans[i]])ans[i]++;
            else break;
        }
        //维护C和R
        if(i+ans[i]>R)
        {
            R=i+ans[i];
            C=i;
        }
        // res=max(res,ans[i]);
        if(ans[i]>res)
        {
            res=ans[i];
            rs=s.substr(i/2-(res-1)/2,res-1);
        }
    }
    //cout<<rs<<'\n';
    return res-1;
}

int main()
{
#ifdef LOCAL
    freopen("E:\\ACMdream\\in.txt", "r", stdin);
    freopen("E:\\ACMdream\\out.txt", "w", stdout);
#endif
    IOS;
//==================================================
    int t=1;
    string s;
    while(cin>>s&&s!="END")
    {
        cout<<"Case "<<t++<<": ";
        cout<<solve(s)<<'\n';
    }
//==================================================
    return 0;
}
```
