/*
    回文子串最大长度：https://www.acwing.com/problem/content/141/
*/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f
typedef long long ll;
#define ull unsigned long long
//#define INF ~0ULL
#define mod 99993

const int N = 1000000 + 10;
const int base=131;
//base = 131 / 133331
//mod = 2^64
ull p[N],hl[N],hr[N];

ull Hashl(int l,int r)
{
    return hl[r]-hl[l-1]*p[r-l+1];
}

ull Hashr(int l,int r)
{
    return hr[l]-hr[r+1]*p[r-l+1];
}


int solve(string s)
{
    string str;
    int ans=1;
    p[0]=1;
    s=' '+s;
    int n=s.size();
    hl[0]=hr[n+1]=0;
    for(int i=1,j=n;i<=n;i++,j--)
    {
        hl[i]=hl[i-1]*base+s[i];  //Hash left
        hr[j]=hr[j+1]*base+s[j];  //Hash right
        p[i]=p[i-1]*base;         //Base init
    }
    for(int i=1;i<=n;i++)    //  中心
    {
        //奇
        int l=0,r=min(i-1,n-i); // p  len = 2*p+1
        int mid=l+r+1>>1;
        while(l<r)  // p = l
        {
            mid=l+r+1>>1;   //  向上取整(向右靠)
            if(Hashl(i-mid,i) == Hashr(i,i+mid))l=mid;
            else r=mid-1;
        }
        // ans=max(l*2+1,ans);
        if(l*2+1>=ans)
        {
            ans=l*2+1;
            str=s.substr(i-l,ans);
        }
        //偶
        l=0,r=min(i-1,n-i);  // q   len = 2*q
        while(l<r)  //  q = l
        {
            mid=l+r+1>>1;   //  向上取整(向右靠)
            if(Hashl(i-mid,i-1) == Hashr(i,i+mid-1) )l=mid;
            else r=mid-1;
        }
        // ans=max(l*2,ans);
        if(l*2>=ans)
        {
            ans=l*2;
            str=s.substr(i-l,ans);
        }
    }
    // cout<<str<<'\n';
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("E:\\ACMdream\\in.txt", "r", stdin);
    freopen("E:\\ACMdream\\out.txt", "w", stdout);
#endif
    IOS;
//==================================================
    int t=1;
    string s;
    while(cin>>s&&s!="END")
    {
        cout<<"Case "<<t++<<": ";
        cout<<solve(s)<<'\n';
    }
//==================================================
    return 0;
}