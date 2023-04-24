<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-21 22:38:48
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-10-21 22:44:09
 * @FilePath: \apricitye:\桌面\ACM\小技巧\多行RawString.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->

# 多行RawString

形如 `cout<<R"()"` 脚本或图形直接往括号里丢。

如下：

```c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<R"(        *
       ***
      *****
     *******
    *********
     *******
      *****
       ***
        *)";
    cout<<'\n';
    system("pause");
    return 0;
}
/*
        *
       ***
      *****
     *******
    *********
     *******
      *****
       ***
        *
*/
```
