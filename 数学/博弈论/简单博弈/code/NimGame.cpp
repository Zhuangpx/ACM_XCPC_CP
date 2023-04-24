/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-18 15:56:26
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-10-19 13:04:28
 * @FilePath: \apricitye:\桌面\ACM\数学\博弈论\简单博弈\code\NimGame.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    51nod/1069:Nim游戏
    http://www.51nod.com/Challenge/Problem.html#problemId=1069
    n堆物品，每堆有a[i]个，两个玩家轮流取走任意一堆的任意个物品，但不能不取，最后无法操作的人失败，或者说取走最后物品的人胜利。
    异或和为0先手胜利，不为0先手失败。
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        ans=(i==1)?x:(ans^x);
    }
    if(ans==0) cout<<"B\n";
    else cout<<"A\n";
    return 0;
}