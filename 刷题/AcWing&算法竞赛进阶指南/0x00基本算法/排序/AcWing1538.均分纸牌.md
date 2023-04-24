# [AcWing1538均分纸牌](https://www.acwing.com/problem/content/1538/)

## 题意

先说泛型一点的：一排牌堆，第i堆有纸牌c[i]张，现可以对相邻牌堆继续纸牌转移，每张牌消耗费用1，求使得所有牌堆纸牌数相等的最小费用。

此题不同之处在于每次移动算费用1，于移动数量无关。

## 题解

### 先说第一种

首先我们可以确定目标纸牌数也就是纸牌平均数 aver=(a[1]+a[2]~+a[n])/n。

然后我们从左向右考虑将牌堆转移至aver张，从第一堆开始。

- 若a[1]<aver，从第二堆拿aver-a[1]张牌

- 若a[1]>aver，向第二堆拿a[1]-aver张牌

- 若a[1]=aver，不需改动。

  用同样方法往后推，即可得到答案。

推导过程借用下图。

![均分纸牌](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210505175103973.png)

```c++
#include<iostream>
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
using namespace std;
const int N=110;
int a[N];
int b[N];
int main()
{
    IOS
    int n;cin>>n;
    int all=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        all+=a[i];
    }
    int aver=all/n;
    int ans=0;
    for(int i=0;i<n;i++){
        if(i==0)b[i]=(a[i]-aver);
        else b[i]=b[i-1]+(a[i]-aver);
        ans+=abs(b[i]);
    }
    cout<<b[n-1]<<'\n';
    return 0;
}
```

### 再说此题

此题费用以移动次数来定，实际上是上述的简化版本，依旧是左往右，记录移动次数ans，每次移动之后要更新下一位的纸牌数。

```c++
#include<iostream>
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
using namespace std;
const int N=110;
int a[N];
int b[N];
int main()
{
    IOS
    int n;cin>>n;
    int all=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        all+=a[i];
    }
    int aver=all/n;
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]!=aver){
            ans++;
            a[i+1]+=(a[i]-aver);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
```

