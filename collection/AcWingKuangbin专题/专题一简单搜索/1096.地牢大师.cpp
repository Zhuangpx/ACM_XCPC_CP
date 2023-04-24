/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-05 13:57:24
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-05 19:21:05
 * @FilePath: \apricitye:\桌面\ACM\collection\AcWingKuangbin专题\专题一简单搜索\1096.地牢大师.cpp
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
const int N = 1e4+111;
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
/*  1096. 地牢大师 <https://www.acwing.com/problem/content/description/1098/>
*/
void init(){
}
int l,r,c;
int x,y,z;
char a[102][102][102];
int vis[102][102][102];
int ans;
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
struct C
{
    int x,y,z;
};
bool check(int p,int q) { return p>=1&&p<=q; }
void bfs(int nx,int ny,int nz)
{
    queue<C>q;
    q.push({nx,ny,nz});
    while(!q.empty()){
        auto now=q.front();q.pop();
        for(int i=0;i<6;i++){
            int xx=now.x+dx[i],yy=now.y+dy[i],zz=now.z+dz[i];
            if(check(xx,l)&&check(yy,r)&&check(zz,c)&&vis[xx][yy][zz]==0&&a[xx][yy][zz]!='#'&&a[xx][yy][zz]!='S'){
                vis[xx][yy][zz]=vis[now.x][now.y][now.z]+1;
                q.push({xx,yy,zz});
                if(a[xx][yy][zz]=='E'){
                    ans=vis[xx][yy][zz];return;
                }
            }
        }
    }
}
void PX()
{
    while(cin>>l>>r>>c&&l){
        memset(vis,0,sizeof vis);
        ans=-1;
        for(int i=1;i<=l;i++)for(int j=1;j<=r;j++)for(int k=1;k<=c;k++)
        {
            cin>>a[i][j][k];
            if(a[i][j][k]=='S')x=i,y=j,z=k;
        }
        bfs(x,y,z);
        if(ans>0)cout<<"Escaped in "<<ans<<" minute(s).\n";
        else cout<<"Trapped!\n";
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
