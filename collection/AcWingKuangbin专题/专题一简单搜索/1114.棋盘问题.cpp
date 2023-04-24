/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-05 13:56:37
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-05 13:56:38
 * @FilePath: \apricitye:\桌面\ACM\collection\AcWingKuangbin专题\专题一简单搜索\1114.棋盘问题.cpp
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
const int N = 1e5+111;
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
/*  1114. 棋盘问题 <https://www.acwing.com/problem/content/description/1116/>
    dfs爆搜
*/
void init(){
}
int n,k;
int ans;
bool vis[10];
char a[10][10];
void dfs(int c,int cnt)
{
    if(cnt==k){ans++;return;}
    if(c>=n)return;
    for(int i=0;i<n;i++)
        if(!vis[i]&&a[c][i]=='#')
            vis[i]=1,dfs(c+1,cnt+1),vis[i]=0;
    dfs(c+1,cnt);
}
void PX()
{
    while(cin>>n>>k&&n>0){
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
        ans=0;dfs(0,0);
        cout<<ans<<'\n';
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
