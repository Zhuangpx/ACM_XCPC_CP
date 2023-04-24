/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-21 20:12:00
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-21 20:12:00
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_[牛客]网络优化.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f
typedef long long ll;
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define UINF ~0ull
#define mod_ 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 2e5+111;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll _mpow(ll a,ll b,ll m=_mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline bool _bug(bool _line=0,bool line_=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";
    if(line_)cout<<'\n';
    return 1;
#endif
    return 0;
}
#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"

/*
    [牛客]网络优化  <https://ac.nowcoder.com/acm/contest/22904/1010>
    优先队列+贪心
    n个人m条服务线，每条有l,r,v分别代表服务范围和最大容量 求最大服务量 n,m只有1e4
    n比较小，考虑枚举n再check有无服务线
    贪心让l==i的服务线为i服务，多条同l考虑先取r小的，r也相同考虑先取v小的
    那么按l-r-v小到大排序，用优先队列来维护选择的服务线，l==i的服务线加入队列，然后取出堆顶进行贡献计数更新
*/
void init(){
}
struct Line
{
    ll l,r,v;
    friend bool operator<(const Line& a,const Line& b)
    {
        if(a.l!=b.l)return a.l<b.l;
        if(a.r!=b.r)return a.r<b.r;
        return a.v<b.v;
    }
};
struct C
{
    ll r,v;
    C(ll _r,ll _v):r(_r),v(_v){};
    friend bool operator<(const C& a,const C& b)
    {
        if(a.r!=b.r)return a.r>b.r;
        else return a.v>b.v;
    }
};
void PX()
{
    ll n,m;
    while(cin>>n>>m){
    vector<Line>v(m);
    for(auto &q:v)cin>>q.l>>q.r>>q.v;
    sort(v.begin(),v.end());
    priority_queue<C>q;
    ll ans=0;
    ll idx=0;
    for(ll i=1;i<=n;i++){
        while(!q.empty()&&(q.top().r<i||q.top().v<=0))q.pop();
        while(v[idx].l==i){
            q.push({v[idx].r,v[idx].v});
            idx++;
        }
        if(!q.empty()){
            auto now=q.top();q.pop();
            now.v--;ans++;
            if(now.v>0)q.push(now);
        }
    }
    cout<<ans<<'\n';}
}

int main()
{
#ifdef LOCAL
    freopen("E:\\ACMdream\\in.txt", "r", stdin);
    freopen("E:\\ACMdream\\out.txt", "w", stdout);
    clock_t time1 = clock();
#endif
    IOS;
    //==================================================
    ll ZPX = 1;
    // cin >> ZPX;
    init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}
