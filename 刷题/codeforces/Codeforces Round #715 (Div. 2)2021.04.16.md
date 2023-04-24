# [Codeforces Round #715 (Div. 2)2021.04.16](https://codeforces.com/contest/1509)
闲话：这场直接迟到了半小时，不过前两道题切的很快，半小时直接两题，挺舒服。不过c很可惜。我读完题觉得是区间dp，隐约记得寒假见过一道区间dp的题，但是时间不够加上不熟练，没写出来。赛后看了一眼群里讨论发现几乎就板子题，真是太可惜了。不过没关系，借此再熟悉一手（一点点）区间dp。
# [A. Average Height](https://codeforces.com/contest/1509/problem/A)
## 题意：
t组样例，每组给一个n和长为n的序列，要求对其重新排列，使得满足**相邻两项和除以2为整数**这样的数的对数最大化。
## 题解：
要想满足两项之和除以2为整数，也就是和为偶数，那么它们的奇偶性应该相同，于是就很简单了，把奇数排在一起，偶数排在一起。
太签到了，读完题就切。
```javascript
        // violet apricity
// Do all I can do.Do good to be good.

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<sstream>

#define STD using namespace std;
#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f
#define r0 return 0;
#define SYP system("pause");
#define endl '\n'
int main()
{
    IOS
    int t;std::cin>>t;
    while(t--){
        int n;std::cin>>n;
        std::vector<int>x,y;
        while(n--){
            int d;std::cin>>d;
            if(d%2==1)x.push_back(d);
            else if(d%2==0)y.push_back(d);
        }
        for(auto i:x)std::cout<<i<<' ';
        for(auto i:y)std::cout<<i<<' ';
        std::cout<<'\n';
    }
    //SYP
    return 0;
}
```
# [B. TMT Document](https://codeforces.com/contest/1509/problem/B)
## 题意：
t组样例，每组给一个n和长为n且只包含‘T’和‘M’的字符串s。将s划分为若干个不相交的子序列且包含该字符串所有的字符，判断是否有某种方案，使每个子序列均为TMT。
## 题解：
字符串匹配问题（我觉得是），这里子序列可以跨着分，但是对于每个子序列必须是TMT，那么必须是中间一个M两边各一个T，稍微想一下就发现了，对于每一个M，它的前面和后面都必须有个T和它匹配。那么我们可以从头遍历s，记录对应字符的数量，如果T的数量小于M的数量，那么说明有某个M前面没有T来和它匹配。同样的，再从尾遍历判断每个M后面是否有T和它匹配。
最后因为每个字符都要用到，所以数量上应该满足T=2*M。（题目说了n是3的倍数，所以这一点不用判断）
依旧是没什么算法的简单思维题。
```javascript
        // violet apricity
// Do all I can do.Do good to be good.

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<sstream>

#define STD using namespace std;
#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f
#define r0 return 0;
#define SYP system("pause");
#define endl '\n'
STD
int main()
{
    IOS
    string s;
    int t;cin>>t;
    while(t--){
        int len;
        cin>>len;
        cin>>s;
        int m=0,t=0;
        bool flag=1;
        for(int i=0;i<len;i++){
            if(s[i]=='T')t++;
            else if(s[i]=='M')m++;
            if(m>t){flag=0;break;}
        }
        int mm=0,tt=0;
        for(int i=len-1;i>=0;i--){
            if(s[i]=='T')tt++;
            else if(s[i]=='M')mm++;
            if(mm>tt){flag=0;break;}
        }
        if(t!=2*m||tt!=2*mm)flag=0;
        if(flag==0)cout<<"NO\n";
        else cout<<"YES\n";
    }
   // SYP
    return 0;
}
```
# [C. The Sports Festival](https://codeforces.com/contest/1509/problem/C)
## 题意：
给出一个n和长为n的序列a，对其重排列，使d[1]+d[2]+~d[n]最小化。
其中d[i]=max(a[1],a[2], ~, a[i])-min(a[1],a[2], ~ a[i])。
## 题解：
一道区间dp题。
首先要把序列从小到大sort一下。
假设现在有：a[1]<=a[2]<=a[3]<=a[4]<=a[5]，n=5；
首先我们来解释一下方案的选择：我们先选第一项，假设现在选a[3]，则max=min，d[1]=0；
再来选第二项和第三项，我们来对比一下选a[4],a[5]和选a[5],a[4]的情况：
1.d[2]+d[3]=(a[4]-a[3])+(a[5]-a[3])=a[3]+a[4]-2* a[3]
2.d[2]+d[3]=(a[5]-a[3])+(a[5]-a[3])=2* a[5]-2* a[3]
很明显上面是要比下面的小的，所以我们选择的时候依次往旁边推，这样子比跨过一个数要小。
更普遍的解释是：要使max-min小，即让max和min尽量相近，那么我们可以在中间选区间然后一次往两边判断加上左边的数还是右边的数作为新区间，且要让最大的和最小的出现在序列的极端，具体实现我们可以dp一下。
状态转移方程为：
```cpp
dp[l][r]=a[r]-a[l]+min(dp[l+1][r],dp[l][r+1]);
//区间[l,r]下的d和最小值
```
我们知道区间dp是把两个区间的信息整合成一个大区间的信息，这里每次只增加一个数，所以是一个区间左边加上一个包含一个数的区间或者右边加上一个包含一个数的区间。
假设我们现在已经选择了一个处于中间的区间[l,r]，该区间贡献值为x（小的那个区间），新区间贡献为y（大的那个区间），有以下两种方案：
选左边小的：y=x+a[r]-a[l-1]；
选右边大的：y=x+a[r+1]-a[l]；
比较以下哪种方案小就选择它。然后更新一下继续往下选。
上述是大往小递推解释，实现的时候为了方便我们从从小往大的方向记忆化枚举，下面在代码中解释：
```cpp
        // violet apricity
// Do all I can do.Do good to be good.

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<sstream>

#define STD using namespace std;
#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f
#define r0 return 0;
#define SYP system("pause");
#define endl '\n'

const int N=2021;
ll a[N],dp[N][N];
STD
int main()
{
    //IOS
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++)//这里是枚举当前区间的长度，因为长为1的区间只有一个数字，它的贡献为0，所以可以不用枚举
        for(ll j=1;j+i-1<=n;j++){//这里是枚举所有长为i的区间，下面内容对每个区间记忆化dp
            ll l=j,r=j+i-1;//这样子写方便理解，分别为左右端点
            dp[l][r]=min(dp[l][r-1],dp[l+1][r])+a[r]-a[l];
            //当前情况转移来的原来两种情况取最小 加上当前情况多出来的贡献
    }
    cout<<dp[1][n]<<'\n';//最后答案为区间[1,n]的贡献
    // SYP
    return 0;
}
```
好了依旧是ABC场，没看的就没必要写了，下次争取切3读4。

