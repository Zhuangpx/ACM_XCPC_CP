# 106. 动态中位数

![image-20210511185239306](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210511185239306.png)

维护动态中位数的问题，可以建两个二叉堆，一个大根堆一个小根堆，输入时优先放进小根堆，出现小根堆的头小于大根堆的头就得交换，出现小根堆数量与大根堆数量之差大于1就得将小根堆的头放进大根堆里，这样子小根堆的头始终为中位数。

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
#include<iomanip>
#include<queue>

#define STD using namespace std;
#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f3f3f3f
#define r0 return 0;
#define SYP system("pause");
#define endl '\n'


int main()
{
    //IOS
    int t;std::cin>>t;
    while(t--){
        std::priority_queue<int,std::vector<int>,std::greater<int>>qs;
        std::priority_queue<int>qb;
        int no,n;
        std::cin>>no>>n;
        std::cout<<no<<' '<<(n+1)/2<<'\n';
        int cnt=0;
        for(int i=1;i<=n;i++){
            int d;std::cin>>d;
            qs.push(d);
            if(qb.size()&&qs.top()<qb.top()){
                int a=qb.top(),b=qs.top();
                qb.pop(),qs.pop();
                qb.push(b),qs.push(a);
            }
            if(qs.size()-qb.size()>1){
                qb.push(qs.top());
                qs.pop();
            }
            if(i&1){
                cnt++;
                std::cout<<qs.top();
                if(cnt%10)std::cout<<' ';
                else std::cout<<'\n';
            }
        }
        if(cnt%10)std::cout<<'\n';
    }
    //SYP
    return 0;
}
```

