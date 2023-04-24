/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-05 11:13:21
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-05 12:23:32
 * @FilePath: \apricitye:\桌面\ACM\collection\2019ccpc秦皇岛\j.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
/*  KMP+循环节
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7+7;
char s[N],p[N];
void PX()
{
    ll a,b;cin>>a>>b;
    cin>>s;
    for(int i=0;i<s[i];i++){
        if(s[i]=='.'){
            strcpy(p+1,s+i+1);
        }
    }
    int n=strlen(p+1);
    reverse(p+1,p+n+1);
    vector<int>ne(n+5,0);
    for(int i=2,j=0;i<=n;i++){
        while(j&&p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])j++;
        ne[i]=j;
    }
    ll ans=-1e9;
    for(int i=1;i<=n;i++){
        ans=max(ans,1ll*a*i-1ll*b*(i-ne[i]));
    }
    cout<<ans<<'\n';
}

int main()
{
    int T=1;
    // cin>>T;
    while(T--)PX();
}