/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:57
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-14 18:49:08
 * @FilePath: \apricity\g.cpp
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
const int mod = 998244353;
const int _mod = 1;
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
/*  G. Occupy the Cities
    01串，初始保证有1，每次可以让每个1将相邻某个0变成1，要求全1最小次数
    //===
    二分答案，贪心check即可
*/
void init(){
}
int cnt;
int wei[N];
ll n;
const int _N=1e6;
string s;
bool check(ll mid)
{
    int l=-1,r=-1;
    int w;
    for(int i=0;i<cnt;i++){
        int now=wei[i];
        l=r,r=1;
        int len;
        if(l==-1){
            len=now;len-=(mid-1);
            if(len>1)return 0;
            else if(len==1)r=0;
        }
        else {
            len=now-w-1;len-=2*(mid-1);
            if(len>2)return 0;
            else if(len<=0)r=1;
            else if(len==2)if(l==0)return 0;else r=0;
            else {if(l==1)r=1;else r=0;}
        }
        w=wei[i];
    }
    int len=n-wei[cnt-1]-1;
    if(r==1&&len)len--;
    return (len<=mid-1);
}
void PX()
{
    cin>>n>>s;
    cnt=0;
    for(int i=0;i<n;i++)if(s[i]=='1')wei[cnt++]=i;
    if(cnt==n){ cout<<"0\n";return; }
    ll l=0,r=n;
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
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
    cin >> ZPX;
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}


