/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:35
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-14 23:20:29
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
/*  D. Assumption is All You Need
    全排列A，B，可交换逆序对，考虑能否从A转到B
    考虑当前i，前i-1已排好
    a[i]=b[i]，无须操作
    a[i]<b[i]，由于只能逆序对交换，无法从后面往前交换使得a[i]变大，因此无解
    a[i]>b[i]，考虑j从i+1往后扫，如果a[i]>a[j]&&a[j]>=b[i]就进行swap(a[i],a[j])
            这样能保证较大的a[k]尽可能保持考前，如下:
            4 3 2 1 -> 3 4 2 1 -> 2 4 3 1 -> 1 4 3 2
*/

void init(){
}
void PX()
{
    ll n;cin>>n;
    vector<ll>a(n),b(n);
    vector<pair<ll,ll>>ans;
    for(auto &i:a)cin>>i;for(auto &i:b)cin>>i;
    for(ll i=0;i<n;i++){
        if(a[i]==b[i])continue;
        if(a[i]<b[i]){ cout<<"-1\n";return; }
        ll j=i+1;
        while(a[i]>b[i]){
            if(a[i]>a[j]&&a[j]>=b[i])swap(a[i],a[j]),ans.push_back({i+1,j+1});
            j++;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i.first<<' '<<i.second<<'\n';
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
