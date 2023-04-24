/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-28 00:53:41
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-13 16:37:47
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.1_智乃酱的子集与超集.cpp
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
// #define INF ~0ULL
// #define mod 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 1e7+7;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}

#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"


/*
    牛客竞赛数据结构专题班前缀和练习题 智乃酱的子集与超集 <https://ac.nowcoder.com/acm/contest/19483/B>
    高维前缀和:每一维做一次前缀和维护，相当于降维，那么k维只需要做k次降维
    考虑每个物体作为一个维度，每个维度两个选值，0表示不选，1表示不选
    那么n维空间下的一个点就是n个物体选择的一个集合
    维护前缀和即为某个集合的所有子集的价值之和
    维护后缀和即为某个集合的所有超集的价值之和
*/
void init(){}
const int _N = 30;
const int _S = 1<<20;   // n<=20
ll n,m,k;
ll a[_N],pres[_S],sufs[_S];
void PX()
{
    cin>>n>>m;
    for(ll i=0;i<n;i++)cin>>a[i];
    // init
    for(ll i=0;i<1<<n;i++){ // i:2^n
        ll s=0;
        for(ll j=0;j<n;j++){  // j:n
            if(i&(1<<j)) s^=a[j];
        }
        pres[i]=sufs[i]=s;
    }
    // 高维前缀和
    for(ll i=0;i<n;i++){    // n次降维
        for(ll j=0;j<1<<n;j++){
            // 当前维度i  枚举集合j
            // 若集合j在第i维值为1 则集合j包含物品i 否则不包含物品i
            // 那么j^(1<<i)和j 只相差一个物品i
            if(j&(1<<i))pres[j]+=pres[j^(1<<i)];    // j为超集
            else sufs[j]+=sufs[j^(1<<i)];           // j为子集
        }
    }
    while(m--){
        cin>>k;
        ll ans=0;   // 集合
        while(k--){
            ll d;cin>>d;
            ans=ans|(1<<d-1);   //  选上物品d 注意d是从1开始 需要减一
        }
        cout<<pres[ans]<<' '<<sufs[ans]<<'\n';
    }
    cout<<'\n';
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