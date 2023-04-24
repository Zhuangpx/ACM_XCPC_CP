/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-10 13:51:55
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-10 13:51:56
 * @FilePath: \apricitye:\桌面\ACM\Problem\code\常规\2022.3_[牛客]EfficientSolutions(uva).cpp
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
/*  [牛客]EfficientSolutions(uva) <https://ac.nowcoder.com/acm/contest/22904/1017>
    给n个点(x,y)，加入不存在这样的点(x1,y1)满足x1<=x&&y1<y或x1<x&&y1<=y那么(x,y)就是有优势的
    依次给出n个点，求每次优势点的个数
    容易发现(x1,y2)会把它的右上点剔除掉
    //==
    考虑到非优势点在往后也是非优势点，因此考虑维护一个优势点的集合，每次新来一个点进行更新
    容易发现优势点集合是有规律的，x小则y大，趋势的往右下的，因此可以按此排序，假如x相同，应该让y大的优先级低，这样依旧是往右下的
    考虑新来一个点进行集合更新
    新来的点非优势点，不进行加入
    新来的点是优势点，找到它的位置，向右进行非优势点删除
    判断当前点是否优势点，用左边一个点进行比较
*/
void init(){
}
struct C{
    int x,y;
    inline bool operator<(const C& c)const{ //  呈现右下趋势
        return this->x==c.x? this->y>c.y : this->x<c.x;
    }
};
void PX()
{
    int T;cin>>T;
    for(int t=1;t<=T;t++){
        cout<<"Case #"<<t<<":\n";
        multiset<C>s;
        int n;cin>>n;
        while(n--){
            C now;cin>>now.x>>now.y;
            if(s.empty()){s.insert(now);cout<<1<<'\n';continue;}
            auto it=s.lower_bound(now); //找到第一个>=now的，那么now的位置就是it-1和it之间
            if(it==s.begin() || (--it)->y>now.y){   //左边无点，或左边点在左上，那么当前点是有优势的
                s.insert(now);
                it=s.upper_bound(now); // 向右找"右"点
                while(it!=s.end()&&it->y>=now.y)s.erase(it++); // 还满足"上"则要删除
            }
            cout<<s.size()<<'\n';
        }
        if(t<T)cout<<'\n';
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
