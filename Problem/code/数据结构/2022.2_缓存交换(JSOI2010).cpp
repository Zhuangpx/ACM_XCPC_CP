/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-19 22:24:53
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-19 22:26:01
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数据结构\2022.2_缓存交换(JSOI2010).cpp
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
const int N = 1e5+7;
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
    JSOI2010]缓存交换 <https://ac.nowcoder.com/acm/contest/22904/1006>
    优先队列+贪心
    假如cache未满则miss并加入，已有当前编号则命中
    假如cache已满且当前编号不存在cache中，考虑弹出
    贪心将下一次出现时机靠后的弹出，用优先队列维护cache里每个数对应下一次出现的时机(小根堆)，每次弹出堆顶即可
*/

void init(){
}

void PX()
{
    ll n,m;cin>>n>>m;
    vector<ll>v(n);
    for(auto &a:v)cin>>a;
    map<ll,ll>mp;
    map<ll,ll>nex;
    for(ll i=n-1;i>=0;i--){
        if(mp[v[i]]==0)nex[i]=n+i+5;
        else nex[i]=mp[v[i]];
        mp[v[i]]=i;
    }
    ll ans=0;
    ll cnt=0;
    priority_queue<ll>q;
    map<ll,bool>vis;
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            ans++;
            if(cnt<m){
                cnt++;
                q.push(nex[i]);
                vis[nex[i]]=1;
            }
            else {
                vis[q.top()]=0;
                q.pop();
                q.push(nex[i]);
                vis[nex[i]]=1;
            }
        }
        else {
            vis[nex[i]]=1;
            q.push(nex[i]);
        }
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