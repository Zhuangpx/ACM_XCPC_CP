/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-23 23:54:41
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-10-25 09:11:24
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数据结构\FenwickTree.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*  FenwickTree 树状数组 BIT

Here form BIT1 to BIT10
using namespace

*/

#include <iostream>
#include <algorithm>    // stable_sort
using namespace std;
#define ll long long
#define int long long
#define INF 0x3f3f3f3f
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }

const int N=1e6+11;     //  maxn

namespace BIT1 {
// 单点修改，区间求和
int a[N];   //  ori
int c[N];   //  bit
int n;      //  size
int lowbit(int x){return x&(-x);}
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
void add(int x,int k) {  while(x<=n){ c[x]+=k; /*x+=lowbit(x);*/lowbitup(x); }  }   //  a[x]=a[x]+k
int getsum(int x) {     //  sum [1,r]
    int ans=0;
    while(x>=1){ ans+=c[x]; /*x-=lowbit(x);*/lowbitdown(x); }
    return ans;
}
int _getsum(int l,int r){return getsum(r)-getsum(l-1);}     //  sum [l,r]
//=====
void Zhuangpx()
{
    int q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        add(i,a[i]);
    }
    for(int i=1;i<=q;++i){
        int d,x,y;cin>>d>>x>>y;
        if(d==1)add(x,y);
        else if(d==2)cout<<_getsum(x,y)<<'\n';
    }
}
//=====
}   //  namespace BIT1

namespace BIT2 {
//  区间修改，单点求值
int a[N],b[N],c[N]; //  ori 差分 bit
int n;
int lowbit(int x){return x&-x;}
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
int getsum(int x)//get a[x] or sum of b[1~x]
{
    int ans=0;
    while(x>=1){
        ans+=c[x];
        /*x-=lowbit(x);*/lowbitdown(x);
    }
    return ans;
}
inline int get(int x)//get a[x] or sum of b[1~x]
{
    return getsum(x);
}
void add(int x,int k)//b[x]=b[x]+k
{
    while(x<=n){
        c[x]+=k;
        /*x+=lowbit(x);*/lowbitup(x);
    }
}
inline void range_add(int l,int r,int k)//a[l~r]+=k
{
    add(l,k),add(r+1,-k);
}
//=====
void Zhuangpx()
{
    int q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        b[i]=a[i]-a[i-1];
        add(i,b[i]);
    }
    for(int i=1;i<=q;++i){
        int d;cin>>d;
        if(d==1){
            int l,r,k;cin>>l>>r>>k;
            range_add(l,r,k);
        }
        else if(d==2){
            int x;cin>>x;
            cout<<get(x)<<'\n';
        }
    }
}
//=====
}   //  namespace BIT2

namespace BIT3 {
//  区间修改，区间求和
int a[N],b1[N],b2[N],c1[N],c2[N];   //  ori 差分 1+2  bit 1+2
int n;
int lowbit(int x){return x&-x;}
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
int getsum(int *t,int x)
{
    int ans=0;
    while(x>=1){
        ans+=t[x];
        /*x-=lowbit(x);*/lowbitdown(x);
    }
    return ans;
}
inline int range_getsum(int l,int r)        //  sum of a[l,r]
{
    return (r+1)*getsum(c1, r)-l*getsum(c1, l - 1)-(getsum(c2,r)-getsum(c2,l-1));
}
void add(int x,int k)
{
    int p=x*k;
    while(x<=n){
        c1[x]+=k,c2[x]+=p;
        /*x+=lowbit(x);*/lowbitup(x);
    }
}
inline void range_add(int l,int r,int k)    //  a[l,r] += k
{
    add(l,k),add(r+1,-k);
}
//=====
void Zhuangpx()
{
    int q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        b1[i]=a[i]-a[i-1];
        b2[i]=b1[i]*i;
        add(i,b1[i]);
    }
    for(int i=1;i<=q;++i){
        int d;cin>>d;
        if(d==1){
            int l,r,k;cin>>l>>r>>k;
            range_add(l,r,k);
        }
        else if(d==2){
            int l,r;cin>>l>>r;
            cout<<range_getsum(l,r)<<'\n';
        }
    }
}
//=====
}   //  namespace BIT3

namespace BIT4 {
//  离散化树状数组求逆序对
int tre[N],ran[N];
int n;
struct Node     //  a.val -> ori
{
    int val,pos;//记录下权值val和位置
}a[N];
int lowbit(int x){return x&-x;}
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
bool cmp(Node x,Node y)//按照权值小到大(位置小到大)排序
{
    if(x.val==y.val)return x.pos<y.pos;
    else return x.val<y.val;
}
void add(int x,int k)
{
    while(x<=n){
        tre[x]+=k;
        /*x+=lowbit(x);*/lowbitup(x);
    }
}
int getsum(int x)
{
    int ans=0;
    while(x>=1){
        ans+=tre[x];
        /*x-=lowbit(x);*/lowbitdown(x);
    }
    return ans;
}
//=====
void Zhuangpx()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        a[i].pos=i;
    }
    //sort(a+1,a+1+n,cmp);
    stable_sort(a+1,a+1+n,cmp);//存在元素相同，不应改变相对位置
    int all=0;
    for(int i=1;i<=n;i++){
        ran[a[i].pos]=i;
    }
    for(int i=1;i<=n;i++){
        add(ran[i],1);
        all+=(i-getsum(ran[i]));
    }
    cout<<all<<'\n';
}
//=====
}   //  namespace BIT4

namespace BIT5 {
// 单点修改，区间求最值
int mai(int a,int b) { return max(a,b); }   //  最大
// int mai(int a,int b) { return min(a,b); }   //  最小
int a[N];   //  ori
int c[N];   //  bit
int n;      //  size
int lowbit(int x){return x&(-x);}
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
void modify(int x,int k) {  while(x<=n){ c[x]=mai(c[x],k); /*x+=lowbit(x);*/lowbitup(x); }  }   //  a[x]=mai(a[x],k)
int getmai(int l,int r) {     //  mai [l,r]
    int res=-INF;
    while(r>=l&&r-l+1>=lowbit(r)){
        res=mai(res,c[r]);
        /*r-=lowbit(r);*/lowbitdown(r);
    }
    while(r>=l){
        res=mai(res,a[r]);
        if(r-l+1<lowbit(r)) r--;
        else res=mai(res,c[r]),/*r-=lowbit(r),*/lowbitdown(r);
    }
    return res;
}
//=====
void Zhuangpx()
{
    int q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        modify(i,a[i]);
    }
    for(int i=1;i<=q;++i){
        int x,y;cin>>x>>y;
        cout<<getmai(x,y)<<'\n';
    }
}
//=====
}   //  namespace BIT5

namespace BIT6{
//  实时求出剩余数的第k小 (树状数组+二分)
/*  AcWing 244. 谜一样的牛 《算法竞赛进阶指南》P209
    1-n,给出i前面比a[i]小的数的个数aks[i]
    后往前，每次i的值就是后面没出现的数字的第ask[i]+1小，维护初始全1的序列，每次求出前缀合为ask[i]+1的位置j(二分)，然后将j置为0
*/
//  BIT1
int a[N];
int c[N];
int n;
int lowbit(int x) { return x&(-x); }
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
void add(int x,int k)
{
    while(x<=n){
        c[x]+=k;
        /*x+=lowbit(x);*/lowbitup(x);
    }
}
int getsum(int x)
{
    int res=0;
    while(x>=1)res+=c[x],/*x-=lowbit(x),*/lowbitdown(x);
    return res;
}   //BIT1
int ans[N];
int ask[N];
void Zhuangpx()
{
    cin>>n;
    ask[1]=0;add(1,1);
    for(int i=2;i<=n;i++){
        cin>>ask[i];
        add(i,1);
    }
    for(int i=n;i>=1;i--){
        int now=ask[i]+1;
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            int num=getsum(mid);
            if(num>=now)r=mid;
            else l=mid+1;
        }
        add(r,-1);
        ans[i]=r;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
}
}   //  namespace BIT6

namespace BIT7{
//  树状数组离线查询区间种类数
/*  将离线区间按r排序，从1开始去枚举位置，每次出现新颜色在对应位置进行add(1)，如果重复颜色则需要把原先的add(-1)，在新位置在add(1)
    那么区间[l,r]的和就是颜色种类数(因为每种颜色权值为1)
*/
int a[N];   //  ori
int c[N];   //  bit
int n;      //  size
int lowbit(int x){return x&(-x);}
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
void add(int x,int k) {  while(x<=n){ c[x]+=k; /*x+=lowbit(x);*/lowbitup(x); }  }   //  a[x]=a[x]+k
int getsum(int x) {     //  sum [1,r]
    int ans=0;
    while(x>=1){ ans+=c[x]; /*x-=lowbit(x);*/lowbitdown(x); }
    return ans;
}
int _getsum(int l,int r){return getsum(r)-getsum(l-1);}     //  sum [l,r]

struct C{   //  查询区间l,r编号idx
    int l,r;
    int idx;
    bool operator<(const C& x)const{    //  按r排序
        return r<x.r;
    }
}ask[N];    //  aks[N]

int col[N];     //  color
int ans[N];     //  ans[i]=j -> ask[i]->ans=j
int m;          //  aks num
int vis[N];     //  vis[i]=j -> 颜色i在位置j
void Zhuangpx()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>col[i];
    for(int i=1;i<=m;i++)cin>>ask[i].l>>ask[i].r,ask[i].idx=i;
    sort(ask+1,ask+1+m);
    int now=1;              //  维护当前扫描位置
    for(int i=1;i<=m;i++){
        for(int j=now;j<=ask[i].r;j++){
            if(vis[col[j]])   add(vis[col[j]],-1);  //  出现过置回
            vis[col[j]]=j;    add(vis[col[j]],1);   //  置1
        }
        now=ask[i].r+1;
        ans[ask[i].idx]=_getsum(ask[i].l,ask[i].r); //  区间和
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
}
}   //  namespace BIT7

namespace BIT8{
//  二维树状数组 - 单点修改，区间求和
//  n*m矩阵，初始全0，add单点+=k，getsum求前缀矩阵和，_getsum求子矩阵和
//  bit矩阵:  单点修改->bit修改   子矩阵求和->矩阵前缀和+容斥
int c[N][N];    //  bit 矩阵(x,y)   左上(0,0)
int n,m;        //  矩阵n*m
int lowbit(int x){return x&(-x);}
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
void add(int x,int y,int k) //a[x,y]=a[x,y]+k -> add c
{
    int memo_y=y;
    while(x<=n){//if the max size is n*m (To prevent overflow)
        y=memo_y;
        while(y<=m){
            c[x][y]+=k;
            /*y+=lowbit(y);*/lowbitup(y);
        }
        /*x+=lowbit(x);*/lowbitup(x);
    }
}
int getsum(int x,int y) //sum of a[1,1]~a[x,y]  -> presum
{
    int ans=0,memo_y=y;
    while(x>=1){
        y=memo_y;
        while(y>=1){
            ans+=c[x][y];
            /*y-=lowbit(y);*/lowbitdown(y);
        }
        /*x-=lowbit(x);*/lowbitdown(x);
    }
    return ans;
}
//容斥定理
int _getsum(int x1,int y1,int x2,int y2) //sum of a[x1,y1]~a[x2,y2]  左上角 (x1,y1) 又下角(x2,y2)
{
    return getsum(x2,y2)-getsum(x2,y1-1)-getsum(x1-1,y2)+getsum(x1-1,y1-1);
}
//====
void Zhuangpx()
{
    cin>>n>>m;
    int op;
    while(cin>>op){
        if(op==1){
            int x,y,k;cin>>x>>y>>k;
            add(x,y,k);
        }
        else if(op==2){
            int a,b,c,d;cin>>a>>b>>c>>d;
            cout<<_getsum(a,b,c,d)<<'\n';
        }
    }
}
//====
}   //  namespace BIT8

namespace BIT9{
//  二维树状数组 - 区间修改，单点求值
//  n*m矩阵，初始全0，add单点+=k，range_add子矩阵+=k，getsum求前缀矩阵和，get求单点
int c[N][N];    //  差分 矩阵(x,y)   左上(0,0)
int n,m;        //  矩阵n*m
int lowbit(int x){return x&(-x);}
//  fast lowbit up and down
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
int getsum(int x,int y)     // 差分presum 即 原点
{
    int ans=0,memo_y=y;
    while(x>=1){
        y=memo_y;
        while(y>=1){
            ans+=c[x][y];
            /*y-=lowbit(y);*/lowbitdown(y);
        }
        /*x-=lowbit(x);*/lowbitdown(x);
    }
    return ans;
}
inline int get(int x,int y)
{
    return getsum(x,y);
    // return getsum(x,y)-getsum(x,y-1)-getsum(x-1,y)+getsum(x-1,y-1);
}
void add(int x,int y,int k)//a[x,y]=a[x,y]+k
{
    int memo_y=y;
    while(x<=n){//if the max num is n (To prevent overflow)
        y=memo_y;
        while(y<=m){
            c[x][y]+=k;
            /*y+=lowbit(y);*/lowbitup(y);
        }
        /*x+=lowbit(x);*/lowbitup(x);
    }
}
inline void range_add(int x1,int y1,int x2,int y2,int k)    //  range add 左上(x1,y1) 右下(x2,y2)
{
    add(x1,y1,k),add(x2+1,y2+1,k);
    add(x1,y2+1,-k),add(x2+1,y1,-k);
}
//====
void Zhuangpx()
{
    cin>>n>>m;
    int op;
    while(cin>>op){
        if(op==1){
            int a,b,c,d,k;cin>>a>>b>>c>>d>>k;
            range_add(a,b,c,d,k);
        }
        else if(op==2){
            int a,b;cin>>a>>b;
            // cout<<get(a,b)<<'\n';
            cout<<getsum(a,b)<<'\n';
        }
    }
}
//====
}   //  namespace BIT9

namespace BIT10{
//  二维树状数组 - 区间修改，区间求和
//  n*m矩阵，初始全0，add单点+=k，range_add子矩阵+=k，getsum求前缀矩阵和，get求子矩阵
//  ori:a  差分b   bit: c1->b[i][j]  c2->b[i][j]*i  c3->b[i][j]*j   c4->b[i][j]*i*j
int c1[N][N],c2[N][N],c3[N][N],c4[N][N];
int n,m;        //  矩阵n*m
int lowbit(int x){return x&(-x);}
//  deal with x==0 error
inline void lowbitup(int &x) { x|=x+1; }
inline void lowbitdown(int &x) { x&=x+1;x--; }
int getsum(int x,int y)     //  presum
{
    int ax=x,ay=y;
    int ans=0,memo_y=y;
    while(x>=1){
        y=memo_y;
        while(y>=1){
            ans+=c1[x][y]*(ax+1)*(ay+1)-c2[x][y]*(ay+1)-c3[x][y]*(ax+1)+c4[x][y];
            /*y-=lowbit(y);*/lowbitdown(y);
        }
        /*x-=lowbit(x);*/lowbitdown(x);
    }
    return ans;
}
inline int get(int x1,int y1,int x2,int y2)     //  get sum of (x1,y1)->(x2,y2)
{
    return getsum(x2,y2)-getsum(x2,y1-1)-getsum(x1-1,y2)+getsum(x1-1,y1-1);
}
void add(int x,int y,int k) //a[x,y]=a[x,y]+k
{
    int ax=x,ay=y;
    int memo_y=y;
    while(x<=n){//if the max num is n*m (To prevent overflow)
        y=memo_y;
        while(y<=m){
            c1[x][y]+=k;
            c2[x][y]+=ax*k;
            c3[x][y]+=ay*k;
            c4[x][y]+=ax*ay*k;
            /*y+=lowbit(y);*/lowbitup(y);
        }
        /*x+=lowbit(x);*/lowbitup(x);
    }
}
inline void range_add(int x1,int y1,int x2,int y2,int k)    //  左上(x1,y2)右下(x2,y2) +=k
{
    add(x1,y1,k),add(x2+1,y2+1,k);
    add(x1,y2+1,-k),add(x2+1,y1,-k);
}
//====
void Zhuangpx()
{
    cin>>n>>m;
    int op;
    while(cin>>op){
        if(op==1){
            int a,b,c,d,k;cin>>a>>b>>c>>d>>k;
            range_add(a,b,c,d,k);
        }
        else if(op==2){
            int a,b,c,d;cin>>a>>b>>c>>d;
            cout<<get(a,b,c,d)<<'\n';
        }
    }
}
//====
}   //  namespace BIT10
