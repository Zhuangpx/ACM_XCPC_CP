/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-19 17:26:52
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-10-19 17:38:25
 * @FilePath: \apricitye:\桌面\ACM\数学\博弈论\简单博弈\code\WythoffGame2.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    51nod/1085：威佐夫博弈 WythoffGame
    http://www.51nod.com/Challenge/Problem.html#problemId=1072
    (b-a)*((1.0+sqrt(5.0))/2.0) == a 先手必败   否则先手必胜 （差值与小者是否满足黄金分割比）
    数字很大，需要模拟乘法
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9;
int main()
{
    ll ratio[3]={618033988,749894848,204586834};
    int T;cin>>T;
    while(T--){
        ll a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        ll d=b-a;
        ll l=d/mod,r=d%mod;
        ll ans=r*ratio[2];
        ans=l*ratio[2]+r*ratio[1]+ans/mod;
        ans=l*ratio[1]+r*ratio[0]+ans/mod;
        ans=d+l*ratio[0]+ans/mod;
        cout<<(ans==a?"B\n":"A\n");
    }
    return 0;
}