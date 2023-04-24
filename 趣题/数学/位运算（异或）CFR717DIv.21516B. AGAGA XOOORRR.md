# 位运算（异或）[CFR717DIv.21516B. AGAGA XOOORRR](https://codeforces.com/contest/1516/problem/B)

这里考查异或的性质：

## x^y==z<----->y==x^z

## x^x=0

## 题意：

t组，每组n和n个数，现在可以选任意两个相邻的数取异或，其结果取代原本两个数。问是否可以通过若干次操作使之只剩下两个以上个相同的数。

## 题解：

首先考虑剩下几个数。

### 剩下两个：

上述提到的，x^x=0，所以若所有数^起来的结果为0，那么说明可以分成两个相同的数。

### 剩下三个：

设分别为a，b，c。

那么应该有a==b==c。

我们由上述知道：x^y==z<----->x==y^z

取一下异或前缀s[n]，设a=s[i]，b=s[j]，c=b[n]。则应该有：

```c++
s[i]==s[i]^s[j]//a==b
s[i]==s[j]^s[n]//a==c
```

### 剩下m（m>3）个：

分成4个以上都可以转化为2个或3个，如下：

#### 转化为两个：

比如4个：a==b==c==d，那么可以做操作：a==b  (c^d)

这里c==d所以c^d==0，

又x^0==x，

所以分成了：a   b    0

这里a^b==a^b^0，即ans==a^b^0==a^b。

那么就转化为两个了。

#### 转化为三个

比如五个：a==b==c==d==e，同样可以做操作：a==b==c  d^e

即：a==b==c 0

即：a==b==c

那么就转化为三个了。

所以本质上只有两个和三个的情况，那么问题就解决了。

## 贴代码：

```c++
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
int a[2020],b[2020];
int main()
{
    //IOS
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans^=a[i];
            b[i]=b[i-1]^a[i];
        }
        bool yes=0;
        if(ans==0){cout<<"YES\n";continue;}
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(b[i]==(b[i]^b[j])&&b[i]==(b[j]^b[n])){
                    yes=1;break;
                }
            }
            if(yes==1)break;
        }
        if(yes)cout<<"YES\n";
        else cout<<"NO\n";
    }
    SYP
    r0
}
```

