/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-05 17:49:26
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-05 18:49:01
 * @FilePath: \apricitye:\桌面\ACM\collection\2021icpc澳门\f.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */


#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
typedef long long ll;
#define ull unsigned long long
#define UINF ~0ull
#define mod_ 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 5e5+55;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll _mpow(ll a,ll b,ll m=_mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline bool _bug(bool _line=0,bool line_=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";if(line_)cout<<'\n';return 1;
#endif
    return 0;
}
#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"
/*  F. Sandpile on Clique
    一种做法是设一个跑的次数上限_N，模拟一遍
    另一种做法来自dls
    首先对于一次操作就是某个数-(n-1)即-n+1，其他数+1，容易发现他们都是在%n意义下+1
    对所有的数%n，然后去枚举与后结果加上的数，即%n意义下同时的偏移量
    如果某种状态下数的和和初始相等，且所有数都是<n-1的，那么它就是合法状态
    最后根据合法状态的数量，如果仅有一个那么它就是最终结果，否则就是无限循环
*/
void init(){
}
/*  做法一
int a[N];
vector<pair<ll,ll>> ans;
priority_queue<pair<ll,ll> >P;
bool cmp(pair<ll,ll>a,pair<ll,ll>b)
{
    return a.second<b.second;
}
const ll _N=1e6;
void PX()
{
    ll sum=0;
    ll n;cin>>n;
    ll cnt=0;
    ll f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];sum+=a[i];
        if(a[i]>=n-1)
        {
            f=(a[i]/(n-1));
            a[i]%=(n-1);
            a[i]-=f;
            cnt+=f;
        }
        P.push({a[i],i});
    }
    ll cur=0;
    while(1)
    {
        cur++;
        if(cur>_N){
            cout<<"Recurrent"<<'\n';return;
        }
        auto x=P.top();
        if(x.first+cnt<n-1)
        {
            while(!P.empty()){
                ans.push_back(P.top());
                P.pop();
            }
            sort(ans.begin(),ans.end(),cmp);
            for(int i=0;i<n;i++)cout<<ans[i].first+cnt<<" \n"[i==n-1];
            return;
        }
        P.pop();
        ll now=x.first+cnt;
        f=now/(n-1);
        cnt+=f;
        now%=(n-1);
        now-=cnt;
        P.push({now,x.second});
    }
}
*/

/*  做法二
*/
int n;
int cnt[N];
void PX()
{
    cin>>n;
    vector<int>a(n);
    ll s=0,sum=0;
    ll p=0;
    for(auto &i:a){
        cin>>i;
        p+=i/n;
        sum+=i;
        i%=n;
        s+=i;
    }
    for(auto i:a)cnt[i]++;
    for(int i=n;i>=0;i--)cnt[i]+=cnt[i+1];
    int ans=-1;     //  唯一偏移答案
    for(int i=0;i<n;i++){   //  枚举偏移
        ll now = s + 1ll*i*n - 1ll*cnt[max(n-i-1,0)]*n;
        // n-1-i个数溢出，每个减去n
        if(now==sum){
            if(ans!=-1) {
                cout<<"Recurrent\n";
                return ;
            }
            else ans=i;
        }
    }
    if(ans==-1){
        cout<<"Recurrent\n";return ;
    }
    for(int i=0;i<n;i++) cout<<(a[i]+ans)%n<<" \n"[i+1==n];
}
signed main()
{
#ifdef LOCAL
    freopen("E:\\ACMdream\\in.txt", "r", stdin);
    freopen("E:\\ACMdream\\out.txt", "w", stdout);
    clock_t time1 = clock();
#endif
    // IOS;
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
