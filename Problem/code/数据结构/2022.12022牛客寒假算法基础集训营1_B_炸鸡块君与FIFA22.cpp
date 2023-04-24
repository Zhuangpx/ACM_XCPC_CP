/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-01-25 21:46:03
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-01-25 21:46:04
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\数据结构\2022.12022牛客寒假算法基础集训营1_B_炸鸡块君与FIFA22.cpp
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
const int N = 1e6+7;
const long double eps=1e-8;
ll mpow(ll a,ll b,ll m=mod){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}

#define pYES cout<<"YES\n"
#define pNO cout<<"NO\n"


/*
    打排位，给出n和长为n的字符串s，L败-1，W赢+1，D平局，注意到当分数是3的倍数时，L不扣分
    给出起始分数和s一段区间，求最终得分
    容易发现起始分数%3得到的结果决定了最终得分，也就是说%3结果一直那么区间分数变化也一致
    因此可以根据余数0 1 1分别维护区间分数变化
    经典rmq，可以倍增分块，ST表，树状数组，线段树，不需要动态维护只需要静态预处理，因此这里用ST表
*/

ll _log[N];     //N=1e6+7
ll st[3][N][21];   //2^20>1e6
ll _logn=20;    //max logn
void init()     //这里区间求和 倍增即可 不需要区间覆盖所以其实不需要log
{
    _log[1]=0;
    for(ll i=1;i<N;i++)_log[i]=_log[i/2]+1;
}
void PX()
{
    ll n,q;cin>>n>>q;
    string s;cin>>s;s=" "+s;
    for(ll i=1;i<=n;i++){
        if(s[i]=='W')st[0][i][0]=st[1][i][0]=st[2][i][0]=1;
        else if(s[i]=='L')st[1][i][0]=st[2][i][0]=-1,st[0][i][0]=0;
        else if(s[i]=='D')st[0][i][0]=st[1][i][0]=st[2][i][0]=0;
    }
    for(ll j=1;j<=_logn;j++){
        for(ll i=1;i<=n;i++){
            ll _l=i,_r=i+(1<<(j-1));
            if(_r>n){
                st[0][_l][j]=st[0][_l][j-1];
                st[1][_l][j]=st[1][_l][j-1];
                st[2][_l][j]=st[2][_l][j-1];
            }
            else {
                st[0][_l][j]=st[0][_l][j-1]+st[((0+st[0][_l][j-1])+3)%3][_r][j-1];
                st[1][_l][j]=st[1][_l][j-1]+st[((1+st[1][_l][j-1])+3)%3][_r][j-1];
                st[2][_l][j]=st[2][_l][j-1]+st[((2+st[2][_l][j-1])+3)%3][_r][j-1];
            }
        }
    }
    while(q--){
        ll l,r,x;cin>>l>>r>>x;
        ll _l=l;
        ll ans=x;
        while(_l<=r){   //  倍增
            ll j=0;
            while(_l+(1<<j)-1<=r)j++;
            j--;
            ans+=st[ans%3][_l][j];  //  ans%3
            _l+=(1<<j);
        }
        cout<<ans<<'\n';
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