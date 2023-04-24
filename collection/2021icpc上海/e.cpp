/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-09 18:23:43
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-09 18:23:44
 * @FilePath: \apricitye:\桌面\ACM\collection\2021icpc上海\e.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+55;
ll a[N];
void PX()
{
    ll n,k;cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    ll ans=0;
    ll pre=a[1];
    ll cnt=1;
    for(ll i=2;i<=n;i++){
        if(a[i]-pre>=k)cnt++,pre=a[i];
    }
    cout<<cnt<<'\n';
}
int main(){
    ll T=1;while(T--)PX();
}