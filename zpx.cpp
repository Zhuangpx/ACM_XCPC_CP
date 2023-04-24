/*
 * @Autor: violet apricity (zpx)
 * @Date: 2021-09-12 10:23:25
 * @LastEditors: violet apricity (zpx)
 * @LastEditTime: 2021-09-12 10:23:25
 * @FilePath: \apricitye:\桌面\ACM\zpx.cpp
 * @Description: Violet && Apricity:/ The warmth of the sun in the winter /
 */
        // violet apricity
        // Do all I can do.Do good to be good.
//g++  ./violet/run.cpp -o ./violet/run.exe
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<sstream>
#include<numeric>
#include<queue>
#include<iomanip>
#include<fstream>
#include<unordered_map>
#include<stack>
#include<set>
#include<random>

//#include<bits/stdc++.h>

#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f3f3f3f
#define r0 return 0;
#define SYP system("pause");
#define lowbit(x) ((x) & -(x))
//#define endl '\n'
using namespace std;

const ll mod=1e9+7;
//const ll mod=1e7;

ll gcd(ll a,ll b){ll d;while(b){d=b;b=a%b;a=d;} return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll _pow(ll a,ll b){ll d=1;while(b){if(b&1)d*=a; a*=a;b>>=1;} return d;}
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
void exgcd(ll a,ll b,ll &g,ll &x,ll &y){if(!b){g=a;x=1;y=0;} else {exgcd(a,b,g,y,x);y-=x*(a/b);}}

/*
inline __int128_t read(){ __int128_t x=0,f=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} while(ch>='0'&&ch<='9'){x*=10;x+=ch-'0';ch=getchar();} return x*f;}
inline void print(__int128_t x){if(x<0)putchar('-'),x=-x; if(x>9)print(x/10); putchar(x%10+'0');}
*/

//#define int long long

//=====================================================================

const int N=2e5+5;

/*
ll jie[N],tow[N];
void init()
{
    jie[0]=1;
    for(int i=1;i<N;i++)jie[i]=jie[i-1]*i%mod;
    tow[N-1]=mpow(jie[N-1],mod-2,mod);
    for(int i=N-2;i>=0;i--) tow[i]=tow[i+1]*(i+1)%mod;
}
ll cal(ll n,ll m){if(m>n) return 0; return jie[n]*tow[m]%mod*tow[n-m]%mod; }
*/

struct dsu {   //DSU
	vector<int> f;
	dsu(int n) :f(n) { iota(f.begin(), f.end(), 0); }
	int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
	void merge(int x, int y) {
		x = find(x); y = find(y);
		if (x > y)swap(x, y);
		f[y] = x;
	}
};

/*
ll pri[N],privis[N],pritot;  //getprimes

void getpri(ll n) //(pri)-allprime (privis)-ispri (pritot)-cntpri
{privis[2]=0;for(ll i=2;i<=n;i++){if(!privis[i])pri[++pritot]=i; for(ll j=1;j<=pritot&&i*pri[j]<=n;j++){privis[pri[j]*i]=1; if(i%pri[j]==0)break; }}}

ll phi[N];
void getphi(ll n)
{
    phi[1]=1;
    for(ll i=2;i<=n;i++){
        if(!privis[i]) {phi[i]=i-1; pri[pritot++]=i; }
        for(ll j=1;j<=pritot&&i*pri[j]<=n;j++){
            privis[i*pri[j]]=1;
            if(i%pri[j]) { phi[i*pri[j]]=phi[i]*(pri[j]-1); }
            else { phi[i*pri[j]]=phi[i]*pri[j]; break; }
        }
    }
}
*/

//=====================================================================

#define pCase(t,d) cout<<"Case #"<<(t)<<": "<<(d)<<'\n'
#define pNO cout<<"NO\n"
#define pYES cout<<"YES\n"
#define pNo cout<<"No\n"
#define pYes cout<<"Yes\n"
#define pno cout<<"no\n"
#define pyes cout<<"yes\n"
#define pdebug(ans) cout<<"ans:"<<(ans)<<'\n'
#define pshow(x) cout<<" show:"<<(x)<<'\n'
#define p(ans) cout<<(ans)<<'\n'
#define pdec(t,ans) cout<<std::fixed<<std::setprecision(t)<<(ans)<<'\n'

//=====================================================================



//=====================================================================

int main()
{
#ifdef LOCAL
    //ifstream cin("E:\\ACMdream\\in.txt");
    //ofstream cout("E:\\ACMdream\\out.txt");
    freopen("E:\\ACMdream\\in.txt","r",stdin);
    freopen("E:\\ACMdream\\out.txt","w",stdout);
#endif
    //IOS

    //======================================================================

    ll t=1;
    //cin>>t;
    while(t--){
    }

    //======================================================================

    //SYP
    return 0;
}