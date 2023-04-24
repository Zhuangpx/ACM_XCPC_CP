/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-21 21:17:44
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-21 21:17:45
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_[牛客]小A与任务.cpp
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
    [牛客]小A与任务 <https://ac.nowcoder.com/acm/contest/22904/1011>
    优先队列+贪心
    n个任务有开始时间y，花费时间x，单位金币缩减时间z 考虑花费最少金币完成所有任务 保留一位小数
    任务优先先结束的，再优先花费高的
    优先队列维护进行的任务，再维护总的时间，当时间大于当前任务右边界，考虑使用金币，优先使用金币花费少的，因此堆顶应该是花费低的
*/
void init(){
}
struct Work
{
    double z,x,y;
    friend bool operator<(const Work& a,const Work& b)
    {
        if(a.y!=b.y)return a.y<b.y;//优先先结束
        if(a.z!=b.z)return a.z>b.z;//优先花费高
        return a.x<b.x;
    }
};
struct C
{
    double z,x;
    friend bool operator<(const C& a,const C& b)
    {
        return a.z<b.z;//优先花费低
    }
};
void PX()
{
    ll n;cin>>n;
    vector<Work>v(n);
    for(auto &a:v)cin>>a.z>>a.x>>a.y;
    sort(v.begin(),v.end());
    priority_queue<C>q;
    double ans=0;
    double _time=0;
    for(auto i:v){
        _time+=i.x;
        q.push({i.z,i.x});
        while(_time>i.y){
            auto now=q.top();q.pop();
            double del=min(now.x,_time-i.y);
            ans+=del/now.z;_time-=del;now.x-=del;
            if(now.x>0)q.push(now);
        }
    }
    cout<<fixed<<setprecision(1)<<ans<<'\n';
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
