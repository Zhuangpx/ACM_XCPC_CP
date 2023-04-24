/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-15 12:00:26
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-15 12:00:26
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_智乃酱的静态数组维护问题多项式.cpp
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
    牛客竞赛数据结构专题班前缀和练习题 智乃酱的静态数组维护问题多项式 <https://ac.nowcoder.com/acm/contest/19483/D>
    多项式前缀和:
        设有多项式f(x)=a[k]*x^k+a[k-1]*x^(k-1)+...+a[1]*x+a[0]，每次对一个区间[l,r]依次进行一个a[l+i-1]+=f(i)的操作。
        容易发现对[l,r]+=f[i]相当于对[l,n]+=f[i]和[r+1,n]-=f[r-l+1+i]
        引入这样一个数学定理:最高项为n次的n阶多项式做n+1次差分后余项为常数(0)
        并且再继续进行差分明显不会影响，也就是做n+1以上次差分能保证余项为常数(0)。
    阶数最大为5,进行6次差分保证余项为0，然后再6次还原，第7次求前缀和
*/

void init(){
}
inline void _D(vector<ll>& a,const ll& len,ll cnt)  //差分
{
    while(cnt--){
        for(ll i=len;i>=1;i--)a[i]=(a[i]-a[i-1]+mod)%mod;
    }
}
inline void _S(vector<ll>& a,const ll& len,ll cnt)  //前缀和
{
    while(cnt--){
        for(ll i=1;i<=len;i++)a[i]=(a[i]+a[i-1])%mod;
    }
}
inline ll _F(ll x,vector<ll>& a,const ll& len)  //多项式
{
    ll base=1,res=0;
    for(ll i=0;i<=len;i++){
        res=(res+a[i]*base%mod)%mod;
        base=base*x%mod;
    }
    return res;
}
void PX()
{
    ll n,m,q;cin>>n>>m>>q;
    vector<ll>d(n+10,0);
    for(ll i=1;i<=n;i++)cin>>d[i];
    _D(d,n,6);
    while(m--){
        ll l,r,k;cin>>l>>r>>k;
        vector<ll>a(10,0);
        for(ll i=k;i>=0;i--)cin>>a[i];
        vector<ll>lf(10,0),rf(10,0);
        for(ll i=1;i<=6;i++){ //求多项式f[x]->x:[1,k+1]
            lf[i]=_F(i,a,k);
            rf[i]=(mod-_F(r-l+1+i,a,k))%mod;
        }
        //k阶多项式k+1次差分
        _D(lf,6,6);
        _D(rf,6,6);
        for(ll i=1;i<=6;i++){ //赋值
            d[l+i-1]=(d[l+i-1]+lf[i])%mod;
            d[r+i]=(d[r+i]+rf[i])%mod;
        }
    }
    _S(d,n,7);
    while(q--){
        ll l,r;cin>>l>>r;
        cout<<((d[r]-d[l-1])%mod+mod)%mod<<'\n';
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