/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-03 22:18:04
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-09 18:23:19
 * @FilePath: \apricitye:\桌面\ACM\collection\2021icpc上海\d.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void px()
{
    ll p,q;cin>>p>>q;
    ll g=__gcd(p,q);
    p/=g,q/=g;
    ll d=p*p-4*q*q;
    ll sd=sqrt(d);
    if(sd*sd!=d){
        cout<<"0 0\n";return;
    }
    ll a=p+sd,b=2*q;
    cout<<a<<' '<<b<<'\n';
}
int main()
{
    ll t;cin>>t;
    while(t--)px();
}