/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:49
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-14 19:10:34
 * @FilePath: \apricity\e.cpp
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
    if(_line)cout<<"_Debug: ";if(line_)cout<<'\n';return 1;
#endif
    return 0;
}
#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"
/*	E. Buy and Delete
	Alice买有向边，Bob删边，且所删边不能成环，Alice要使回合数多，Bob要使回合数少
	//===
	Ailce买不起：0
	Ailce买环：2
	Ailce买非环：1
	问题转换成最小环花费
	Dijsktra求最小花费环即可(多源最短路)
*/

void init(){
}
ll n,m,c;
ll dis[2222][2222];
bool vis[2222];
struct Edge{
	ll ne,to,w;
}e[N];
ll he[N],cnt=0;
//堆优化使用
struct node
{
   	ll dis;
   	ll pos;
	node(ll a,ll b):dis(a),pos(b){};
   	bool operator <(const node& x)const
   	{
   	    return x.dis < dis;
   	}
};
inline void dijsktra(ll n, ll start)
{
    // 初始化走过的点，点start到所有点的距离为无穷
    memset(vis, false, sizeof(vis));
    for(ll i=1; i<=n; i++)
        dis[start][i] = INF;

    priority_queue<node> q;
    dis[start][start] = 0;
    q.push(node(0, start));

   	while(!q.empty())
   	{
    	node tmp = q.top();
       	q.pop();

       	ll x = tmp.pos;//取起点
       	if(vis[x] == true)
        	continue;

       	vis[x] = true;
       	//遍历边
       	for(ll i=he[x]; i!=0; i=e[i].ne)
       	{
           	//列举终点
           	ll y = e[i].to;

           	//松弛
           	if(!vis[y] && dis[start][x] + e[i].w < dis[start][y])
           	{
               	dis[start][y] = dis[start][x]+e[i].w;

               	//确保该点已得到松弛下询问
                q.push((node){dis[start][y], y});

           	}
       	}
   	}
}
inline void adde(ll u,ll v,ll w)
{
	cnt++;e[cnt].ne=he[u];e[cnt].to=v;e[cnt].w=w;he[u]=cnt;
}

void PX()
{
	cin>>n>>m>>c;
	ll minn=INF;
	for(ll i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		adde(u,v,w);minn=min(minn,w);
	}
	if(minn>c){ cout<<"0\n";return; }
	for(ll i=1;i<=n;i++)dijsktra(n,i);
	ll ans=INF;
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(dis[i][j]!=INF&&dis[j][i]!=INF) ans=min(ans,dis[i][j]+dis[j][i]);
		}
	}
	if(c>=ans)cout<<"2\n";
	else cout<<"1\n";
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
