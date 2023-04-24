/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-20 15:09:27
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-20 15:09:27
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_[牛客]背包.cpp
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
    [牛客]背包 <https://ac.nowcoder.com/acm/contest/22904/1007>
    优先队列+二分
    容量v的背包有n个物品，选m个求最大中位数
    排序，中位数的选择
    如m是奇数，考虑当前i和i左边m/2和i右边m/2
        优先队列维护，满足体积最小，再去枚举i取最大值
    如m是偶数，考虑当前i和i左边m/2-1和i右边m/2
        优先队列维护，满足体积最小，再去枚举i，再确定i之下枚举另一个中间数
        由于贡献有序，且由于优先队列维护，体积也有序，因此可以二分枚举
*/

void init(){
}
void PX()
{
    ll n,v,m;cin>>v>>n>>m;
    vector<pair<ll,ll>>a;
    a.push_back({0,0});
    for(ll i=1;i<=n;i++){
        ll x,y;cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end()); // i.first<j.first__i<j
    priority_queue<ll,vector<ll>,less<ll>>q;
    vector<ll>s1(n+5,0),s2(n+5,0);
        if(_bug(1,1))for(auto i:a)cout<<i.first<<' '<<i.second<<'\n';
    for(ll i=1;i<=n;i++){
        q.push(a[i].second);
        s1[i]=s1[i-1]+a[i].second;
        if(q.size()>(m-1)/2){   // 8-3__9-4
            s1[i]-=q.top();
            q.pop();
        }
    }
    while(!q.empty())q.pop();  //clear
    for(ll i=n;i>=1;i--){
        q.push(a[i].second);
        s2[i]=s2[i+1]+a[i].second;
        if(q.size()>m/2){   // 8-4__9-4
            s2[i]-=q.top();
            q.pop();
        }
    }
    ll ans=0;
    if(m&1){
        for(ll i=m/2;i<=n-m/2;i++){  // 9__[4,n-4]__4+1+4
            if(s1[i-1]+s2[i+1]+a[i].second<=v) ans=a[i].first;
        }
        cout<<ans<<'\n';
    } else {
        for(ll i=m/2;i<=n-m/2;i++){  // 8__[4,n-4]__3+1+4
            ll l=i+1,r=n-m/2+1; // _l=i _r=[i+1,n-m/2+1)
            while(l<=r){
                ll mid=(l+r)>>1;
                if(s1[i-1]+s2[mid]+a[i].second<=v)l=mid+1;
                else r=mid-1;
            }
            if(r>i)ans=max(ans,a[i].first+a[r].first);
        }
        cout<<ans/2<<'\n';
    }
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


