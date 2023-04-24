/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-07 19:26:10
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-07 19:26:11
 * @FilePath: \apricitye:\桌面\ACM\collection\AcWingKuangbin专题\专题一简单搜索\4318.翻转.cpp
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
/*  4218. 翻转 <https://www.acwing.com/problem/content/description/4221/>
*/
void init(){
}
void PX()
{
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    int m,n;cin>>m>>n;
    vector<vector<int>>a(m+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    auto b=a;
    vector<vector<int>>ans(m+1,vector<int>(n+1,0));
    auto ref=[&](int x,int y){
        b[x][y]^=1;ans[x][y]++;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<m&&ny<n)b[nx][ny]^=1;
        }
    };
    for(int i=0;i<(1<<n);i++){
        for(auto &p:ans)for(auto &q:p)q=0;
        b=a;
        for(int j=0;j<n;j++)if(i>>j&1)ref(0,j);
        for(int j=0;j<m-1;j++)for(int k=0;k<n;k++)if(b[j][k])ref(j+1,k);
        bool ok=1;
        for(int j=0;j<m;j++)for(int k=0;k<n;k++)if(b[j][k]){ok=0;break;}
        if(ok){
            for(int j=0;j<m;j++)for(int k=0;k<n;k++)cout<<ans[j][k]<<" \n"[k==n-1];
            return ;
        }
    }
    cout<<"IMPOSSIBLE\n";
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
