/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-24 19:40:28
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-07-21 16:10:59
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\动态规划_DP\t.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
typedef long long ll;
typedef unsigned long long ull;
#define UINF ~0ull
#define mod_ 99993
#define vii vector<int>
#define vvii vector<vector<int>>
#define vll vector<ll>
#define fi first
#define se second
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 5e5+55;
const long double eps=1e-8;
const long double PI=acos(-1.0);
ll mpow(ll a,ll b,ll m){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline bool _bug(bool _line=0,bool line_=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";if(line_)cout<<'\n';return 1;
#endif
    return 0;
}
/*
    洛谷 P3506 [POI2010]MOT-Monotonicity 2  dp+树状数组维护前后缀最值
    <https://www.luogu.com.cn/problem/P3506>
    给出长为n的整数序列a,长为k的符号序列s(<,=,>)
    求最长的子序列满足 a[i] 's[(i-1)%k+1]' a[i+1]
    对权值映射,在a[i]范围维护前/后缀最大值树状数组,分别用来维护<,>长度,=的情况直接val记录
    dp[i]维护前i个最长子序列长度
    on遍历,一边维护三种情况的长度,取<i时三种情况的最大值更新dp[i]
......
n/k -> 500000 ->5e5
a[i] -> 1e6
n = 7   k = 3
1 2 3 4 5 6 7
2 4 3 1 3 5 3
1 2 3
< > =
6
2 4 3 3 5 3
(1-1)%3+1 = 1 -> 2<4
(2-1)%3+1 = 2 -> 4>3
(3-1)%3+1 = 3 -> 3=3
......
*/
// bool multest = 1;
bool multest = 0;
void _Init(){
}
const int MA = 1e6;
int n, k;
int a[N], b[N]; //  b:string of op ->[ <:0; =:1; >:2 ]
int pre[MA+5], suf[MA+5]; //  Bit pre && suf
int dp[N], val[MA+5];  //  dp[i]:max len of pre i  val[i]:max len of val i
#define lowbit(x) ((x) & -(x))
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
//  树状数组维护前后缀最大值
inline void update(int t[], int pos, int x)
{
    for(int i=pos;i<=MA;lowbitup(i)) {
        t[i] = max(t[i], x);
    }
}
inline int query(int t[], int pos)
{
    int Res = 0;
    for(int i=pos;i>0;lowbitdown(i)) {
        Res = max(Res, t[i]);
    }
    return Res;
}
int PX()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=k;i++) {
        char op;
        cin >> op;
        if(op=='<') b[i]=0;
        else if(op=='=') b[i]=1;
        else b[i]=2;
    }
    for(int i=k+1;i<=n;i++) b[i] = b[i-k];  //  预处理模后的操作
    for(int i=1;i<=n;i++) {
        //  [pre] _val_ [suf]
        int x = val[a[i]];
        int y = query(pre, a[i]-1);
        int z = query(suf, MA-a[i]);
        dp[i] = max({x,y,z}) + 1;
        auto now = dp[i];
        if(b[now]==0) {
            update(pre, a[i], now);
        }
        else if(b[now]==2) {
            update(suf, MA-a[i]+1, now);
        }
        else val[a[i]] = max(now, val[a[i]]);
    }
    int len = 0, R = 0, res = 0;
    for(int i=1;i<=n;i++) {
        if(dp[i]>len) {
            len = dp[i];
            R = i;
            res = a[i];
        }
    }
    stack<int> path;
    cout << len << '\n';
    len--;
    path.push(res);
    for(int i = R - 1; i>0; i--) {
        if(len==0) break;
        bool ok = 0;
        if(b[len]==1) {
			if(res==a[i]&&dp[i]==len)   ok = 1;
		}
		else if(b[len]==0) {
			if(res>a[i]&&dp[i]==len)    ok = 1;
		}
		else if(b[len]==2) {
			if(res<a[i]&&dp[i]==len)    ok = 1;
		}
        if(ok) {
            path.push(a[i]);
            len--;
            res=a[i];
        }
    }
    while(!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    // puts("");
    cout << '\n';
    return 1;
}
signed main()
{
#ifdef LOCAL
    freopen("E:\\ACMdream\\in.txt", "r", stdin);
    freopen("E:\\ACMdream\\out.txt", "w", stdout);
    clock_t time1 = clock();
#endif
    IOS;
    //==================================================
    ll ZPX = 1;
    if (multest)
        cin >> ZPX;
    _Init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}