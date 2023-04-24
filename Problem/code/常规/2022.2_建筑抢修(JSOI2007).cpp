/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-19 16:16:26
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-19 16:16:26
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_建筑抢修(JSOI2007).cpp
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
const int N = 1e6+7;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll _mpow(ll a,ll b,ll m=_mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline bool _bug(bool _line=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";
    return 1;
#endif
    return 0;
}
#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"

/*
    [JSOI2007]建筑抢修 <https://ac.nowcoder.com/acm/contest/22904/1005>
    优先队列
    每个建筑有个持续时间和最晚结束时间
    首先按最晚结束时间排序，贪心先结束的先选
    若出现当前不能选的，则要往前找到一个持续时间最长且比当前长的替换掉
*/

void init(){
}
bool cmp(pair<ll,ll>a,pair<ll,ll>b)
{
    if(a.second!=b.second)return a.second<b.second;
    else return a.first<b.first;
}
void PX()
{
    ll n;cin>>n;
    vector<pair<ll,ll>>v(n);
    for(auto &i:v)cin>>i.first>>i.second;
    sort(v.begin(),v.end(),cmp);
    priority_queue<ll>q;
    ll en=0;
    ll ans=0;
    for(auto i:v){
        if(q.empty())q.push(i.first),en+=i.first;
        else if(en+i.first<=i.second)q.push(i.first),en+=i.first;
        else if(q.top()>=i.first)en-=q.top(),q.pop(),q.push(i.first),en+=i.first;
        ans=max(ans,(ll)q.size());
    }
    cout<<ans<<'\n';
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