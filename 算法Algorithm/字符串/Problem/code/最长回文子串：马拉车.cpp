
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

int solve(string s)
{
    int res=1;
    string rs;
    if(s.size()<=1)
    {
        cout<<s<<'\n';
        return s.size();
    }
    int len=s.size()*2+1;   //manacher串长度
    string str;             //manacher
    vector<int>ans(len+1,0);//回文半径数组
    int R=-1,C=-1;          //初始化-1
    for(int i=0;i<len;i++)  //处理manacher
    {
        if(i&1)str+=s[i/2];
        else str+='#';
    }
    for(int i=0;i<len;i++)  //枚举中心i
    {
        //int ii=2*C-i      //i关于C对称点ii
        //先处理出最短的可能
        if(i>R) ans[i]=1;
        else ans[i]=min(R-i,ans[2*C-i]);
        //取完最小值后直接进行第三种情况的匹配 省去情况判断
        while(i+ans[i]<len && i-ans[i]>=0)
        {
            if(str[i+ans[i]]==str[i-ans[i]])ans[i]++;
            else break;
        }
        //维护C和R
        if(i+ans[i]>R)
        {
            R=i+ans[i];
            C=i;
        }
        // res=max(res,ans[i]);
        if(ans[i]>res)
        {
            res=ans[i];
            rs=s.substr(i/2-(res-1)/2,res-1);
        }
    }
    //cout<<rs<<'\n';
    return res-1;
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