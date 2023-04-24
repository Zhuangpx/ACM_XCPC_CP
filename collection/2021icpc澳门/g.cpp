/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-05 20:11:56
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-05 20:16:04
 * @FilePath: \apricitye:\桌面\ACM\collection\2021icpc澳门\g.cpp
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
const int mod = 998244353;
const int _mod = 1;
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
/*  G. Cyclic Buffer
    dp[i][0/1]:把前i个数i转到左/右的步数
    gol[i]:把i转到左之后下一个不在范围内的数
    gor[i]:把i转到右之后下一个不在范围内的数
    注意答案应该是min(dp[n+1][0/1]) 因为每次只会从i向i+1推
*/
void init(){
}
int n,k;
int p[N],pos[N],gol[N],gor[N];
ll dp[N][2];
void PX()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>p[i];      //  p[x]=y : x位置上的数为y
        pos[p[i]]=i;    //  pis[x]=y : 数x的位置为y
    }
    if(n==k) {  //  全部在内
        cout<<"0\n";return ;
    }
    set<int> d;     //  集合维护不在[0,k-1]范围内的数
    for(int i=k;i<n;i++) d.insert(p[i]);
    //  预处理每个数x转到边界之后，下一个>x且不在[0,k-1]范围内的数
    for(int i=0;i<n;i++) {  //  枚举左边的数l，依次往左转
        int l=p[i], r=p[(i+k-1)%n];      //  假如左边为l，那么右边就为r
        auto it1=d.lower_bound(l);       //  找到第一个>l且不在[0,k-1]范围的数
        if(it1==d.end()) gol[l]=n+1; else gol[l]=*it1;
        auto it2=d.lower_bound(r);       //  找到第一个>r且不在[0,k-1]范围的数
        if(it2==d.end()) gor[r]=n+1; else gor[r]=*it2;
        //  往左转一位之后l会出[0,k-1] 而r的下一个会进[0,k-1]
        d.erase(p[(i+k)%n]);d.insert(l);
    }
    for(int i=1;i<=n+1;i++) dp[i][0]=dp[i][1]=(1ll<<60);
    bool mov=0;
    auto go=[&](int p,int pos0,int id,int pos1) {
        //  id从pos1转到pos0需要的步数 p表示id原先位置
        if(id==n+1) return 0;   //  无此数
        int qpos=(pos[id]-(pos0-p))%n;
        if(qpos<0) qpos+=n;
        return min( abs(pos1-qpos) , n-abs(pos1-qpos) );
    };
    for(int i=1;i<=n;i++) {
        if(pos[i]>=k&&!mov) {   //  i不在范围内且未转动 (显然是第一个数即pos[i]==0)
            dp[i][0] = go(0,0,i,0);
            dp[i][1] = go(0,0,i,k-1);
            mov=1;
        }
        if(mov) {   //  转过
            dp[gol[i]][0] = min( dp[gol[i]][0] , dp[i][0]+go(0,pos[i],gol[i],0) );
            dp[gol[i]][1] = min( dp[gol[i]][1] , dp[i][0]+go(0,pos[i],gol[i],k-1) );
            dp[gor[i]][0] = min( dp[gor[i]][0] , dp[i][1]+go(k-1,pos[i],gor[i],0) );
            dp[gor[i]][1] = min( dp[gor[i]][1] , dp[i][1]+go(k-1,pos[i],gor[i],k-1) );
        }
    }
    cout<<min(dp[n][0],dp[n][1])<<'\n';
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
    while (ZPX--)   PX();
    // system("pause");
    //==================================================
#ifdef LOCAL
    std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
#endif
    return 0;
}


