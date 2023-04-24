# [Codeforces Round #716 (Div. 2)](https://codeforces.com/contest/1514)
闲话：这场是九点半开始的，九点上完课匆匆忙忙跑回宿舍收拾一下刚好赶上。记得上一次定了个小目标（过三题！），这一次还真让我达成了。虽说不是什么很有代表性的题，但好歹也是我第一次cf切三读四（虽然切完三题有剩时间但读一下D就走了并不打算写）。所以呢还是有一点小开心，总算是有点进步。不过还是不能骄傲自满，我和同阶段选手的差距还大着呢。所以得继续加油，再接再厉。
# [A. Perfectly Imperfect Array](https://codeforces.com/contest/1514/problem/A)（数学）
## 题意：
t组样例，每组给出n和n个数，判断是否存在一个**非空**子序列，其元素乘积**不是**一个完全**平方**数。
## 题解：
我们知道，对平方乘积有这样子的性质：

```cpp
a^2*b^2=(a*b)^2
```
所以说两个完全平方数的乘积也是完全平方数。这里要求一个子序列乘积不是完全平方数，那么也就是说存在一个数不是完全平方数。
于是我们预处理一下，然后边输入边判断就可以了。
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
#include<numeric>

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
const int N=1e4+5;
int a[102];
map<ll,ll>is;
void find()
{
    for(int i=1;i<1e2+2;i++){
        is[i*i]=1;
    }
}
int main()
{
    IOS
    int t;cin>>t;
    find();
    while(t--){
        int n;cin>>n;
        bool flag=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(is[a[i]]==0)flag=1;
        }
        if(flag==1)cout<<"YES\n";
        else if(flag==0)cout<<"NO\n";
    }
    //SYP
    r0
}
```
# [B. AND 0, Sum Big](https://codeforces.com/contest/1514/problem/B)
## 题意：
t组样例，每组给出两个整数n和k。要求一个长为n的数列，该数列满足下列条件：
 1. 所有数大小在[0,2^k-1]中间
 2. 所有数的AND（&）结果为0
 3. 所有数的和要最大化

求满足条件的数列的总数，结果对1e9+7取模。
## 题解：
我们先分析一下题目，对三个条件进行思考，发现：
 - 由数字范围可知，该数列里的数字为一个**k位二进制数**
 - 所有数&结果为0，那么**每一位都存在一个数在该位为0**
 - 要数的总和最大，那么**除了满足条件2，其它位均为1**

所以问题转化为，n个k位数，选k个位置为0，其它为1。
可以看成一个n行k列矩阵，每一列n个数选1个有n种选择，又有k列，所以是n^k。
因此结果为n^k。快速幂一下(也可以直接乘)就可以了。
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
#include<numeric>

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
const ll mod=1e9+7;
ll powermod(ll a,ll b,ll p)  //return a^b mod p
{
    ll temp = 1;
    while(b)
    {
        if(b & 0x01)
        {
            temp = (temp * (a%p)) % p;
        }
        a = ( (a%p) * (a%p) ) % p;
        b >>= 1;
    }
    return temp%p;
}
int main()
{
    IOS
    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        ll ans=1;
        ans*=powermod(n,k,mod);
        cout<<ans<<'\n';
    }
    //SYP
    r0
}
```
# [C. Product 1 Modulo N](https://codeforces.com/contest/1514/problem/C)
## 题意：
给一个总数n，找出一个序列满足：

 - 该数列为 [1,2,3,~~,n-1] 的子序列
 - 所有数乘积结果对n取模结果为1
 - 序列长度要最长

## 题解：
首先，1是肯定包含的。（为了使长度最大化）
其次，与n**不互质的数**（设为k）是不包含的。因为若k和n不互质，那么k * j与n也不互质，也就是说k*j%n!=1。用数学式子就是这样子：gcd(k mod n,n)=gcd(k ,n )!=1。（两个数不互质说明最小公倍数不为1）所以说我们要从小于n中选择k，k必须满足gcd(k,n)=1。
但是这样子还不够，我们将以上k乘积模n后得到一个数p，若p为1则满足题意，若p不为1则必须去掉一个数使结果为1，那么可以去掉p。
事实上，这个乘积模n必然是1或-1，当n有原根的时候为-1，此时去掉n-1就可以了。

另一种说法是[wilson定理的推广](https://www.ixueshu.com/h5/document/4d2c3204ec195da2bfd2f6d86a779153318947a18e7f9386.html)。
由于本人目前对数论研究不深，此题只能勉强做出结果来，至于证明实在无力。

我们可以在求出所有互质数之后乘积一下，结果取模不为1就把最后一个去掉。

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
#include<numeric>
#include<queue>

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
vector<ll>ans;
ll gcd(ll a,ll b)   //return a=gcd(a,b)
{
    ll temp;
    while(b){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main()
{
    IOS
    ll n;cin>>n;
    for(ll i=1;i<=n;i++){
        if(i==1)ans.push_back(i);
        else {
            if(gcd(i,n)==1)ans.push_back(i);
        }
    }
    ll d=1;
    for(ll i=0;i<ans.size();i++)d*=ans[i],d%=n;
    if(d!=1)ans.pop_back();
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i<<' ';
    cout<<'\n';
    //SYP
    r0
}
```
