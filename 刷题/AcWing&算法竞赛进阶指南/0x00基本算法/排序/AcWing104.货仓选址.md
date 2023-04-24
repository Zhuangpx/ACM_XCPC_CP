# [AcWing 104. 货仓选址](https://www.acwing.com/problem/content/106/)

中位数好题。

## 题意

给出商店总数n和每个的位置a[i]，找出一个货仓位置使其到所有商店距离总和最小。

## 题解

贪心一下，先对a小到大排序，假设现在在位置d，左边商店x家，右边商店y家，若x<y，即右边商店多，则每向右移动一单位距离和就会减少y-x，同理，若x>y即左边商店多，每向左移动一单位距离和减少x-y，因此当x=y时可得最优解，此时距离和最小。

如果n为奇数，那么选中间那个商店可以使得左右商店个数相等。

如果n为偶数，只要处于a[n/2]和a[n/2+1]之间的任何位置都有左右商店个数相等。

```c++
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
using namespace std;
const int N=200111;
int a[N];
int main()
{
    IOS
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    int t;
    if(n%2)t=a[n/2+1];
    else t=a[n/2];
    for(int i=1;i<=n;i++)ans+=abs(a[i]-t);
    cout<<ans<<'\n';
    return 0;
}
```

