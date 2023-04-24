/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:35
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-07 11:52:00
 * @FilePath: \apricity\d.cpp
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
const int N = 1e6+111;
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
/*  D. Period
    转化一下问题就是判前后缀相同，然后进行后缀和，考虑用hash(或kmp)
*/

void init(){
}
const int P=131;//13331
//const int Q=pow(2,64);
ull h[N];//hash
ull p[N];//p
void init(string s)
{
    p[0]=1;//p^0==1
    for(int i=1;i<=s.size();++i){
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+s[i-1]; //s=>[0,size)
    }
}
ull get(int l,int r)    //hash=>[l,r]
{
    return h[r]-h[l-1]*p[r-l+1];
}
int a[N];
ll b[N];
void PX()
{
    string s;cin>>s;
    int n=s.size();
    ull x,y;
    init(s);
    for(int i=n-1;i>0;i--){
        x=get(i+1,n),y=get(1,n-i);
        if(x==y)a[i+1]=1;else a[i+1]=0;
        b[i+1]=b[i+1+1]+a[i+1];
    }
    ll q;cin>>q;
    // for(ll i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
    // for(ll i=1;i<=n;i++)cout<<b[i]<<" \n"[i==n];
    while(q--){
        ll d;cin>>d;
        if(d<=n/2){
            ll len=n-d+2;
            cout<<b[len]<<'\n';
        }
        else {
            ll len=d+1;
            cout<<b[len]<<'\n';
        }
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
    //cin >> ZPX;
    
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}
