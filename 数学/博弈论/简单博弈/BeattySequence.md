<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-18 19:47:16
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-10-19 01:09:53
 * @FilePath: \apricitye:\桌面\ACM\数学\博弈论\简单博弈\BeattySequence.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->

# BeattySequence(贝亚蒂定理)

![Beatty定理](./assets/photos/BeattySequence.png)

## 证明

先证明第一项，集合无交集。此处使用反证法。

首先对于无理数 $p,q$ ，$[n*p]$ 表示向下取整，容易知道 $p>1,q>1$ ，因此 $[n*q]$ 跨度大于 $1$ ，向下取整时不会有重复元素。

假设存在公共元素 $k\in P,k\in Q$ ，即 $[p*m]=[q*n]=k$ 。

那么就有 $k<m*p<k+1,k<n*q<k+1$ ，即 $\frac{k}{m}<p<\frac{k+1}{m}$ ，即 $\frac{m}{k+1}<\frac{1}{p}<\frac{m}{k}$ ，同理有 $\frac{n}{k+1}<\frac{1}{q}<\frac{n}{k}$ 。

把两个式子相加得 $\frac{m}{k+1}+\frac{n}{k+1}<1=\frac{1}{p}+\frac{1}{q}=1<\frac{m}{k}+\frac{n}{k}$ 即 $k<m+n<k+1$ 。这说明 $m+n$ 是个无理数，与前提 $n,m$ 矛盾，证毕。

再证明第二项，同样使用反证法。

假设 `[p*m]>k && [p*(m-1)]<k` ，那么就有 `[p*m]>=k+1 && [p*(m-1)]<=k-1` ，进而 `p*m>=k+1 && p*(m-1)<=k` 这里的等号显然不可取，于是我们可以得到 `p*m-1>k>p*(m-1)` 。同样地取 `q*n-1>k>q*(n-1)` 。

于是有 `n+m-1 = n+m-(1/q+1/p) > m-p/1 + n-1/q > k = k/m+k/n = k > m-1 + n-1 = m+n-2` 。也就是说 `n+m+1>k>m+n-2` 。因为三者都是正整数，显然不成立，矛盾，证毕。

## 应用

此定理可用于**威佐夫博弈的通项公式**证明。
