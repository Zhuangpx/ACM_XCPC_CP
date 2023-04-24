/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-07 21:25:25
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-07 21:27:35
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数据结构\2022.2_第十四届吉林省赛_F_Queue.cpp
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
// #define INF ~0ULL
// #define mod 99993
const int mod = 1e9+7;
const int _mod = 998244353;
const int N = 1e5+7;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}

#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"

inline bool _bug(){
#ifdef LOCAL
    return 1;
#endif
    return 0;
}

/*
    <https://codeforces.ml/gym/102800>
    `Problem`:[cfgym]第十四届吉林省赛_F_Queue
    `tag`:逆序对(树状数组)
    先求出逆序对
    每次交换元素 a[_l] a[_r]
    由于 _r-_l<=100 因此可以暴力维护
    考虑 _l<i<_r 将a[i]与a[_l],a[_r]比较 分类讨论得到改变量
    注意还有 <a[_l],a[_r]> 这一对改变
    维护最小值然后更新即可
*/


void init(){
}
ll d[N];
int a[N];
int n;
ll cnt,ans;
inline void add(int x,int c)
{
    while(x<N){
        d[x]+=1ll*c;
        x+=lowbit(x);
    }
}
inline ll getsum(int x)
{
    ll res=0;
    while(x>0){
        res+=d[x];
        x-=lowbit(x);
    }
    return res;
}
void PX()
{
    memset(d,0,sizeof d);cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]++;
    for(int i=1;i<=n;i++){
        cnt+=(1ll*i-1ll-getsum(a[i]));
        add(a[i],1);
    }
    ans=cnt;
    int m;cin>>m;
    while(m--){
        int _l,_r;cin>>_l>>_r;
        if(_l==_r)continue;
        int _add=(a[_r]>a[_l]),_sub=(a[_l]>a[_r]);
        for(int i=_l+1;i<_r;i++){
            _add+=(a[i]>a[_l])+(a[i]<a[_r]);
                    if(_bug())cout<<"add:"<<_add<<'\n';
            _sub+=(a[i]>a[_r])+(a[i]<a[_l]);
                    if(_bug())cout<<"sub:"<<_sub<<'\n';
        }
                    if(_bug())cout<<"add:"<<_add<<" sub:"<<_sub<<'\n';
        swap(a[_l],a[_r]);
        cnt+=_add*1ll;
        cnt-=_sub*1ll;
                    if(_bug())cout<<"cnt:"<<cnt<<'\n';
        ans=min(ans,cnt);
    }
    cout<<ans<<'\n';
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