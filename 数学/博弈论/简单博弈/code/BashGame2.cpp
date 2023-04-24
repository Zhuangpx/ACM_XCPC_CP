/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-19 16:36:34
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-10-19 16:53:59
 * @FilePath: \apricitye:\桌面\ACM\数学\博弈论\简单博弈\code\BashGame2.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    51nod/1067:BashGame2
    http://www.51nod.com/Challenge/Problem.html#problemId=1067
    每次只能拿1,3,4个
    模7余数0和2
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;cin>>T;
    while(T--){
        long long n;cin>>n;
        bool ans=(n%7==0||n%7==2);
        cout<<(ans?"B\n":"A\n");
    }
    return 0;
}