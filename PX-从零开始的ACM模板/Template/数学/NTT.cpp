/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-08 11:36:06
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-08 13:55:14
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数学\NTT.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*  NTT
    大模数MOD下的多项式乘法(加法卷积)
    需要进制翻转数组预处理
    优化技巧:
    预处理原根，省去部分乘法操作
    ull存，能承受18*MOD*MOD的范围，常规不取模或少取模
*/


#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 998244353   //  默认的大模数

ll powM(ll a,ll b=MOD-2,ll m=MOD){ll d=1; while(b){if(b&1)d=(d*(a%m))%m; a=((a%m)*(a%m))%m; d%=m; b>>=1;}return d%m;}
inline void init_NTT(int *trb,int len)      //  init_NTT 进制翻转数组预处理
{
    for(int i=0;i<len;i++) trb[i]=(trb[i>>1]>>1)|((i&1)?len>>1:0);
}


//==============   常规
const int N = 2e6+55;
void NTT(ll *f, int *trb, int n ,bool flag)     //  模MOD意义下的NTT
{
    ll G=3;
    ll invG=powM(G);
    for(int i=0;i<n;i++) if(i<trb[i]) swap(f[i],f[trb[i]]);
    for(int p=2;p<=n;p<<=1) {
        int len=p>>1, tG=powM(flag?G:invG, (MOD-1)/p);
        for(int k=0;k<n;k+=p) {
            ll res=1;
            for(int l=k;l<k+len;l++) {
                int temp=res*f[len+l]%MOD;
                f[len+l]=f[l]-temp;
                if(f[len+l]<0) f[len+l]+=MOD;
                f[l]=f[l]+temp;
                if(f[l]>MOD) f[l]-=MOD;
                res=res*tG%MOD;
            }
        }
    }
}
ll f[N<<1],g[N<<1]; //  long long
int trb[N<<1];
void Zhuangpx()
{
    /* n次多项式f1(x)    m次多项式f2(x)     求乘积
       把f1存在f  f2存在g
    */
    int n,m;cin>>n>>m;
    n++,m++;    //  ! 注意 n 和 m 要加一
    for(int i=0;i<n;i++) cin>>f[i];
    for(int i=0;i<m;i++) cin>>g[i];
    //  ! nm = n+m  len = 2^n (补全为2的幂次)
    int len=1,nm=n+m;
    while(len<nm)len<<=1;
    init_NTT(trb, len); NTT(f, trb, len, 1);  NTT(g, trb, len, 1);  //  DFT
    for(int i=0;i<len;i++) f[i]=f[i]*g[i]%MOD;  //  f= f*g
    NTT(f, trb, len, 0);    //  IDFT
    int invlen=powM(len);   //  invlen
    for(int i=0;i<nm-1;i++) cout<<(int)(f[i]*invlen%MOD)<<" \n"[i==nm-2];   //  f*invlen%MOD
}

//=============    优化
const int N = 1e6+50000;
void NTT_(int *f, int *trb, int n, bool flag)       //  模MOD意义下的NTT
{
    int _G=3;
    int invG=powM(_G);
    static ull _f[N << 1], w[N << 1] = {1};
    for (int i = 0; i < n; i++) _f[i] = f[trb[i]];
    for (int l = 1; l < n; l <<= 1) {
        ull tG = powM(flag ? _G : invG, (MOD - 1) / (l + l));
        for (int i = 1; i < l; i++) w[i] = w[i - 1] * tG % MOD;
        for (int k = 0; k < n; k += l + l) {
            for (int p = 0; p < l; p++) {
                int tt = w[p] * _f[k | l | p] % MOD;
                _f[k | l | p] = _f[k | p] + MOD - tt;
                _f[k | p] += tt;
            }
        }
        if (l == (1 << 17)) for(int i = 0; i < n; i++) _f[i] %= MOD;
    }
    if (!flag) {
        ull invn = powM(n);
        for (int i = 0; i < n; ++i) f[i] = _f[i] % MOD * invn % MOD;
    }
    else for (int i = 0; i < n; ++i) f[i] = _f[i] % MOD;
}
int f[N<<1],g[N<<1];
int trb[N<<1];
void PX()
{
    /* n次多项式f1(x)    m次多项式f2(x)     求乘积
       把f1存在f  f2存在g
    */
    int n,m;cin>>n>>m;
    n++,m++;    //  ! 注意 n 和 m 要加一
    for(int i=0;i<n;i++) cin>>f[i];
    for(int i=0;i<m;i++) cin>>g[i];
    //  ! nm = n+m  len = 2^n (补全为2的幂次)
    int len=1,nm=n+m;
    while(len<nm)len<<=1;
    init_NTT(trb, len); NTT_(f, trb, len, 1);  NTT_(g, trb, len, 1);  //  DFT
    for(int i=0;i<len;i++) f[i]=1ll*f[i]*g[i]%MOD;  //  f= f*g
    NTT_(f, trb, len, 0);    //  IDFT
    for(int i=0;i<nm-1;i++) cout<<(int)f[i]<<" \n"[i==nm-2];
}

