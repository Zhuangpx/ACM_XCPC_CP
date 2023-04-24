/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-19 13:05:40
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-10-19 13:18:56
 * @FilePath: \apricitye:\桌面\ACM\数学\博弈论\简单博弈\code\FibonacciGame.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    hdu2516:取石子游戏 斐波那契博弈
    1堆石子有n个,两人轮流取.先取者第1次可以取任意多个，但不能全部取完.以后每次取的石子数不能超过上次取子数的2倍。取完者胜.先取者负输
    当石子数为斐波那契数时先手必败，否则先手必胜。
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll f[N];
map<ll,bool>isf;
int main()
{
    f[1]=1;f[2]=2;
    isf[1]=1;isf[2]=1;
    for(ll i=3;i<=N;i++)f[i]=f[i-1]+f[i-2],isf[f[i]]=1;
    ll x;
    while(cin>>x){
        if(x==0)break;
        cout<<(isf[x]?"Second win\n":"First win\n");
    }
    return 0;
}