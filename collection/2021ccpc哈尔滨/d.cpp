/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:22:35
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-20 09:38:25
 * @FilePath: \apricitye:\桌面\ACM\collection\2021ccpc哈尔滨\d.cpp
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
/*  D. Math master
    分子分母同时抹去相同集合的数字，使得分数最简且值不变
    最多19位，暴力枚举，模拟验证，注意前导零处理
*/
// int_128  /* don't use IOS */
namespace i128{
inline __int128_t read(){ __int128_t x=0,f=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} while(ch>='0'&&ch<='9'){x*=10;x+=ch-'0';ch=getchar();} return x*f;}
inline void print(__int128_t x){if(x<0)putchar('-'),x=-x; if(x>9)print(x/10); putchar(x%10+'0');}
};
void init(){
}
__int128_t a,b,aa,bb;
vector<__int128_t>A,B;
int la,lb;
int cnta[14]={0},cntb[14]={0};
inline __int128_t geta(int sta)
{
    __int128_t res=0,base=1;
    for(int i=0;i<la;i++){
        if((sta>>i)&1)res+=A[i]*base,base*=10;
    }
    return res;
}
bool check(int sta)
{
    int cntB[12];for(int i=0;i<11;i++)cntB[i]=cntb[i];
    int cntA[12];for(int i=0;i<11;i++)cntA[i]=cnta[i];
    for(int i=0;i<la;i++)if(!((sta>>i)&1))cntB[A[i]]--;
    __int128_t nowa=geta(sta),nowb=nowa*b/a,nowB=nowb;
    if(nowb==0||((nowa*b)%a!=0))return 0;
    while(nowB)cntB[nowB%10]--,nowB/=10;
    for(int i=1;i<=9;i++)if(cntB[i]!=0)return 0;
    if(cntB[0]<0)return 0;
    // zero
    vector<__int128_t>P;
    while(nowb)P.push_back(nowb%10),nowb/=10;
    for(int i=1;i<=cntB[0];i++)P.push_back(0);
    int cp=P.size();
	int nw=0;
	for(int i=0;i<lb;i++)
	{
		if(B[i]==P[nw]) nw++;
		if(nw==cp) return true;
	}
	return false;
}
void PX()
{
    a=i128::read(),b=i128::read();
    aa=a,bb=b;
    A.clear(),B.clear();
    for(int i=0;i<11;i++)cnta[i]=cntb[i]=0;
    while(aa)A.push_back(aa%10),cnta[aa%10]++,aa/=10;
    while(bb)B.push_back(bb%10),cntb[bb%10]++,bb/=10;
    la=A.size(),lb=B.size();
    pair<__int128_t,__int128_t>ans={a,b};
    for(int i=1;i<(1<<la);i++)if(check(i)){
            if(_bug(1))i128::print(geta(i));cout<<'\n';
        if(ans.first>geta(i))ans={geta(i),geta(i)*b/a};
    }
    i128::print(ans.first);cout<<' ';
    i128::print(ans.second);cout<<'\n';
}
int main()
{
#ifdef LOCAL
    freopen("E:\\ACMdream\\in.txt", "r", stdin);
    freopen("E:\\ACMdream\\out.txt", "w", stdout);
    clock_t time1 = clock();
#endif
    // IOS;
    //==================================================
    ll ZPX = 1;
    cin >> ZPX;
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}
