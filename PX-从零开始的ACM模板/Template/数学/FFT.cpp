/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-04-08 09:33:44
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-04-08 11:40:34
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数学\FFT.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*  分治FFT = DFT+IDFT
    从朴素到优化
    浮点数范围内的多项式乘法(加法卷积)  存在精度丢失的问题 尤其是值域相差比较大的时候
    想要避免精度丢失 移步NTT
*/

#include <iostream>
#include <math.h>
using namespace std;

const int N = 2e6+55;


const double PI = acos(-1); //  PI
//  复数类
struct CP   //  Complex
{
    double x, y;    //  x+y*i
    CP (double nx=0.0, double ny=0.0):x(nx),y(ny) {}
    CP operator+ (CP const &P) const
    { return CP(x+P.x, y+P.y); }
    CP operator- (CP const &P) const
    { return CP(x-P.x, y-P.y); }
    CP operator* (CP const &P) const
    { return CP(x*P.x-y*P.y, x*P.y+y*P.x); }
    CP operator/ (CP const &P) const
    {
        double res = P.x*P.x+P.y*P.y;    //  Complex mul Conjugate Complex
        return CP((x*P.x+y*P.y)/res, (y*P.x-x*P.y)/res);
    }
};
//  预处理单位根 (n等分单位圆)
inline void cpw_init(int n, CP *w)    //  init w (单位根)
{
    CP now(1,0), res(cos(2*PI/n), sin(2*PI/n));
    for(int i=0;i<n;i++) {
        w[i]=now;
        now=now*res;
    }
}
//  分治DFT 保证len为2的米次  与下述IDFT配合使用
void DFT(CP *f, CP *sav, int len)    //  分治DFT  len = 2^n
{
    if(len==1) return ;
    CP *fl=f, *fr=f+len/2;
    for(int k=0;k<len;k++) sav[k]=f[k];
    for(int k=0;k<len/2;k++) {
        fl[k]=sav[k*2];   //  2*k
        fr[k]=sav[k*2+1]; //  2*k+1
    }
    DFT(fl, sav, len/2); DFT(fr, sav, len/2);
    CP tG(cos(2*PI/len), sin(2*PI/len));    //  cos sin
    CP res(1,0);
    for(int k=0;k<len/2;k++) {
        sav[k] = fl[k] + res*fr[k];   //  FL
        sav[k+len/2] = fl[k] - res*fr[k]; //  FR
        res = res*tG;
    }
    for(int k=0;k<len;k++) f[k]=sav[k];
}
//  分治IDFT 保证len为2的幂次 与上述DFT配合使用
void IDFT(CP *f, CP *sav, int len)      //  分治IDFT    len = 2^n
{
    if(len==1) return ;
    CP *fl=f, *fr=f+len/2;
    for(int k=0;k<len;k++) sav[k]=f[k];
    for(int k=0;k<len/2;k++) {
        fl[k]=sav[k*2];
        fr[k]=sav[k*2+1];
    }
    IDFT(fl, sav, len/2); IDFT(fr, sav, len/2);
    CP tG(cos(2*PI/len), -1*sin(2*PI/len) );    //  cos , -sin
    CP res(1,0);
    for(int k=0;k<len/2;k++) {
        sav[k]=fl[k]+res*fr[k];
        sav[k+len/2]=fl[k]-res*fr[k];
        res = res*tG;
    }
    for(int k=0;k<len;k++) f[k]=sav[k];
}
//  朴素的分治FFT   不压常数    供理解
void FFT_(CP* f, CP *sav, int len, bool flag)   //  分治FFT falg?DFT:IDFT len = 2^n
{
    if(len==1) return ;
    CP *fl=f, *fr=f+len/2;
    for(int k=0;k<len;k++) sav[k]=f[k];
    for(int k=0;k<len/2;k++) {
        fl[k]=sav[k*2];
        fr[k]=sav[k*2+1];
    }
    FFT_(fl, sav, len/2, flag); FFT_(fr, sav, len/2, flag);
    CP tG(cos(2*PI/len), sin(2*PI/len) );
    if(!flag) tG.y*=-1; //  DFT->cos,sin  IDFT->cos,-sin
    CP res(1,0);
    for(int k=0;k<len/2;k++) {
        sav[k]=fl[k]+res*fr[k];
        sav[k+len/2]=fl[k]-res*fr[k];
        res = res*tG;
    }
    for(int k=0;k<len;k++) f[k]=sav[k];
}


//  常数优化 分治FFT 预处理 进制翻转数组
inline void init_FFT(int *trb, int len)     //  init_FFT    预处理进制翻转
{
    for(int i=0;i<len;i++) trb[i]=(trb[i>>1]>>1)|((i&1)?len>>1:0);
}
//  常数优化 分治FFT
//  优化了分治拷贝 三角函数求值 乘法冗余
void FFT(CP* f, int *trb, int n, bool flag)   //  常数优化分治FFT falg?DFT:IDFT   n=2^k
{
    //F(x)=FL(x^2)+x*FR(x^2)
    //F(W^k)=FL(w^k)+W^k*FR(w^k)
    //F(W^{k+n/2})=FL(w^k)-W^k*FR(w^k)
    for(int i=0;i<n;i++) if(i<trb[i]) swap(f[i], f[trb[i]]);  //  蝴蝶变换-二进制翻转来得到原来系列和分治序列的关系
    for(int p=2;p<=n;p<<=1) {   //  枚举区间长度
        int len=p>>1;   //  待合并的长度
        CP tG(cos(2*PI/p), sin(2*PI/p));
        if(!flag) tG.y*=-1;     //  p次单位根
        for(int k=0;k<n;k+=p) {  //  枚举起点
            CP res(1,0);
            for(int l=k;l<k+len;l++) {
                CP temp = res*f[len+l];
                f[l+len]=f[l]-temp; //  注意顺序
                f[l]=f[l]+temp;
                res = res*tG;
            }
        }
    }
}

//===============
CP f1[N<<1],f2[N<<1],sav[N<<1],f[N<<1];
int trb[N<<1];  //  trans bit
void Zhuangpx()
{
    /* n次多项式f1(x)    m次多项式f2(x)     求乘积
    */
    //  1. DFT+IDFT
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>f1[i].x;
    for(int i=0;i<=m;i++) cin>>f2[i].x;
    //  ! nm = n+m  len = 2^n (补全为2的幂次)
    int len=1, nm=n+m;
    while(len<=nm) len<<=1;
    DFT(f1, sav, len); DFT(f2, sav, len);
    for(int i=0;i<len;i++) f1[i] = f1[i]*f2[i];
    IDFT(f1, sav, len);
    //  ! 注意要/len 以及精度(+0.49)
    for(int i=0;i<=nm;i++) cout<<(int)(f1[i].x/len + 0.49)<<" \n"[i==nm];
    //====
    //  2. 朴素分治 FFT
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>f1[i].x;
    for(int i=0;i<=m;i++) cin>>f2[i].x;
    //  ! nm = n+m  len = 2^n (补全为2的幂次)
    int len=1, nm=n+m;
    while(len<=nm) len<<=1;
    FFT_(f1, sav, len ,1); FFT_(f2, sav, len, 1);
    for(int i=0;i<len;i++) f1[i] = f1[i]*f2[i];
    FFT_(f1, sav, len, 0);
    //  ! 注意要/len 以及精度(+0.49)
    for(int i=0;i<=nm;i++) cout<<(int)(f1[i].x/len + 0.49)<<" \n"[i==nm];
    //====
    //  3. 常数优化 分治FFT
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>f1[i].x;
    for(int i=0;i<=m;i++) cin>>f2[i].x;
    //  ! nm = n+m  len = 2^n (补全为2的幂次)
    int len=1, nm=n+m;
    while(len<=nm) len<<=1;
    init_FFT(trb, len);  FFT(f1, trb, len, 1);  FFT(f2, trb, len, 1);
    for(int i=0;i<len;i++) f1[i] = f1[i]*f2[i];
    FFT(f1, trb, len, 0);
    //  ! 注意要/len 以及精度(+0.49)
    for(int i=0;i<=nm;i++) cout<<(int)(f1[i].x/len + 0.49)<<" \n"[i==nm];
    //====
    //  4. 常数优化 + 三次变两次优化 分治FFT
    //  三次变两次优化 只用一个复数组 分别把两个多项式存在实数和虚数域
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>f[i].x;
    for(int i=0;i<=m;i++) cin>>f[i].y;
    //  ! nm = n+m  len = 2^n (补全为2的幂次)
    int len=1, nm=n+m;
    while(len<=nm) len<<=1;
    init_FFT(trb, len);  FFT(f, trb, len, 1);
    for(int i=0;i<len;i++) f[i] = f[i]*f[i];
    FFT(f, trb, len, 0);
    //  ! 注意y要/len再/2 以及精度(+0.49)
    for(int i=0;i<=nm;i++) cout<<(int)(f[i].y/len/2 + 0.49)<<" \n"[i==nm];

}
//===============
