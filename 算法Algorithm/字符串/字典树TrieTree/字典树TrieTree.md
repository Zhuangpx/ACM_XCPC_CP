<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-10-05 11:10:54
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-10-19 16:22:01
 * @FilePath: \apricitye:\桌面\ACM\算法Algorithm\字符串\字典树TrieTree\字典树TrieTree.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->

# 字典树TrieTree

字典树，Trie Tree，其实也是前缀树。

题单：<https://vjudge.net/contest/294092> -> <https://blog.csdn.net/qq_41292370/article/details/90680145>

## 板子

```c++
// 1.vector
struct TrieTree {
    int tt_cnt;     //  tt_cnt = sum_node
    int tt_max;     //  tt_max = sum_len
    int ch_max;     //  ch_max = sum_char
    vector<vector<int>> tt_trie;
    vector<int> tt_end;
    TrieTree(int tt_Max, int ch_Max) {
        tt_max = tt_Max;
        ch_max = ch_Max;
        tt_trie.resize(tt_max+2, vector<int> (ch_max+2, 0));
        tt_end.resize(tt_max+2, 0);
    }
    int ch_int(char ch) {
        return (ch-'a');
        // return (ch-'0');
        // return (int)ch;
    }
    void tt_insert(string s) {
        int len = s.size();
        int id = 0;
        for(int i=0;i<len;i++) {
            int ch = ch_int(s[i]);
            if(!tt_trie[id][ch]) tt_trie[id][ch] = ++tt_cnt;
            id = tt_trie[id][ch];
        }
        tt_end[id]++;
    }
    int tt_find(string s) {
        int len = s.size();
        int id = 0;
        for(int i=0;i<len;i++) {
            int ch = ch_int(s[i]);
            if(!tt_trie[id][ch]) return 0;
            id = tt_trie[id][ch];
        }
        return tt_end[id];
    }
};
// 2.const int
const int tt_max = 1e6 + 5, ch_max = 28;
struct TrieTree {
    int tt_cnt;     //  tt_cnt = sum_node
    int tt_trie[tt_max][ch_max], tt_end[tt_max];
    int ch_int(char ch) {
        return (ch-'a');
        // return (ch-'0');
        // return (int)ch;
    }
    void tt_insert(string s) {
        int len = s.size();
        int id = 0;
        for(int i=0;i<len;i++) {
            int ch = ch_int(s[i]);
            if(!tt_trie[id][ch]) tt_trie[id][ch] = ++tt_cnt;
            id = tt_trie[id][ch];
        }
        tt_end[id]++;
    }
    int tt_find(string s) {
        int len = s.size();
        int id = 0;
        for(int i=0;i<len;i++) {
            int ch = ch_int(s[i]);
            if(!tt_trie[id][ch]) return 0;
            id = tt_trie[id][ch];
        }
        return tt_end[id];
    }
};
```

## 01Trie

比较广义的，比如可以把整数看成01字符串。

如，求异或最大值。

### 异或最大值

高位往低位建

```c++
const int tt_max = 1e6 + 5, ch_max = 28;
struct TrieTree_01 {
    //  最大异或对 高位往低位建
    int tt_cnt;     //  tt_cnt = sum_node
    int tt_trie[tt_max][2], tt_end[tt_max];
    void tt_init() {
        memset(tt_trie, 0, sizeof tt_trie);
        memset(tt_end, 0, sizeof tt_max);
        tt_cnt = 0;
    }
    void tt_insert(int num) {
        int id = 0;
        for(int i=32;i>=0;i--) {
            int now = (num>>i)&1;   //  now:0 Or 1
            if(!tt_trie[id][now]) tt_trie[id][now] = ++tt_cnt;
            id = tt_trie[id][now];
        }
        tt_end[id] = num;
    }
    //  与num异或最大的数
    int tt_find_max01(int num) {
        int id = 0;
        for(int i=32;i>=0;i--) {
            int now = (num>>i)&1;   //  now:0 Or 1
            if(tt_trie[id][now^1]) id = tt_trie[id][now^1]; //  First:now^1
            else id = tt_trie[id][now];                     //  Second:now
        }
        return tt_end[id];
    }
};
```

### 全局异或_全局+1

低位往高位建，只关心每一位0/1个数，不关心具体的数

## 经典题

### 模板：检索

<https://www.luogu.com.cn/problem/P2580>

```c++
// #pragma GCC optimize(2)
//
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
#define UINF ~0ull              //18446744073709551615=1e19
typedef long long ll;
typedef unsigned long long ull;
#define Ve(T) vector<T>
#define VVe(T) vector<vector<T>>
#define pii pair<int,int>
#define all(T) T.begin(),T.end()
#define fi first
#define se second
#define pdec(t,ans) cout<<std::fixed<<std::setprecision(t)<<(ans)
const int Mod = 99993;
const int mod = 1e9+7;
const int MOD = 998244353;
const int N = 1e6+5;
const long double eps=1e-6;
const long double PI=acos(-1.0);
ll mpow(ll a,ll b,ll m = mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll gcd(ll a,ll b){ll d;while(b){d=b;b=a%b;a=d;} return a;}
template<class T> void fout(T ita) { cout << ita << ' '; }
template<class T> void fout_(T ita) { cout << ita ; }
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
inline bool _bug(bool _debug=0,bool _line=0){
#ifdef LOCAL
    if(_debug)cout<<"_Debug: ";if(_line)cout<<'\n';return true;
#endif
    return false;
}
/*
*/
// bool multest = 1;
bool multest = 0;
void _Init()
{
}
const int tt_max = 1e6 + 5, ch_max = 28;
struct TrieTree {
    int tt_cnt;     //  tt_cnt = sum_node
    int tt_trie[tt_max][ch_max], tt_end[tt_max];
    int ch_int(char ch) {
        return (ch-'a');
        // return (ch-'0');
        // return (int)ch;
    }
    void tt_insert(string s) {
        int len = s.size();
        int id = 0;
        for(int i=0;i<len;i++) {
            int ch = ch_int(s[i]);
            if(!tt_trie[id][ch]) tt_trie[id][ch] = ++tt_cnt;
            id = tt_trie[id][ch];
        }
        tt_end[id]++;
    }
    int tt_find(string s) {
        int len = s.size();
        int id = 0;
        for(int i=0;i<len;i++) {
            int ch = ch_int(s[i]);
            if(!tt_trie[id][ch]) return 0;
            id = tt_trie[id][ch];
        }
        return tt_end[id];
    }
};
TrieTree px, p;
int PX()
{
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        px.tt_insert(s);
    }
    int m;
    cin >> m;
    while(m--) {
        string s;
        cin >> s;
        int res = px.tt_find(s);
        if(res==0) cout << "WRONG\n";
        else {
            int now = p.tt_find(s);
            if(now!=0) cout << "REPEAT\n";
            else cout << "OK\n", p.tt_insert(s);
        }
    }
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
    int ZPX = 1;
    if (multest)
        cin >> ZPX;
        // scanf("%d", &ZPX);
    _Init();
    for(int Zpx = 1; Zpx <= ZPX; ++Zpx) {
        // cout << "Case #" << Zpx << ": ";
        PX();
    }
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}
```

### 01Trie：求异或最大值

<https://www.acwing.com/problem/content/description/145/>

```c++
// #pragma GCC optimize(2)
//
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
#define UINF ~0ull              //18446744073709551615=1e19
typedef long long ll;
typedef unsigned long long ull;
#define Ve(T) vector<T>
#define VVe(T) vector<vector<T>>
#define pii pair<int,int>
#define all(T) T.begin(),T.end()
#define fi first
#define se second
#define pdec(t,ans) cout<<std::fixed<<std::setprecision(t)<<(ans)
const int Mod = 99993;
const int mod = 1e9+7;
const int MOD = 998244353;
const int N = 1e6+5;
const long double eps=1e-6;
const long double PI=acos(-1.0);
ll mpow(ll a,ll b,ll m = mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll gcd(ll a,ll b){ll d;while(b){d=b;b=a%b;a=d;} return a;}
template<class T> void fout(T ita) { cout << ita << ' '; }
template<class T> void fout_(T ita) { cout << ita ; }
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
inline bool _bug(bool _debug=0,bool _line=0){
#ifdef LOCAL
    if(_debug)cout<<"_Debug: ";if(_line)cout<<'\n';return true;
#endif
    return false;
}
/*
*/
// bool multest = 1;
bool multest = 0;
void _Init()
{
}
const int tt_max = 1e7 + 5, ch_max = 28;
struct TrieTree_01 {
    int tt_cnt;     //  tt_cnt = sum_node
    int tt_trie[tt_max][2], tt_end[tt_max];
    void tt_init() {
        memset(tt_trie, 0, sizeof tt_trie);
        memset(tt_end, 0, sizeof tt_max);
        tt_cnt = 0;
    }
    void tt_insert(int num) {
        int id = 0;
        for(int i=32;i>=0;i--) {
            int now = (num>>i)&1;   //  now:0 Or 1
            if(!tt_trie[id][now]) tt_trie[id][now] = ++tt_cnt;
            id = tt_trie[id][now];
        }
        tt_end[id] = num;
    }
    int tt_find_max01(int num) {
        int id = 0;
        for(int i=32;i>=0;i--) {
            int now = (num>>i)&1;   //  now:0 Or 1
            if(tt_trie[id][now^1]) id = tt_trie[id][now^1]; //  First:now^1
            else id = tt_trie[id][now];                     //  Second:now
        }
        return tt_end[id];
    }
};
TrieTree_01 tr;
int PX()
{
    int n;
    cin >> n;
    int ans = 0;
    while(n--) {
        int d;
        cin >> d;
        tr.tt_insert(d);
        ans = max(ans, d^tr.tt_find_max01(d));
    }
    cout << ans << '\n';
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
    int ZPX = 1;
    if (multest)
        cin >> ZPX;
        // scanf("%d", &ZPX);
    _Init();
    for(int Zpx = 1; Zpx <= ZPX; ++Zpx) {
        // cout << "Case #" << Zpx << ": ";
        PX();
    }
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}
```

<https://www.luogu.com.cn/problem/P4551>

同理，处理一下树

```c++
// #pragma GCC optimize(2)
//
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
#define UINF ~0ull              //18446744073709551615=1e19
typedef long long ll;
typedef unsigned long long ull;
#define Ve(T) vector<T>
#define VVe(T) vector<vector<T>>
#define pii pair<int,int>
#define all(T) T.begin(),T.end()
#define fi first
#define se second
#define pdec(t,ans) cout<<std::fixed<<std::setprecision(t)<<(ans)
const int Mod = 99993;
const int mod = 1e9+7;
const int MOD = 998244353;
const int N = 1e6+5;
const long double eps=1e-6;
const long double PI=acos(-1.0);
ll mpow(ll a,ll b,ll m = mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll gcd(ll a,ll b){ll d;while(b){d=b;b=a%b;a=d;} return a;}
template<class T> void fout(T ita) { cout << ita << ' '; }
template<class T> void fout_(T ita) { cout << ita ; }
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
inline bool _bug(bool _debug=0,bool _line=0){
#ifdef LOCAL
    if(_debug)cout<<"_Debug: ";if(_line)cout<<'\n';return true;
#endif
    return false;
}
/*
*/
// bool multest = 1;
bool multest = 0;
void _Init()
{
}
const int tt_max = 1e6 + 5, ch_max = 28;
struct TrieTree_01 {
    int tt_cnt;     //  tt_cnt = sum_node
    int tt_trie[tt_max][2], tt_end[tt_max];
    void tt_init() {
        memset(tt_trie, 0, sizeof tt_trie);
        memset(tt_end, 0, sizeof tt_max);
        tt_cnt = 0;
    }
    void tt_insert(int num) {
        int id = 0;
        for(int i=32;i>=0;i--) {
            int now = (num>>i)&1;   //  now:0 Or 1
            if(!tt_trie[id][now]) tt_trie[id][now] = ++tt_cnt;
            id = tt_trie[id][now];
        }
        tt_end[id] = num;
    }
    int tt_find_max01(int num) {
        int id = 0;
        for(int i=32;i>=0;i--) {
            int now = (num>>i)&1;   //  now:0 Or 1
            if(tt_trie[id][now^1]) id = tt_trie[id][now^1]; //  First:now^1
            else id = tt_trie[id][now];                     //  Second:now
        }
        return tt_end[id];
    }
};
TrieTree_01 tr;
vector<pii> e[N];
int val[N];
int ans;
void dfs(int u, int fa)
{
    tr.tt_insert(val[u]);
    ans = max(ans, val[u]^tr.tt_find_max01(val[u]));
    for(auto [v, w]:e[u]) {
        if(v==fa) continue;
        val[v] = val[u]^w;
        dfs(v, u);
    }
}
int PX()
{
    int n;
    cin >> n;
    for(int i=1,u,v,w; i<n; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << ans << '\n';
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
    int ZPX = 1;
    if (multest)
        cin >> ZPX;
        // scanf("%d", &ZPX);
    _Init();
    for(int Zpx = 1; Zpx <= ZPX; ++Zpx) {
        // cout << "Case #" << Zpx << ": ";
        PX();
    }
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}
```

<https://www.acwing.com/problem/content/1416/>

同理，处理一下前缀异或和，end可以存下标

```c++
// #pragma GCC optimize(2)
//
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
#define UINF ~0ull              //18446744073709551615=1e19
typedef long long ll;
typedef unsigned long long ull;
#define Ve(T) vector<T>
#define VVe(T) vector<vector<T>>
#define pii pair<int,int>
#define all(T) T.begin(),T.end()
#define fi first
#define se second
#define pdec(t,ans) cout<<std::fixed<<std::setprecision(t)<<(ans)
const int Mod = 99993;
const int mod = 1e9+7;
const int MOD = 998244353;
const int N = 1e6+5;
const long double eps=1e-6;
const long double PI=acos(-1.0);
ll mpow(ll a,ll b,ll m = mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll gcd(ll a,ll b){ll d;while(b){d=b;b=a%b;a=d;} return a;}
template<class T> void fout(T ita) { cout << ita << ' '; }
template<class T> void fout_(T ita) { cout << ita ; }
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
inline bool _bug(bool _debug=0,bool _line=0){
#ifdef LOCAL
    if(_debug)cout<<"_Debug: ";if(_line)cout<<'\n';return true;
#endif
    return false;
}
/*
*/
// bool multest = 1;
bool multest = 0;
void _Init()
{
}
const int tt_max = 1e6 + 5, ch_max = 28;
struct TrieTree_01 {
    int tt_cnt;     //  tt_cnt = sum_node
    int tt_trie[tt_max][2], tt_end[tt_max];
    void tt_init() {
        memset(tt_trie, 0, sizeof tt_trie);
        memset(tt_end, 0, sizeof tt_max);
        tt_cnt = 0;
    }
    void tt_insert(int num, int pos) {
        int id = 0;
        for(int i=32;i>=0;i--) {
            int now = (num>>i)&1;   //  now:0 Or 1
            if(!tt_trie[id][now]) tt_trie[id][now] = ++tt_cnt;
            id = tt_trie[id][now];
        }
        tt_end[id] = pos;
    }
    int tt_find_max01(int num) {
        int id = 0;
        for(int i=32;i>=0;i--) {
            int now = (num>>i)&1;   //  now:0 Or 1
            if(tt_trie[id][now^1]) id = tt_trie[id][now^1]; //  First:now^1
            else id = tt_trie[id][now];                     //  Second:now
        }
        return tt_end[id];
    }
};
TrieTree_01 tr;
int PX()
{
    int n;
    cin >> n;
    int ans = -1, l = 0, r = 0;
    vector<int> v(n+1, 0);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        if(v[i]>ans) ans=v[i], l=r=i;
        v[i]^=v[i-1];
    }
    tr.tt_insert(0, 0);
    for(int i=1;i<=n;i++) {
        //
        tr.tt_insert(v[i], i);
        int pos = tr.tt_find_max01(v[i]);
        int now = v[pos] ^ v[i];
        if(now>ans) ans=now, l=pos+1, r=i;
        // cout << i << ' ' << now << ' ' << pos << '\n';
    }
    cout << ans << ' ' << l << ' ' << r << '\n';
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
    int ZPX = 1;
    if (multest)
        cin >> ZPX;
        // scanf("%d", &ZPX);
    _Init();
    for(int Zpx = 1; Zpx <= ZPX; ++Zpx) {
        // cout << "Case #" << Zpx << ": ";
        PX();
    }
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}
```

## 散题

### CF1447E

<https://codeforces.com/contest/1447/problem/E>

01字典树，维护树结构，保证每一层只有一个节点，删点求min
