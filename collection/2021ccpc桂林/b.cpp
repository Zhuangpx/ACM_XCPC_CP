/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:27
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-15 19:53:03
 * @FilePath: \apricity\b.cpp
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
/*  B. A Plus B Problem
    给串A和B，加起来得到串C，保留C和AB等长部分，然后询问
    每次询问将串r的第c位变成d，输出串C的第c位和三个串改变的数位总和
    //===
    考虑维护和非9位置，每次修改判断当前位变化，和前面连续9位置是否会改变
*/
void init(){
}
void PX()
{
    ll n,q;cin>>n>>q;
    vector<string>str(2);cin>>str[0]>>str[1];
    set<ll>s;s.insert(0),s.insert(n+1); //  哨兵0 n+1
    vector a(2,vector<ll>(n+2,0));
    for(ll j=0;j<2;j++)for(ll i=0;i<n;i++)a[j][i+1]=str[j][i]-'0';
    for(ll i=1;i<=n;i++)if(a[0][i]+a[1][i]!=9)s.insert(i);  //  和非9的位置
    while(q--){
        ll r,c,d;cin>>r>>c>>d;r--;
        s.erase(c); //  修改位先擦除
        auto it=s.lower_bound(c);   //  找到c后面一个和非9位置it，如果r1[it]+r2[it]>=10那么后面会往c位进位，it-1即c前面第一个和非9位置
        ll pre=a[r^1][c]+a[r][c]+(a[0][*it]+a[1][*it]>=10); //  修改前
        ll now=a[r^1][c]+d+(a[0][*it]+a[1][*it]>=10);   //  修改后
        a[r][c]=d;  //  修改
        if(pre==now)cout<<now%10<<" 0\n";   //  修改后不变
        else if((pre<10)^(now<10))--it,cout<<now%10<<" "<<2+c-max(1ll,(*it))<<'\n';  //  修改前后进位情况不一致，往前和非9位置都会改变
        else cout<<now%10<<" 2\n";  //  修改前后进位情况一致，只会改变当前位
        if(a[0][c]+a[1][c]!=9)s.insert(c);  //  和非9插入
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
