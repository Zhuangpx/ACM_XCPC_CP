/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-28 18:17:31
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-28 18:20:22
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数学\2022.2_AtCoder_Regular_Contest_136_B.TripleShift.cpp
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
    AtCoder Regular Contest 136 B.Triple Shift    <https://atcoder.jp/contests/arc136/tasks/arc136_b>
    排列奇偶性
    A,B两数组，可对A相邻三个数进行循环右移，即xyz->zxy，询问能否得到B
    操作相当于两次数对交换，因此排列奇偶性不变
    只要AB排列奇偶性一致，就可置换得到
    假如A中某个数出现超过两次，并且AB排列奇偶性不同，显然可以交换两个相同的数使得奇偶性改变(逆序对+1/-1)
*/
void init(){
}
void PX()
{
    ll n;cin>>n;
    vector<ll>a(n),b(n);
    map<ll,ll>mp;bool f1=0,f2=0;
    for(auto &i:a)cin>>i,mp[i]++,f1=mp[i]>1?1:f1;
    for(auto &i:b)cin>>i,mp[i]--;
    for(auto i:a)if(mp[i]){cout<<"No\n";return;}
    if(f1){cout<<"Yes\n";return;}
    ll cnt1=0,cnt2=0;
    for(ll i=1;i<n;i++){
        for(ll j=0;j<i;j++){
            if(a[i]<a[j])cnt1++;
        }
    }
    for(ll i=1;i<n;i++){
        for(ll j=0;j<i;j++){
            if(b[i]<b[j])cnt2++;
        }
    }
    if((cnt1%2)==(cnt2%2))cout<<"Yes\n";
    else cout<<"No\n";
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
