# [糖果传递](https://www.acwing.com/problem/content/124/)

另一个说法是环形均分纸牌

# 题意

n个小朋友围成一圈，第i个小朋友有a[i]个糖果，每个小朋友可以向旁边的小朋友传递糖果，每颗糖果传递消耗费用1，要求求出最小费用使得所有小朋友糖果一样多。数据保证一定有解。

# 题解

手动将圈断成行，转换成均分纸牌的问题。之后分析断点，再转换成货仓选址的问题。

![image-20210508125503806](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210508125503806.png)

![image-20210508125529298](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210508125529298.png)

也有另一种证明：

首先假设一共有m个糖果，那么每个小朋友应该分到糖果aver=m/n。这就确定了末状态。

假设我们沿一个方向分糖果，设b[i]表示i->(i-1)传递。特殊地，b[1]表示1->n。那么答案就是ans=\sum_{i=1}^{n}\left | b[i] \right |  。	

那么就有a[i]-b[i]+b[i-1]=aver。设c[m]=\sum_{i=1}^{m}(a[i]-aver)，有：

- 第一个小朋友：a[1]-b[1]+b[2]=aver-------->b[2]=b[1]+aver-a[1]=b[1]-c[1]
- 第二个小朋友：a[2]-b[2]+b[3]=aver-------->b[3]=b[2]+aver-a[2]=b[1]+2*aver-a[1]-a[2]=b[1]-c[2]
- 。。。。。。。。。。。。。。。
- 第n个小朋友：a[n]-b[n]+b[1]=b[1]-c[n-1]

那么答案就是ans=|b[1]|+|b[1]-c[1]|+~+|b[1]-c[n-1]|，在数轴上|b[1]-c[i]|表示b[1]和c[i]的距离，那么问题转换成求某个点与若干个已知点的距离之和最小。也就是货仓选址问题。

```c++
#include<bits/stdc++.h>
#define lll long long
using namespace std;
lll read()
{
	lll x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*w;
}
lll n,ave,qwe,ans;
lll a[1000010],sum[1000010];
int main()
{
	n=read();
	for(lll i=1;i<=n;i++)a[i]=read(),qwe+=a[i];
	lll ave=qwe/n;
	for(int i=1;i<=n;i++) a[i]-=ave,sum[i]=sum[i-1]+a[i];
	sort(sum+1,sum+1+n);int cut=sum[(n+1)/2];
	for(int i=1;i<=n;i++) ans+=abs(sum[i]-cut);
	cout<<ans<<endl;
}
```

