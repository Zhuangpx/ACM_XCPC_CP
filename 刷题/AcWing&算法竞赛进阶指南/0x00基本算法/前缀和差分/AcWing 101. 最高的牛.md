# [AcWing 101. 最高的牛](https://www.acwing.com/problem/content/103/)

![image-20210420153501858](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210420153501858.png)

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
const int N=1e5+5;
map<pair<int,int>,bool>ex;
int c[10011],d[10011];
int main()
{
    //IOS
    int n,p,h,m;
    cin>>n>>p>>h>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        if(ex[make_pair(a,b)]==1)continue;
        ex[make_pair(a,b)]=1;
        d[a+1]--;d[b]++;
    }
    for(int i=1;i<=n;i++){
        c[i]=c[i-1]+d[i];
        cout<<c[i]+h<<'\n';
    }
    cout<<'\n';
    SYP
    r0
}
```

