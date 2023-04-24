<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-28 14:57:12
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-23 18:40:36
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Zhuangpx的ACM模板.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->
# Zhuangpx的ACM模板

# 目录

Zhuangpx的ACM模板

# 零.前导

- 我的自用火车头

```c++
        // Zhuangpx - violet apricity
        // Do all I can do.Do good to be good.
//#include<ext/rope>
//#include<conio.h>

#include<bits/stdc++.h>

#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f3f3f3f
#define r0 return 0;
#define SYP system("pause");
#define lowbit(x) ((x) & -(x))
//#define endl '\n'
using namespace std;
using namespace __gnu_cxx;

const ll mod=1e9+7;
const ll _mod=998244353;

ll gcd(ll a,ll b){ll d;while(b){d=b;b=a%b;a=d;} return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll _pow(ll a,ll b){ll d=1;while(b){if(b&1)d*=a; a*=a;b>>=1;} return d;}
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
/* a*x+b*y=gcd(a,b) */
void _exgcd(ll a,ll b,ll &g,ll &x,ll &y){if(!b){g=a;x=1;y=0;} else {_exgcd(b,a%b,g,y,x);y-=x*(a/b);}}
void _exgcd(int a,int b,int &g,int &x,int &y){if(!b){g=a;x=1;y=0;} else {_exgcd(b,a%b,g,y,x);y-=x*(a/b);}}
ll exgcd(ll a,ll b,ll &x,ll &y){if(!b){x=1;y=0;return a;} else {ll d=exgcd(b,a%b,y,x);y-=x*(a/b);return d;}}
int exgcd(int a,int b,int &x,int &y){if(!b){x=1;y=0;return a;} else {ll d=exgcd(b,a%b,y,x);y-=x*(a/b);return d;}}
/* 线性同余方程 a*x=b (mod m)  ( gcd(a,m)|b )  ex:方程组(中国剩余定理) x=a[i](mod m[i]) M=multi(m[i]) M[i]=M/m[i] x=sum(a[i]*M[i]*M`[i] ) */
inline ll getcongruence(ll a,ll b,ll m=mod){ ll x,y;ll d=exgcd(a,m,x,y); return x*(b/d)%m; }
/* 快速幂求逆元(模质数)  get x-inverse  (mod p)  (p-prime && x%p!0)*/
inline ll getinverse(ll x,ll p=mod) { return mpow(x,p-2,p); }
/* 线性逆元 */
ll inv[N];
void initinv(ll n,ll p=mod) { inv[1]=1; for(ll i=2;i<=n;i++){ inv[i]=(p-p/i)*inv[p%i]%p; } }

int rint()
{
    int _res=0,_flag=0;char _ch=getchar();
    if(_ch=='-')_flag=1;else if(_ch>='0'&&_ch<='9')_res=_ch-'0';
    while((_ch=getchar())>='0'&&_ch<='9')_res=_res*10+(_ch-'0');
    return _flag?-_res:_res;
}
ll rintl()
{
    ll _res=0,_flag=0;char _ch=getchar();
    if(_ch=='-')_flag=1;else if(_ch>='0'&&_ch<='9')_res=_ch-'0';
    while((_ch=getchar())>='0'&&_ch<='9')_res=_res*10+(_ch-'0');
    return _flag?-_res:_res;
}
void cint(int _x)
{
    if(_x<0){putchar('-');_x=-_x;}if(_x>=10)cint(_x/10);putchar(_x%10+'0');
}
void cint(ll _x)
{
    if(_x<0){putchar('-');_x=-_x;}if(_x>=10)cint(_x/10);putchar(_x%10+'0');
}

int stein(int a,int b)
{
    int k=1;
    while( (!(a&1)) && (!(b&1)) ){
        k<<=1; a>>=1; b>>=1;
    }
    //k=2^p
    while(!(a&1))a>>=1;
    while(!(b&1))b>>=1;
    if(a<b)a^=b, b^=a, a^=b; //swap
    while(a!=b){
        a-=b;
        if(a<b)a^=b, b^=a, a^=b; //swap
    }
    return k*a;
}

// int_128
inline __int128_t read(){ __int128_t x=0,f=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} while(ch>='0'&&ch<='9'){x*=10;x+=ch-'0';ch=getchar();} return x*f;}
inline void print(__int128_t x){if(x<0)putchar('-'),x=-x; if(x>9)print(x/10); putchar(x%10+'0');}

//=====================================================================

// Cal
const int _N=1e6+6;
ll jie[_N],tow[_N];
void init()
{
    jie[0]=1;
    for(int i=1;i<_N;i++)jie[i]=jie[i-1]*i%mod;
    tow[_N-1]=mpow(jie[_N-1],mod-2,mod);
    for(int i=_N-2;i>=0;i--) tow[i]=tow[i+1]*(i+1)%mod;
}
ll cal(ll n,ll m){if(m>n) return 0; return jie[n]*tow[m]%mod*tow[n-m]%mod; }

struct dsu {   //DSU
    vector<int> f;
    dsu(int n) :f(n) { iota(f.begin(), f.end(), 0); }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x > y)swap(x, y);
        f[y] = x;
    }
};

// pri + phi
ll pri[N],privis[N],pritot;  //getprimes
void getpri(ll n) //(pri)-allprime (privis)-ispri (pritot)-cntpri
{privis[2]=0;for(ll i=2;i<=n;i++){if(!privis[i])pri[++pritot]=i; for(ll j=1;j<=pritot&&pri[j]<=n/i;j++){privis[pri[j]*i]=1; if(i%pri[j]==0)break; } } }
ll phi[N];
void getphi(ll n)
{
    phi[1]=1;
    for(ll i=2;i<=n;i++){
        if(!privis[i]) {phi[i]=i-1; pri[pritot++]=i; }
        for(ll j=1;j<=pritot&&pri[j]<=n/i;j++){
            privis[i*pri[j]]=1;
            if(i%pri[j]) { phi[i*pri[j]]=phi[i]*(pri[j]-1); }
            else { phi[i*pri[j]]=phi[i]*pri[j]; break; }
        }
    }
}

//=====================================================================

#define pCase(t,d) cout<<"Case #"<<(t)<<": "<<(d)<<'\n'
#define pNO cout<<"NO\n"
#define pYES cout<<"YES\n"
#define pNo cout<<"No\n"
#define pYes cout<<"Yes\n"
#define pno cout<<"no\n"
#define pyes cout<<"yes\n"
#define pdebug(ans) cout<<"debug:"<<(ans)<<'\n'
#define pshow(x) cout<<" show:"<<(x)<<'\n'
#define p(ans) cout<<(ans)<<'\n'
#define pdec(t,ans) cout<<std::fixed<<std::setprecision(t)<<(ans)<<'\n'

//=====================================================================

inline void init(){
}

//=====================================================================

int main()
{
#ifdef LOCAL
    //ifstream cin("E:\\ACMdream\\in.txt");
    //ofstream cout("E:\\ACMdream\\out.txt");
    freopen("E:\\ACMdream\\in.txt","r",stdin);
    freopen("E:\\ACMdream\\out.txt","w",stdout);
    clock_t time1 = clock();
#endif
    IOS
    //======================================================================

    int T=1;
    // cin>>T;
    while(T--){
    }

    //======================================================================

#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif

    //SYP
    return 0;
}

/*
 *  ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
 *  │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
 *  └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
 *  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
 *  │~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │N L│ / │ * │ - │
 *  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
 *  │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
 *  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
 *  │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
 *  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
 *  │ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
 *  ├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
 *  │ Ctrl│    │Alt │         Space         │ Alt│    │    │Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←─┘│
 *  └─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
 */

```

- 快读快写

```c++

```

- c++骚操作总结

# 一.c++头文件与内置函数

- c++常用头文件汇总

```c++
#include <algorithm>　　　 //STL 通用算法
#include <bitset>　　　　　//STL 位集容器
#include <cctype>         //字符处理
#include <cerrno> 　　　　 //定义错误码
#include <cfloat>　　　　 //浮点数处理
#include <ciso646>         //对应各种运算符的宏
#include <climits> 　　　　//定义各种数据类型最值的常量
#include <clocale> 　　　　//定义本地化函数
#include <cmath> 　　　　　//定义数学函数
#include <complex>　　　　 //复数类
#include <csignal>         //信号机制支持
#include <csetjmp>         //异常处理支持
#include <cstdarg>         //不定参数列表支持
#include <cstddef>         //常用常量
#include <cstdio> 　　　　 //定义输入／输出函数
#include <cstdlib> 　　　　//定义杂项函数及内存分配函数
#include <cstring> 　　　　//字符串处理
#include <ctime> 　　　　　//定义关于时间的函数
#include <cwchar> 　　　　 //宽字符处理及输入／输出
#include <cwctype> 　　　　//宽字符分类
#include <deque>　　　　　 //STL 双端队列容器
#include <exception>　　　 //异常处理类
#include <fstream> 　　　 //文件输入／输出
#include <functional>　　　//STL 定义运算函数（代替运算符）
#include <limits> 　　　　 //定义各种数据类型最值常量
#include <list>　　　　　　//STL 线性列表容器
#include <locale>         //本地化特定信息
#include <map>　　　　　　 //STL 映射容器
#include <memory>         //STL通过分配器进行的内存分配
#include<new>            //动态内存分配
#include <numeric>         //STL常用的数字操作
#include <iomanip> 　　　 //参数化输入／输出
#include <ios>　　　　　　 //基本输入／输出支持
#include <iosfwd>　　　　　//输入／输出系统使用的前置声明
#include <iostream> 　　　//数据流输入／输出
#include <istream>　　　　 //基本输入流
#include <iterator>        //STL迭代器
#include <ostream>　　　　 //基本输出流
#include <queue>　　　　　 //STL 队列容器
#include <set>　　　　　　 //STL 集合容器
#include <sstream>　　　　 //基于字符串的流
#include <stack>　　　　　 //STL 堆栈容器
#include <stdexcept>　　　 //标准异常类
#include <streambuf>　　　 //底层输入／输出支持
#include <string>　　　　　//字符串类
#include <typeinfo>        //运行期间类型信息
#include <utility>　　　　 //STL 通用模板类
#include <valarray>        //对包含值的数组的操作
#include <vector>　　　　　//STL 动态数组容器
```

# 二.动态规划

## 背包

- 初始化

```c++
#define fINF -127  //fINF为负无穷
// 要求恰好装满背包
std::memset(f,fINF,sizeof(f)); //其他fINF
f[0]=0; //首位0
// 不需恰好装满
std::memset(f,0,sizeof(f));
```

- 01背包

```c++
// 一维滚动数组
const int N=1011;
const int M=N*N+1;
int V,n,v[N],w[N],f[M];
int main(){
    cin>>n>>V;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=V;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[V]<<'\n';
    return 0;
}
// 前缀和 常数优化
const int N=1011;
const int M=N*N+1;
int V,n,v[N],w[N],f[M],s[N];
int main(){
    cin>>n>>V;
    memset(f,0,sizeof f);s[0]=0;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i],s[i]=s[i-1]+v[i];
    for(int i=1;i<=n;i++){
        int d=max(v[i],V-s[n]-s[i]);
        for(int j=V;j>=d;j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
    cout<<f[V]<<'\n';
}
```

- 完全背包

```c++
// 一维滚动数组
const int N=1011;
const int M=N*N+2;
int V,n,v[N],w[N],f[M];
int main(){
    cin>>n>>V;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=V;j++)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[V]<<'\n';
    return 0;
}
```

- 多重背包

```c++
// 二进制优化 转为01背包
const int N=1111;
const int M=N*N+2;
int V,n,v[N],w[N],s[N],f[M];
int main(){
    cin>>n>>V;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i]>>s[i];
    for(int i=1;i<=n;i++){
        int d=min(s[i],V/v[i]);
        for(int p=1;d>0;p<<=1){
            if(p>d)p=d;
            d-=p;
            for(int j=V;j>=v[i]*p;j--)
                f[j]=max(f[j],f[j-v[i]*p]+w[i]*p);
        }
    }
    cout<<f[V]<<'\n';
    return 0;
}
// 单调队列优化 按余数分类 单调队列维护窗口最大值
const int N=20000+55;
int V,n,f[N],q[N],g[N];
int main(){
    cin>>n>>V;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++){
        int v,w,s;cin>>v>>w>>s;
        memcpy(g,f,sizeof f);
        for(int j=0;j<v;j++){   //余数
            int hh=0,tt=-1;
            for(int k=j;k<=V;k+=v){ //容量
                // 单调队列
                f[k]=g[k];
                if(hh<=tt&&k-s*v>q[hh])hh++;
                if(hh<=tt)f[k]=max(f[k],g[q[hh]]+(k-q[hh])/v*w);
                //max(f[i-1][k],f[i-1][能转移里最大]+个数*v[i]);
                while(hh<=tt&&g[q[tt]]-(q[tt]-j)/v*w<=g[k]-(k-j)/v*w)tt--;
                q[++tt]=k;
            }
        }
    }
    cout<<f[V]<<'\n';
}
```

- 混合背包

```c++
const int N=1111;
int V,n,f[N],v[N],w[N],s[N];
int main(){
    cin>>n>>V;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i]>>s[i];
    for(int i=1;i<=n;i++){
        if(s[i]==-1){   // 01背包
            for(int j=V;j>=v[i];j--)f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
        else if(s[i]==0){   // 完全背包
            for(int j=v[i];j<=V;j++)f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
        else if(s[i]>0){    // 多重背包
            int d=min(s[i],V/v[i]);
            for(int p=1;d>0;p<<=1){
                if(p>d)p=d;
                d-=p;
                for(int j=V;j>=v[i]*p;j--)f[j]=max(f[j],f[j-v[i]*p]+w[i]*p);
            }
        }
    }
    cout<<f[V]<<'\n';
    return 0;
}
```

- 分组背包

```c++
// 每组选一 多一层枚举组
const int N=111;
int V,n,s[N],v[N][N],w[N][N],f[N];
int main(){
    cin>>n>>V;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=1;j<=s[i];j++)cin>>v[i][j]>>w[i][j];
    }
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)
        for(int j=V;j>=0;j--)
            for(int k=1;k<=s[i];k++)
                if(j>=v[i][k])f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
    cout<<f[V]<<'\n';
    return 0;
}
```

- 二维费用的背包问题

```c++
// 二维费用的01背包
// 状态增加一维
const int N=1111;
int n,V1,V2,v1[N],v2[N],w[N],f[N][N];
int main(){
    cin>>n>>V1>>V2;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)cin>>v1[i]>>v2[i]>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=V1;j>=v1[i];j--)
            for(int k=V2;k>=v2[i];k--)
                f[j][k]=max(f[j][k],f[j-v1[i]][k-v2[i]]+w[i]);
    cout<<f[V1][V2]<<'\n';
    return 0;
}
// 前缀和 常数优化
const int N=1111;
int n,V1,V2,v1[N],v2[N],w[N],f[N][N],s1[N],s2[N];
int main(){
    cin>>n>>V1>>V2;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)cin>>v1[i]>>v2[i]>>w[i],s1[i]=s1[i-1]+v1[i],s2[i]=s2[i-1]+v2[i];
    for(int i=1;i<=n;i++){
        int d1=max(V1-s1[n]-s1[i],v1[i]);
        int d2=max(V2-s2[n]-s2[i],v2[i]);
        for(int j=V1;j>=d1;j--)
            for(int k=V2;k>=d2;k--)
                f[j][k]=max(f[j][k],f[j-v1[i]][k-v2[i]]+w[i]);
    }
    cout<<f[V1][V2]<<'\n';
}
```

- 最优方案数

```c++
// 01背包最优方案数
// f[i,v]=sum{f[i-1,v],f[i,v-ci]}
const int mod=1e9+7;
const int N=1111;
int n,V,f[N],g[N],v[N],w[N];
int main()
{
    cin>>n>>V;
    std::memset(f,0,sizeof f);
    for(int i=0;i<=V;i++)g[i]=1;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=V;j>=v[i];j--){
            int d=f[j-v[i]]+w[i];
            if(f[j]<d)f[j]=d,g[j]=g[j-v[i]];
            else if(d==f[j])g[j]=(g[j]+g[j-v[i]])%mod;
        }
    cout<<g[V]<<'\n';
    return 0;
}
```

- 具体方案

```c++
/*  字典序最小的最优方案
    1.字典序最小:倒序枚举 或 方案排序
    2.方案预处理 判断选择
*/
//  01背包字典序最小方案
const int N=1111;
int n,V,f[N][N],v[N],w[N];
int main()
{
    cin>>n>>V;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    for(int i=n;i>=1;i--){
        for(int j=0;j<=V;j++){
            f[i][j]=f[i+1][j];
            if(j>=v[i])f[i][j]=max(f[i][j],f[i+1][j-v[i]]+w[i]);
        }
    }
    int res=V;
    for(int i=1;i<=n;i++){
        if(i==n&&res>=v[i]){cout<<i<<' ';break;}
        if(res<=0)break;
        if(res>=v[i]&&f[i][res]==f[i+1][res-v[i]]+w[i])cout<<i<<' ',res-=v[i];
    }
    cout<<'\n';
    return 0;
}
```

- k优解

```c++
/*  f[i,v,k] 第三维为有序队列
    f[i,v,k] = {f[i-1,v,k]}+{f[i-1,v-v[i],k]}
*/
//  恰好装满 前k大价值(和)
const int N=5055;
const int _N=222;
const int K=66;
int n,k,V,ans,f[N][K],v[_N],w[_N],res[K];
int main()
{
    cin>>k>>V>>n;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    memset(f,-127,sizeof f);f[0][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            int x=1,y=1,z=0;
            while(z<=k){
                if(f[j][x]>=f[j-v[i]][y]+w[i])res[++z]=f[j][x++];
                else res[++z]=f[j-v[i]][y++]+w[i];
            }
            for(int i=1;i<=k;i++)f[j][i]=res[i];
        }
    }
    for(int i=1;i<=k;i++)cout<<f[V][i]<<" \n"[i==k];
    for(int i=1;i<=k;i++)ans+=f[V][i];
    cout<<ans<<'\n';
    return 0;
}
```

- 有依赖的背包问题(树形dp/树上背包)

```c++
// 树形依赖背包问题 树上dp
const int N=1005;
int n,v,root;
int f[N][N],c[N],w[N];
int h[N],ne[N],e[N],cnt;
inline void add(int a,int b)    // a->b
{
    e[cnt]=b,ne[cnt]=h[a],h[a]=cnt++;
}
void dfs(int u)
{
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int son=e[i];dfs(son);
        for(int j=v-c[u];j>=0;j--){
            for(int k=0;k<=j;k++){
                f[u][j]=max(f[u][j],f[u][j-k]+f[son][k]);
            }
        }
    }
    for(int i=v;i>=c[u];i--)f[u][i]=f[u][i-c[u]]+w[u];
    for(int i=0;i<c[u];i++)f[u][i]=0;
    return ;
}
int main()
{
    memset(f,0,sizeof f);memset(h,-1,sizeof h);
    cin>>n>>v;
    for(int i=1;i<=n;i++){
        int p;cin>>c[i]>>w[i]>>p;   // p->i
        if(p==-1)root=i;else add(p,i);
    }
    dfs(root);
    cout<<f[root][v]<<'\n';
    return 0;
}
```

## 树形dp

## 数位dp

## 区间dp

## 插头dp

## dp优化

# 三.字符串

## KMP

## Tire树

## AC自动机

## 字符串哈希

## 马拉车(manacher)

## 字符串的最小表示

## 后缀数组(SA)

## 后缀自动机(SAM)

## 编辑距离

# 四.数据结构

## 常见简单数据结构

- 单链表

- 双链表

- 栈

## 单调栈与单调队列

## 并查集

并查集是一种树形的数据结构，通过树结构将元素进行集合**合并**即**查询**，能够维护传递性的关系，通常支持:

查询(Find):查询元素所属集合
合并(Merge/Union):将两个集合合并

### 朴素并查集+路径压缩

```c++
struct dsu {   //   DSU
    vector<int> f;
    dsu(int n) :f(n) { iota(f.begin(), f.end(), 0); }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }   //  路径压缩
    bool same(int x,int y) { return find(x)==find(y);}
    void merge(int x, int y) {  //  大并小
        x = find(x); y = find(y);
        if (x > y)swap(x, y);
        f[y] = x;
    }
};
```

### 路径压缩+启发式合并

```c++
struct dsu {   //   DSU
    vector<int> f, size;
    dsu(int n) :f(n), size(n,1) { iota(f.begin(), f.end(), 0); }    //  路径压缩
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    bool same(int x,int y) { return find(x)==find(y);}
    void merge(int x, int y) {  //  启发式合并
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (size[fx] > size[fy]) swap(fx,fy);   //  启发式合并
        f[fx] = fy;
        size[fy] += size[fx];                   //  启发式合并
    }
};
```

### 维护大小+祖先距离

```c++
struct dsu {   //   DSU
    vector<int> f, size, d;     //  实际大小应是size[f[x]]
    dsu(int n) :f(n), size(n,1), d(n,0) {  iota(f.begin(), f.end(), 0); }
    int find(int x) {   //  路径压缩
        if(f[x]==x) return x;
        int fa = find(f[x]);
        d[x] += d[f[x]];
        return f[x] = fa;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) {  //  大并小
        x = find(x); y = find(y);
        if(x==y) return;
        if (x > y)swap(x, y);
        size[x] += size[y];
        d[y] = 1;   //  other
        f[y] = x;
    }
};
```

### 带权并查集

```c++
/*  带权并查集 例子 权==x-f[x] 通常若权值为M个集合，应取模M，即维护模M意义下的运算群 */
struct dsu {   //   DSU
    vector<int> f, size;
    vector<int> val;    //  权x-f[x]
    dsu(int n) :f(n), size(n,1), val(n,0) {  iota(f.begin(), f.end(), 0); }
    int find(int x) {   //  路径压缩
        if(f[x]==x) return x;
        int fa = find(f[x]);    //  注意顺序
        val[x] += val[f[x]];    //  更新权 val[x]%=M
        return f[x] = fa;       //  路径压缩
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y,int res) {  //  启发式合并 边权x<->y==res
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (size[fx] > size[fy]) swap(fx,fy);   //  启发式合并
        f[fx] = fy;
        size[fy] += size[fx];                   //  启发式合并
        val[fx] = val[y] + res - val[x];        //  更新权 val[fy]%=M
    }
};
```

### 带权并查集求有向图最小环

```c++
/*  带权并查集求有向图最小环
    例子:信息传递
    维护带权并查集，边权x-f[x]默认1，每次加边x->y先判是否在一个集合，不在则合并，在则说明成环，环长即val[y]+1
*/
#define inf 0x3f3f3f3f
struct dsu {   //   DSU
    vector<int> f/*, size*/;
    vector<int> val;    //  权x-f[x]
    dsu(int n) :f(n)/*, size(n,1)*/, val(n,0) {  iota(f.begin(), f.end(), 0); }
    int find(int x) {   //  路径压缩
        if(f[x]==x) return x;
        int fa = find(f[x]);    //  注意顺序
        val[x] += val[f[x]];    //  更新权
        return f[x] = fa;       //  路径压缩
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y,int res) {  //  合并 x->y
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        // if (size[fx] > size[fy]) swap(fx,fy);    //  启发式合并
        f[fx] = fy;
        // size[fy] += size[fx];                    //  启发式合并
        val[fx] = val[y] + res - val[x];    //  更新权
    }
};
void PX()
{
    int n;cin>>n;
    dsu px(n+1);
    int ans=inf;
    for(int i=1;i<=n;i++){  //  边i->t
        int t;cin>>t;
        if(!px.same(i,t))px.merge(i,t,1);  //  加边i->t
        else ans=min(ans,px.val[t]+1);  //  成环 更新最小ans
    }
    cout<<ans<<'\n';
}
```

### 种类并查集/并查集扩展域

```c++
/*  种类并查集/并查集扩展域 通过多个并查集维护多个集合的关系，同时也是循环对称关系
    (例子食物链) i,j同类或i吃j或j吃i 开三倍大小[1,3*n]  <i,j>:i,j同类;<i,j+n>:i吃j;<i,j+2*n>:j吃i
*/
struct dsu {   //   DSU
    vector<int> f, size;
    dsu(int n) :f(n), size(n,1) { iota(f.begin(), f.end(), 0); }    //  路径压缩
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    bool same(int x,int y) { return find(x)==find(y);}
    void merge(int x, int y) {  //  启发式合并
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (size[fx] > size[fy]) swap(fx,fy);   // 启发式合并
        f[fx] = fy;
        size[fy] += size[fx];                   // 启发式合并
    }
};
void PX()
{
    int n,k;cin>>n>>k;
    dsu px(3*n+1);
    int ans=0;
    while(k--){ //  有序
        int op,x,y;cin>>op>>x>>y;
        if(x>n||y>n) { ans++;continue; }    //  超过n
        if(op==1) { // 1 x y same(x,y)
            if(px.same(x,y+n)||px.same(x,y+2*n))ans++;  //  x->y / y->x
            else px.merge(x,y),px.merge(x+n,y+n),px.merge(x+2*n,y+2*n); // x<->y
        }
        if(op==2) { // 2 x y x->y
            if(px.same(x,y+2*n)||px.same(x,y))ans++;  //  y->x / x<->y
            else px.merge(x,y+n),px.merge(x+n,y+2*n),px.merge(x+2*n,y); //  x->y
        }
    }
    cout<<ans<<'\n';    //  error time
}
```

### 并查集元素删除

```c++
/*  并查集元素删除
    朴素并查集初始化f[x]=x，先进行f[i]=i+n，f[j]=j，其中i为有效点，j为虚拟点
    例子  op=1,x,y -> merge(x->y)   op=2,x,y -> move(x->y)  op=3,x -> size[(x)] + sum[(x)]
*/
struct dsu {   //   DSU
    vector<int> f, size, sum;    //  f[0-n-1]->[n-2*n]  f[n-2*n]->[n-2*n] (visual)
    dsu(int n) :f(2*n), size(2*n,1), sum(2*n,0) {
        for (int i = 0; i < n; i++) {
            f[i] = f[i + n] = i + n;
            size[i + n] = 1;        //  visual size
            sum[i + n] = i;         //  visual sum
        }
    }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    bool same(int x,int y) { return find(x)==find(y);}
    void merge(int x, int y) {  //  合并 merge(x->y)
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        // if (size[fx] > size[fy]) swap(fx,fy);   //  启发式合并
        f[fx] = fy;
        size[fy] += size[fx];
        sum[fy] += sum[fy];
        size[fx] = sum[fx] = 0;
    }
    void del(int x) {    //  删除 del(x)
        int fx = f[x];
        size[fx]--; sum[fx]-=x;
        f[x]=0;             //  o 或者 2*n+1 范围点外即可
    }
    void move(int x, int y) {   //  move (x->y)
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        size[fy]++; sum[fy]+=x;
        size[fx]--; sum[fx]-=x;
        f[x] = fy;
    }
};
void PX()
{
    int n;cin>>n;
    dsu px(n+1);
    int m;cin>>m;
    int x,y,op;
    while(m--){
        cin>>op;
        if(op==1){      //  merge(x->y)
            cin>>x>>y;
            if(px.same(x,y))continue;
            else px.merge(x,y);
        }
        else if(op==2){ //  move(x->y)
            cin>>x>>y;
            if(px.same(x,y))continue;
            else px.move(x,y);
        }
        else {          //  answer size[(x)] + sum[(x)]
            cin>>x;
            int fx=px.f[x];
            cout<<px.size[fx]<<' '<<px.sum[fx]<<'\n';
        }
    }
}
```

## 树状数组

## 线段树

## 平衡树

## 主席树

## ST表

## 莫队

# 五.图论

## 最短路

## 最长路

## k短路

## 欧拉回路

## 最小生成树

## 最小树形图(朱刘算法)

## 负环与01分数规划

## 树上问题

## 最近公共祖先(LCA)

## 无向图的连通性

## 有向图的连通性

## 2-SAT问题

## 拓扑排序

## 二分图

# 六.网络流

# 七.数论

# 八.计算几何

# 杂项
