# [AcWIng110.防嗮](https://www.acwing.com/problem/content/description/112/)

## 题意

![image-20210515095216077](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210515095216077.png)

## 题解

![image-20210515095249299](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210515095249299.png)

另一种证明

![image-20210515095328455](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210515095328455.png)

![image-20210515095339648](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210515095339648.png)

## 代码

```c++

using namespace std;
const int N=2626;
map<int,int>p;
struct C{
    int mi,ma;
}c[N];
vector<int>all;
bool cmp2(int a,int b){return a>b;}
bool cmp(C x,C y){return x.mi>y.mi;}
int main()
{
    int cc,l;
    int ans=0;
    cin>>cc>>l;
    for(int i=0;i<cc;i++)cin>>c[i].mi>>c[i].ma;
    for(int i=0;i<l;i++){
        int spe,cor;cin>>spe>>cor;
        if(p[spe]==0)all.push_back(spe);
        p[spe]+=cor;
    }
    sort(c,c+cc,cmp);
    sort(all.begin(),all.end(),cmp2);
    for(int i=0;i<cc;i++){
        for(auto j:all){
            if(j<=c[i].ma&&j>=c[i].mi&&p[j]>0){
                p[j]--;ans++;break;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
```

可以用上STL二分找。

```c++
using namespace std;
typedef pair<int,int> PII;
const int N = 2510;
int n, m;
PII cows[N];
int main()
{
    cin >> n >> m;
    map<int, int> spfs;
    for (int i = 0; i < n; i ++ ) cin >> cows[i].first >> cows[i].second;
    for (int i = 0; i < m; i ++ )
    {
        int spf, cover;
        cin >> spf >> cover;
        spfs[spf] += cover; // 注意这里要写 +=，因为数据中存在spf值相同的防晒霜
    }
    sort(cows, cows + n);
    int res = 0;
    spfs[0] = spfs[1001] = n;
    for (int i = n - 1; i >= 0; i -- )
    {
        auto spf = spfs.upper_bound(cows[i].second);
        spf --;
        if (spf->first >= cows[i].first)
        {
            res ++ ;
            if (--spf->second == 0)
                spfs.erase(spf);
        }
    }
    cout << res << endl;
    return 0;
}
```

