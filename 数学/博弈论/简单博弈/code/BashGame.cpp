/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-18 16:26:06
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-10-18 19:50:20
 * @FilePath: \apricitye:\桌面\ACM\数学\博弈论\简单博弈\code\BashGame.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    51nod/1066:BashGame
    http://www.51nod.com/Challenge/Problem.html#problemId=1066
    有 1 堆石子，总个数是 n ，两名玩家轮流在石子堆中拿石子，每次至少取 1 个，至多取 m 个。取走最后一个石子的玩家为胜者。判定先手和后手谁胜。
    若 n%(m+1)==0 先手必胜，否则先手必败。
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        if(n%(m+1))cout<<"A\n";
        else cout<<"B\n";
    }
    return 0;
}