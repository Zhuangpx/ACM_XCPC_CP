/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-18 20:31:56
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-10-19 13:04:33
 * @FilePath: \apricitye:\桌面\ACM\数学\博弈论\简单博弈\code\WythoffGame.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    51nod/1072：威佐夫博弈 WythoffGame
    http://www.51nod.com/Challenge/Problem.html#problemId=1072
    (b-a)*((1.0+sqrt(5.0))/2.0) == a 先手必败   否则先手必胜 （差值与小者是否满足黄金分割比）
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;cin>>T;
    while(T--){
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        int ans=(b-a)*((1.0+sqrt(5.0))/2.0);
        if(ans==a)cout<<"B\n";
        else cout<<"A\n";
    }
    return 0;
}