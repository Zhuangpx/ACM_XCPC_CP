/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-07 21:45:27
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-07 21:45:27
 * @FilePath: \apricitye:\桌面\ACM\collection\AcWingKuangbin专题\专题一简单搜索\4220.质数路径.cpp
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
/*  4220. 质数路径 <https://www.acwing.com/problem/content/4223/>
*/
map<int,int>mp;
bool check(int x) {  for(int i=2;i*i<=x;i++)if(x%i==0)return 0;return 1;  }
void init(){
    for(int i=1000;i<=9999;i++) mp[i]=check(i);
}
int dis[10001];
void PX()
{
    int x,y;cin>>x>>y;
    if(x==y){cout<<"0\n";return;}
    memset(dis,-1,sizeof dis);dis[x]=0;
    queue<int>q;q.push(x);
    int a[4]={0,0,0,0},d[4]={1000,100,10,1};
    while(!q.empty()){
        auto now=q.front();q.pop();
        for(int i=now,j=3;i;i/=10,j--)a[j]=i%10;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=3;j++){
                if(!(i+j))continue;
                int p=now+d[j]*(i-a[j]);
                if(mp[p]&&dis[p]<0)q.push(p),dis[p]=dis[now]+1;
                if(p==y){cout<<dis[p]<<'\n';return;}
            }
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
    cin >> ZPX;
    init();
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}
