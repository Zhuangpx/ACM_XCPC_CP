<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-18 12:03:14
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2023-04-07 23:37:17
 * @FilePath: \apricitye:\桌面\ACM\算法Algorithm\字符串\KMP\KMP.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->
# KMP

视频：<https://www.bilibili.com/video/BV1CY4y14751>

## next数组

求最长的 后缀==前缀 部分，即next数组。

## 板子

```c++
struct KMP {
    int len_p, len_s;       //  k & ori
    string str_p, str_s;    //  [1,len]
    vector<int> nxt, kp;    //  suf == pre
    KMP(int p_n, int s_n, string p, string s) {
        len_p = p_n+2, len_s = s_n+2;
        str_p = p, str_s = s;
        nxt.resize(len_p+2, 0);
        kp.resize(len_s+2, 0);
    }
    void kmp_next() {
        int id = 0;
        nxt[1] = 0;
        for(int i=2;i<=len_p;i++) {
            while(id>0 && str_p[id+1]!=str_p[i]) id = nxt[id];
            if(str_p[id+1] == str_p[i]) id++;
            nxt[i] = id;
        }
    }
    void kmp_mach() {
        int id = 0;
        for(int i=1;i<=len_s;i++) {
            while(id==len_p || (id>0 && str_p[id+1]!=str_s[i])) id = nxt[id];
            if(str_p[id+1] == str_s[i]) id++;
            kp[i] = id;
        }
    }
};
```
