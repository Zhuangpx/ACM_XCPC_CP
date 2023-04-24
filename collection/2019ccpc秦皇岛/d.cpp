/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-04 14:05:44
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-04 15:56:56
 * @FilePath: \apricitye:\桌面\ACM\collection\2019ccpc秦皇岛\d.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
/*  1/n能除净
    判是否有 2 5 以外的因子
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void PX()
{
    ll n;cin>>n;
    while(n%2==0)n/=2;
    while(n%5==0)n/=5;
    if(n==1)cout<<"No\n";
    else cout<<"Yes\n";
}

int main()
{
    int T=1;
    cin>>T;
    while(T--)PX();
    return 0;
}