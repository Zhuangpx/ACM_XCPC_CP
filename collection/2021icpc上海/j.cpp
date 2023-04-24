/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-06 12:50:27
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-10 00:37:36
 * @FilePath: \apricity\j.cpp
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
const int N = 5e4+111;
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
/*  J. Two Binary Strings Problem
    给出01串A，B，长为n [0,n]
    定义: f(l,r)=（bool)(sum[l,r]/(r-l+1))  // 平均值
    定义一个数字k是lucky的iff:对于任意i，有f(max(i-k+1,1),i)=b[i]
    考虑对于所有k,1<=k<=n，判断k是否lucky，以01串输出(k为区间长度)
    //==
    令'0'=-1，那么有f(l,r)=(bool)(sum[l,r]>0)
    考虑位置i和k，有f(l,r)=1<==>sum[1,i-k]<sum[1,i]<==>s[i-k]<s[i]，也就是说满足b[i]=1的k有s[i-k]<s[i](前缀和)
    反之满足b[i]=0的k有s[i-k]>=s[i]，于是通过s[i]将k分到了两个集合
    i:      1   2   3   4   5   6   7
    A:      0   1   1   0   0   1   1
    K=1:    0   1   1   0   0   1   1
    k=2:    0   0   1   0   0   0   1
    k=3:    0   0   1   1   0   0   1
    ...
    k=7:    0   0   1   0   0   0   1
    B:      x   x   x   x   x   x   x
    另一优质题解参考:<https://www.cnblogs.com/1625--H/p/15616797.html>(规律递推)
*/
void init(){
}
bitset<N>c[N],x,y;
void PX()
{
    int n;cin>>n;
    string a,b;cin>>a>>b;
    unordered_map<int,int>mp;mp[0]=-1;    // 记录前缀和s的位置i 即s[0,i]=cnt--->mp[cnt]=i
    x.reset(),y.reset();for(int i=0;i<n;i++)x[i]=y[i]=1;  // x,y=>1  x为答案，y为全1的bitset
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(a[i]=='1'?1:-1);
        c[i].reset(); //c[i]=>0
        //寻找最近的j满足s[j+1,i]=0 更新c[0]~c[n-1]
        if(mp.count(cnt)){
            int j=mp[cnt]; // 某两个位置l,r前缀和相同 说明这两个位置的区间和s[l+1,r]为0
            if(a[i]=='1') c[i]|=y>>(n-(i-j-1)); // c[i]的0~i-j-1位为1
            if(j>=0) c[i]|=c[j]<<(i-j); //  从c[j]往c[i]递推
        }
        else {
            if(a[i]=='1')c[i]=y;    //  不存在这样的j
        }
        if(c[i][i]==1) c[i]|=(y>>i)<<i; // 如果往前数k个达到了边界并且当前c[k][k]=1，那么往后也都是1(k变大但区间不变长)
        mp[cnt]=i;
        if(b[i]=='1')x&=~(c[i]^y);
        else x&=~c[i];
    }
    for(int i=0;i<n;i++)if(x[i]==1)cout<<'1';else cout<<'0';
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
