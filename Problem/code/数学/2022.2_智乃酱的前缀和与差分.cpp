/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-15 15:52:51
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-15 15:52:52
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_智乃酱的前缀和与差分.cpp
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
*/
#define MOD _mod
const ll maxn=3e6+111;
int rev[maxn];
void get(int bit){
    for(int i=0;i<(1<<bit);i++)rev[i]=(rev[i>>1]>>1)|((1&i)<<(bit-1));
    return ;
}
void ntt(ll *a,int n,int f){
    get(log2(n));
    for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int i=1;i<n;i<<=1){
        ll wn=_mpow(3,(MOD-1)/(i<<1))%MOD;
        if(f==-1)wn=_mpow(wn,MOD-2);
        for(int j=0;j<n;j+=i<<1){
            ll w=1,x,y;
            for(int k=0;k<i;k++,w=wn*w%MOD){
                x=a[k+j];y=a[k+j+i]*w%MOD;
                a[j+k]=(x+y)%MOD;a[j+k+i]=(x-y)%MOD;
            }
        }
    }
    if(f==1)return ;
    int nv=_mpow(n,MOD-2);
    for(int i=0;i<n;i++)a[i]=a[i]*nv%MOD;
    return ;
}
ll n,k,a[maxn],ki[maxn];
void init(){
    k=(k%MOD+MOD)%MOD;
    ki[0]=1;
    for(ll i=1;i<n;i++) ki[i]=(ki[i-1]*_mpow(i,MOD-2)%MOD)*(i+k-1ll)%MOD;
}
void PX()
{
    cin>>n>>k;init();
    for(int i=0;i<n;i++)cin>>a[i];
    int lens=n<<1,bit=ceil(log2(lens));lens=(1<<bit);
    ntt(ki,lens,1);ntt(a,lens,1);
    for(int i=0;i<lens;i++)ki[i]=ki[i]*a[i]%MOD;
    ntt(ki,lens,-1);
    for(int i=0;i<n;i++)cout<<(ki[i]%MOD+MOD)%MOD<<" \n"[i==n-1];
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
    // init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}