/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-10-19 16:55:44
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-10-19 17:02:03
 * @FilePath: \apricitye:\桌面\ACM\数学\博弈论\简单博弈\code\BashGame3.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    51nod/1068:BashGame3
    http://www.51nod.com/Challenge/Problem.html#problemId=1068
    每次只能拿2的整数幂，并且n<=1e1000
    三的倍数先手必败
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;cin>>T;
    while(T--){
        string s;cin>>s;
        int len=s.size();
        int sum=0;
        for(int i=0;i<len;i++)sum+=s[i]-'0',sum%=3;
        cout<<(sum==0?"B\n":"A\n");
    }
    return 0;
}