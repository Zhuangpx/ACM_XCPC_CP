/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:49
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-19 22:10:16
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
/*	E. Power and Modulo
	找出唯一的M使得A[i]=2^(i-1)%M (i=[1,2,..,n])，M不唯一或不存在都是-1
	分类讨论
	先考虑A[1],如果A[1]=0，那么后续都应该是0并且M=1,否则如果A[1]!=1显然是不存在合法的M
	不满足上述条件的话，那么此时A[1]=1，容易得到A[2]=2*A[1]，同理A[i]=2*A[i-1]，如果某个j不满足，那么就能得出M来，显然M=2^j-A[j]
	此时在考虑A[j]，如果A[j]=0，那么后续都得是0，否则利用M去检验后面的A[i]即可
	注意一种特殊情况，即A[i]=2^(i-1)，不能找出唯一的M，此时M是无限可能的
*/
void init(){
}
ll a[N];
void PX()
{
	int n;cin>>n;
	int flag=1;
	bool ok=1;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)num++;
		if(a[1]==0&&i>1&&a[i]!=0)flag=0;
		if(a[1]!=1)ok=0;
	}
	if(num==n){
		cout<<1<<endl;return;
	}
	if(!flag||!ok){
		cout<<-1<<endl;return;
	}
	for(int i=2;i<=n;i++){
		ll temp=2*a[i-1];
		if(temp==a[i])continue;
		else {
			if(a[i]>=a[i-1]){
				cout<<-1<<endl;return;
			}
			ll le=a[i-1],ri=temp;
			ll ans=ri-a[i];
			int len=i-1;
			ll x=a[i];
			if(a[i]==0){
				for(int j=i+1;j<=n;j++){
					if(a[j]!=0){cout<<-1<<endl;return;}
				}
				cout<<ans<<endl;return;
			}
			for(int j=i+1;j<=n;j++){
				ll tmp=x*2;
				if(tmp>=ans)tmp%=ans;
				if(a[j]!=tmp){cout<<-1<<endl;return;}
				x=a[j];
			}
			cout<<ans<<endl;return;
		}
	}
	cout<<-1<<endl;
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
