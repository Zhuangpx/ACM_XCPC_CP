/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-22 21:38:05
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-22 21:38:06
 * @FilePath: \apricitye:\桌面\ACM\算法Algorithm\图论\平面点的曼哈顿最小生成树\求平面点的曼哈顿最小生成树边权和.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#pragma GCC optimize(2)
#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
// #include <vector>
using namespace std;
// #define int ull
// #define int ll
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f          //1061109567=1e9
#define INF 0x3f3f3f3f3f3f3f3f  //4557430888798830399=4e18
typedef long long ll;
#define ull unsigned long long
#define UINF ~0ull
#define mod_ 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 1e5+55;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
ll _mpow(ll a,ll b,ll m=_mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline bool _bug(bool _line=0,bool line_=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";if(line_)cout<<'\n';return 1;
#endif
    return 0;
}
/*	D - Another Minimum Spanning Tree	https://vjudge.net/contest/490329#problem/D
	二维平面点的曼哈顿最小生成树 Manhattan MST
	https://www.renrendoc.com/paper/195730692.html
*/
void init(){}
int n,k;
// Point
struct Point{
	int x,y,id;
	bool operator<(const Point& p) const {
		if(x!=p.x) return x<p.x;
		return y<p.y;
	}
}p[N];	//	n
int dist(int u,int v)
{
	return abs(p[u].x-p[v].x)+abs(p[u].y-p[v].y);
}
//	Edge
int tot;
struct Edge{
	int u,v,d;
	bool operator<(const Edge& e) const {
		return d<e.d;
	}
}e[N<<2];	//	n^2
inline void addedge(int u,int v,int d)
{
	e[tot].u=u, e[tot].v=v, e[tot++].d=d;
}
//	BIT
struct BIT{
	int min_val;
	int pos;
	void init() {
		min_val=(1<<30);
		pos=-1;
	}
}bit[N];
#define lowbit(x) (x&(-x))
void update(int x,int val,int pos)	//	update
{
	while(x) {
		if(val<bit[x].min_val) bit[x].min_val=val,bit[x].pos=pos;
		x-=lowbit(x);
	}
}
int query(int l,int r)	//	min of [l,r]
{
	int res=(1<<30),pos=-1;
	while(l<=r) {
		if(bit[l].min_val<res) res=bit[l].min_val,pos=bit[l].pos;
		l+=lowbit(l);
	}
	return pos;
}
//	DSU
int f[N];
inline int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
//
int a[N],b[N];
ll Manhattan_spanning_tree(int n,Point *p){
	//	Init
	tot=0;
    for(int dir=0;dir<4;dir++){
        //4种坐标变换
        if(dir==1||dir==3){
            for(int i=0;i<n;i++)
                swap(p[i].x,p[i].y);
        }
        else if(dir==2){
            for(int i=0;i<n;i++){
                p[i].x=-p[i].x;
            }
        }
        sort(p,p+n);
        for(int i=0;i<n;i++){
            a[i]=b[i]=p[i].y-p[i].x;
        }
        sort(b,b+n);
        int m=unique(b,b+n)-b;
        for(int i=1;i<=m;i++)
            bit[i].init();
        for(int i=n-1;i>=0;i--){
            int pos=lower_bound(b,b+m,a[i])-b+1;   //BIT中从1开始
            int ans=query(pos,m);
            if(ans!=-1)
                addedge(p[i].id,p[ans].id,dist(i,ans));
            update(pos,p[i].x+p[i].y,i);
        }
    }
	//	Solve The Problem
    sort(e,e+tot);
	//	All Edge
	// for(int i=0;i<tot;i++) cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].d<<'\n';
	// cout<<"==\n";
	//	求最小生成树边权和
	ll sum=0;
	for(int i=0;i<n;i++)
		f[i]=i;
	for(int i=0;i<tot;i++) {
		int u=e[i].u, v=e[i].v;
		int fa=find(u), fb=find(v);
		if(fa!=fb) {
			f[fa]=fb;
			sum+=e[i].d;
			//	Use Edge
			// cout<<"Edge:"<<u<<' '<<v<<' '<<e[i].d<<'\n';
		}
	}
	return sum;
	//	求第k大边
	/*
    int cnt=n-k;	//	cnt = n-k	第cnt小
    for(int i=0;i<n;i++)
        f[i]=i;
    for(int i=0;i<tot;i++){
        int u=e[i].u,v=e[i].v;
        int fa=find(u),fb=find(v);
        if(fa!=fb){
            cnt--;
            f[fa]=fb;
            if(cnt==0)
                return e[i].d;
        }
    }
	return -1;
	*/
}
int ti=0;
void PX()
{
	while(cin>>n&&n){
		ti++;
		// cin>>k;	第k大
		for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y,p[i].id=i;
		ll ans=Manhattan_spanning_tree(n,p);
		// cout<<ans<<'\n';
		cout<<"Case "<< ti <<": Total Weight = "<< ans <<'\n';
	}
}
signed main()
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
