/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-08 09:09:03
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-08 09:09:04
 * @FilePath: \apricitye:\桌面\ACM\collection\AcWingKuangbin专题\专题一简单搜索\4221.洗牌.cpp
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
/*  4221. 洗牌 <https://www.acwing.com/problem/content/description/4224/>
*/
void init(){
}
void PX()
{
    int T;cin>>T;
    for(int t=1;t<=T;t++){
        int cnt=0;
        int n;cin>>n;
        string s1,s2,s3;cin>>s1>>s2>>s3;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        reverse(s3.begin(),s3.end());
        map<string,bool>mp;
        while(++cnt){
            string s="";
            for(int i=0,j=0,k=0;i<2*n;i++){
                if(i%2)s+=s2[j++];
                else s+=s1[k++];
            }
            if(s==s3)break;
            if(mp[s]){cnt=-1;break;}
            mp[s]=1;
            s2=s.substr(0,n),s1=s.substr(n,n);
        }
        cout<<t<<' '<<cnt<<'\n';
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
