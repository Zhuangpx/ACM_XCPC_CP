# Educational Codeforces Round 107 (Rated for Div. 2)
链接：[Educational Codeforces Round 107 (Rated for Div. 2)](https://codeforces.com/contest/1511).
闲话：这场打的时候室友在打游戏，加上当时有好几个作业没写，还迟到了十几分钟，心里慌得很想快点切几题去补作业。没想到bc题憋到嘴边出不来，那种要差一点就写出来的感觉可真难受，看到题目想了一会这次还以为能切3题了，没想到还是停在A，依旧是十分钟过A一小时罚坐。所以说再提醒自己一句：**心态很重要！**
# A. Review Site（思维+贪心）
链接：[A. Review Site](https://codeforces.com/contest/1511/problem/A)
题意：t组样例，每组样例输入n和n个整数，该整数为1或2或3。
题目意思是有两个服务器和n个观众评价电影，每个观众有个代号即上述1~3的整数。当代号：
为1时：选择某个服务器，给它点赞。
为2时：选择某个服务器，给它点踩。
为3时：选择某个服务器，若踩大于赞则点踩，否则点赞。
其中服务器的选择由你决定，输出点赞最大值。
题解：签到，1和3就能点赞。
为什么呢？因为你可以把2都放到一边，1放到另一边，3也放到1这一边，那么3进入时只要有1进入过就能点赞，这样子能使3成为点赞的次数最大。此时能使最多人都点赞。
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
    //IOS
    ll t,m;
    cin >> t;
    while (t--) {
        ll ans = 0;
        cin >> m;
        while(m--){
            ll n;
            cin >> n;
            if (n == 1 || n == 3)
                ans++;
        }
        cout << ans << endl;
    }
    //SYP
    return 0;
}
```
# B. GCD Length（构造+数学）
链接：[B. GCD Length](https://codeforces.com/contest/1511/problem/B)
题意：t组样例，每组输入a，b，c求三个十进制数x，y，z满足：
1.x位数为a
2.y位数为b
3.z位数为c
4.gcd(x,y)=z
输出x和y。
题解：构造题。此题做法有很多，因为答案也有很多种，这里举两种。
一种是干脆只用0和1来构造，另一种下面给出。
我们知道，要枚举x和y是不可能的，那么我们可以从z出发往x和y构造，又因为gcd(x,y)=z，所以可以确定一下z，假设z=tc=10^(c-1)，那么有x=t*tc,y=k*tc，我们只要求出t和k就可以了。这里我们重新设下变量t=x,k=y。
由于gcd的关系，x和y都应该是质数且x!=y（若x=y则gcd(x,y)=x=y）。
那么就好办了，找到x和y的下界，然后判断一下是否为质数，不为质数就+1，并且不能相等。
接下来就得解决一下下界寻找的问题了。我们知道10 ^ (a-1)<=x*tc，而tc=10 ^ (c-1)，那么x>=10^(a-c)，下界就是10 ^ (a-c)。问题就迎刃而解啦。
下面贴代码吧：
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

ll qpow(ll x, ll y) { ll ans = 1; for (; y > 0; y >>= 1) { if (y & 1)ans *= x; x *= x; }return ans; }
bool isprime(ll x)
{
    if(x==2)return 1;
    if(x%2==0||x<=1)return 0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return 0;
    }
    return 1;
}
int main()
{
    IOS
    int t;std::cin>>t;
    while(t--){
    int a,b,c;
    std::cin>>a>>b>>c;
    ll tc=qpow(10,c-1);
    ll x=qpow(10,a-c),y=qpow(10,b-c);
    while(!isprime(x))++x;
    while(x==y||!isprime(y))++y;
    std::cout<<x*tc<<' '<<y*tc<<'\n';
    }
    SYP
    return 0;
}
```
这题很妙的，比赛的时候因为比较急躁没做出来，后来上英语课的时候分析了一下得出答案来。不得不感慨秒的很啊！。
# C. Yet Another Card Deck
链接：[C. Yet Another Card Deck](https://codeforces.com/contest/1511/problem/C)
题意：给出一个长为n的序列，进行q次询问，每次询问输入整数m找到最靠前的m，输出它的位置并将它提到序列最前方。
样例如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210415195605969.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
题解：这题比赛的时候放着b不管硬怼，结果就到快要出答案的地方过不了。其实也不是很难得题，稍微想一想就出答案得了。
这里给出两种解法。
## 解法一
在输入时记录下每个数第一次出现的位置，因为我们知道每次询问会把那个数字提前，那么与它相同且在它后面得数字永远也用不到，所以没必要存下来。在输出答案时直接输出，然后将位置在次数前面的数位置全部加一，之后把该数位置改为1就可以了。很简单，比赛的时候也是这么想的，但是心急出了bug没实现出来。
这个解法可行在于输入的数字范围很小，所以可以遍历找出每个数的位置关系然后进行修改，所以说**题目的数据范围很重要**。
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



int a[55];
int main()
{
    //IOS
    int n,q;
    std::cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;std::cin>>x;
        if(a[x]==0)a[x]=i;
    }
    while(q--){
        int x;std::cin>>x;std::cout<<a[x]<<' ';
        for(int i=0;i<=50;i++){
            if(a[i]!=0&&a[i]<a[x])a[i]++;
        }
        a[x]=1;
    }
    std::cout<<'\n';
    //SYP
    return 0;
}
```
## 解法二
在一篇博客上看到的，贴下[原文](https://www.cnblogs.com/2aptx4869/p/14652615.html)。
原文是这样子讲的：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210415201202361.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MDI4MTg2OQ==,size_16,color_FFFFFF,t_70)
再往下比赛的时候没看，所以就不写啦。
开始感受到打cf的快感了，继续加油，先定个小目标，每场切个abc。
