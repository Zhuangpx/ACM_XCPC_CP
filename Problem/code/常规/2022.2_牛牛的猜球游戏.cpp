/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-13 18:17:07
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-13 22:04:35
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_牛牛的猜球游戏.cpp
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
inline bool _bug(bool _line=0){
#ifdef LOCAL
    if(_line)cout<<"_Debug: ";
    return 1;
#endif
    return 0;
}
#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"

/*
    牛客竞赛数据结构专题班前缀和练习题 牛牛的猜球游戏 <https://ac.nowcoder.com/acm/contest/19483/F>
    广义前缀和+置换前缀和
    a序列长为10，初始 0-9 进行n次交换，每次交换a[l]-a[r]
    m次提问，给出交换区间[l,r]求结果
    考虑交换结果叠加与抵消，交换区间下的结果:[l,r]=[0,r]-[0,l-1] 减表示抵消(置换)
    考虑如何抵消[0,l-1]即[0,k]的交换 只需抵消结果即可 不需在乎过程
*/

void init(){
}
void PX()
{
    int n,m;cin>>n>>m;
    vector<vector<ll>>a(n+1,vector<ll>(10));
    iota(a[0].begin(),a[0].end(),0);
    for(int i=1;i<=n;i++){
        int _l,_r;cin>>_l>>_r;
        a[i]=a[i-1];
        swap(a[i][_l],a[i][_r]);
    }
    while(m--){
        int _l,_r;cin>>_l>>_r;
        vector<ll>c(10);
        for(int i=0;i<10;i++){
            c[a[_l-1][i]]=i;    // a[_l-1][i]位置上为p p为原来的i
        }
        for(int i=0;i<10;i++){
            cout<<c[a[_r][i]]<<' ';     // a[_r][i]位置上为p p为原来的c[p]
        }
        cout<<'\n';
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