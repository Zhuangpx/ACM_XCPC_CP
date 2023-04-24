/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-19 15:08:31
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-19 15:08:31
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\玄学\2022.2_异或矩阵.cpp
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
    牛客挑战赛57 异或矩阵 <https://ac.nowcoder.com/acm/contest/11197/B>
    n*m矩阵按1-n*m排 求出子矩阵异或和最大值并构造出满足的子矩阵
    异或和最大值必然是ans=11..11b的形式，考虑如何构造11..11b
    首先找到x=10..00b和y=01..11b（y+1==x），如果相邻那么构造这两个即可
    如果不相邻那必然是y在一行末尾，而x在下一行开头，此时对构造这两行的子矩阵即可，证明如下：
    容易知道x^y==ans，并且发现(y-1)^(x+1)==ans，继续推得到(y-cnt)^(x+cnt)==ans，因此只要保证有奇数对这样的数即可
    由于x%2==0而x%m==1(x在第一列)，因此必然有m%2==1，因此这样的数是奇数对，证毕
*/

void init(){
}

void PX()
{
    ll n,m;cin>>n>>m;
    if(n==1&&m==1){
        cout<<"1\n1 1 1 1\n";
        return ;
    }
    ll cnt=60;
    ll ma=n*m;
    while((ma>>cnt)%2==0)cnt--;
    ll res=(1ll<<cnt)-1;
    ll ans=(1ll<<(cnt+1))-1;
    cout<<ans<<'\n';
    if(res%m==0){
        ll _x=res/m;
        cout<<_x<<" 1 "<<_x+1<<' '<<m<<'\n';
    }
    else {
        ll _x=res/m+1,_y=res%m;
        cout<<_x<<' '<<_y<<' '<<_x<<' '<<_y+1<<'\n';
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