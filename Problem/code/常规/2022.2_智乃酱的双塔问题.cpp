/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-02-13 22:54:16
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-02-14 17:31:38
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.2_智乃酱的双塔问题.cpp
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
    牛客竞赛数据结构专题班前缀和练习题 智乃酱的双塔问题 <https://ac.nowcoder.com/acm/contest/19483/E>
    DP+矩阵+前缀和
    两座塔左右都可往上，并且第i层可斜上，分别表示为 / , \ ，要求某座塔i到j层方案数
    考虑dp，dp[i][0]表示最底层到达左边第i层方案数，dp[i][1]则是右边，那么:
    dp[i][0] = dp[i-1][0] + dp[i-1][1]*(s[i-1]=='\')
    dp[i][1] = dp[i-1][1] + dp[i-1][0]*(s[i-1]=='/')
    边界: dp[0][0] = dp[0][1] = 1
    考虑用矩阵来描述:                                    |     1        s[i-1]=='/'  |
    [ dp[i][0] dp[i][1] ] = [ dp[i-1][0] dp[i-1][1] ] * | s[i-1]=='\'      1        |
    边界: [ dp[0][0] dp[0][1] ] = 1 对应的边界矩阵应该是 [ 1 0 0 1]
    到达某一层方案数可表示为矩阵链乘
    容易发现矩阵可逆，因此可用前缀和，矩阵除即逆矩阵乘(左乘)
*/
ll A[5][5];
ll inv(ll x){
    if(x == 1) return 1;
    return (mod - mod / x) * inv(mod % x) % mod;
}
struct Mat{
    ll a[2][2];
    Mat(int a1 = 0, int a2 = 0, int b1 = 0, int b2 = 0){
        a[0][0] = a1, a[0][1] = a2;
        a[1][0] = b1, a[1][1] = b2;
    }
};
Mat operator * (Mat x, Mat y){  //矩阵乘
    Mat ans = Mat(0, 0, 0, 0);
    for(int i=0;i<=1;i++) for(int j=0;j<=1;j++) for(int k=0;k<=1;k++){
        (ans.a[i][j] += x.a[i][k] * y.a[k][j] % mod) %= mod;
    }
    return ans;
}
Mat getinv(Mat x, int n){  //求逆矩阵
    //构造
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            A[i][j] = x.a[i][j];
            A[i][j + n] = (j == i ? 1 : 0);
    }
    //化为对角矩阵
    for(int j=0;j<n;j++){
        //选择主元
        if(!A[j][j]){
            for(int i=j+1;i<n;i++){
                if(!A[i][j]) continue;
                //行交换
                for(int k=0;k<2*n;k++) swap(A[i][k], A[j][k]);
                break;
            }
        }
        //主元化为1
        int inva = inv(A[j][j]);
        for(int k=0;k<2*n;k++) (A[j][k] *= inva) %= mod;
        //消元
        for(int i=j+1;i<n;i++){
            int mul = A[i][j];
            for(int k=0;k<2*n;k++) A[i][k] = (A[i][k] - mul * A[j][k] % mod + mod) % mod;
        }
    }
    //左半部分化为单位阵
    for(int j=n-1;j>=0;j--)
        for(int i=j-1;i>=0;i--){
            int mul = A[i][j];
            for(int k=0;k<2*n;k++) A[i][k] = (A[i][k] - mul * A[j][k] % mod + mod) % mod;
        }
    Mat res;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) res.a[i][j] = A[i][j + n];
    return res;
}
Mat l_up = Mat(1,1,0,1);
Mat r_up = Mat(1,0,1,1);
#define M_1 Mat(1,0,0,1)
#define M_0 Mat(0,0,0,0)
void init(){
}
void PX()
{
    ll n,m;cin>>n>>m;
    string s;cin>>s;
    vector<Mat>pre(n+1,M_0);
    pre[1]=M_1;
    for(int i=0;i<n-1;i++){
        char c=s[i];
        if(c=='/')pre[i+2]=pre[i+1]*l_up;
        else pre[i+2]=pre[i+1]*r_up;
    }
    while(m--){
        int _l,_r,pl,pr;cin>>_l>>_r>>pl>>pr;
        Mat ans = getinv(pre[_l],2)*pre[_r];
        cout<<ans.a[pl][pr]<<'\n';
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