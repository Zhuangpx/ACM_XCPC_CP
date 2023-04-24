/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-09 18:24:31
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-09 18:24:32
 * @FilePath: \apricitye:\桌面\ACM\collection\2021icpc上海\i.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[105][2800][105];
ll n,m;
pair<ll,ll>a[105];
void PX()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    memset(dp,-0x3f,sizeof dp);
    // dp[0][1300][m]=0;
    for(ll i=0;i<=m;i++)dp[0][1300][i]=0;
    for(ll i=1;i<=n;i++){
        for(ll k=0;k<=m;k++){
            for(ll j=0;j<=2605;j++){
                dp[i][j][k]=dp[i-1][j][k];
                if(k>=1&&j-2*a[i].second>=0){
                    dp[i][j][k]=max(dp[i-1][j-2*a[i].second][k-1]+a[i].first,dp[i][j][k]);
                }
                if(j-a[i].second>=0){
                    dp[i][j][k]=max(dp[i-1][j-a[i].second][k]+a[i].first,dp[i][j][k]);
                }
                if(k>=1&&j+2*a[i].second<=2600){
                    dp[i][j][k]=max(dp[i-1][j+2*a[i].second][k-1]+a[i].first,dp[i][j][k]);
                }
                if(j+a[i].second<=2600){
                    dp[i][j][k]=max(dp[i-1][j+a[i].second][k]+a[i].first,dp[i][j][k]);
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=m;i++){
        ans=max(ans,dp[n][1300][i]);
    }
    cout<<ans<<endl;
}
int main()
{
    ll T=1;
    // cin>>T;
    while(T--)PX();
}