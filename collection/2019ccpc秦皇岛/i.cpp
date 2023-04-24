/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-04 15:57:20
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-05 10:00:03
 * @FilePath: \apricitye:\桌面\ACM\collection\2019ccpc秦皇岛\i.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
/*  模拟+dp
dp[i][j] = min(dp[i][j],dp[i-1][k]+cal[k->j])   //  状态转移+状态距离计算
0 Y = {"QQQ","QQQ","QQQ","QQQ","QQQ","QQQ"}
1 V = {"QQW","QWQ","WQQ","WQQ","WQQ","WQQ"}
2 G = {"QQE","QEQ","EQQ","EQQ","EQQ","EQQ"}
3 C = {"WWW","WWW","WWW","WWW","WWW","WWW"}
4 X = {"QWW","WQW","WWQ","WWQ","WWQ","WWQ"}
5 Z = {"WWE","WEW","EWW","EWW","EWW","EWW"}
6 T = {"EEE","EEE","EEE","EEE","EEE","EEE"}
7 F = {"QEE","EQE","EEQ","EEQ","EEQ","EEQ"}
8 D = {"WEE","EWE","EEW","EEW","EEW","EEW"}
9 B = {"QWE","QEW","EQW","EWQ","WEQ","WQE"}
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
const int N=1e5+55;
#define INF 0x3f3f3f3f
string all[10][6]={
    {"QQQ","QQQ","QQQ","QQQ","QQQ","QQQ"},
    {"QQW","QWQ","WQQ","WQQ","WQQ","WQQ"},
    {"QQE","QEQ","EQQ","EQQ","EQQ","EQQ"},
    {"WWW","WWW","WWW","WWW","WWW","WWW"},
    {"QWW","WQW","WWQ","WWQ","WWQ","WWQ"},
    {"WWE","WEW","EWW","EWW","EWW","EWW"},
    {"EEE","EEE","EEE","EEE","EEE","EEE"},
    {"QEE","EQE","EEQ","EEQ","EEQ","EEQ"},
    {"WEE","EWE","EEW","EEW","EEW","EEW"},
    {"QWE","QEW","EQW","EWQ","WEQ","WQE"},
};
map<char,int>mp;
// unordered_map<char,int>mp;
string s;
vector<int>a;
int len;
int n;
int dp[N][6];
int cal(int l1,int l2,int r1,int r2)    // all[l1][l2] -> all[r1][r2]
{
    if(all[l1][l2]==all[r1][r2])return 0;
    if(all[l1][l2][1]==all[r1][r2][0]&&all[l1][l2][2]==all[r1][r2][1])return 1;
    if(all[l1][l2][2]==all[r1][r2][0])return 2;
    return 3;
}
void init()
{
    mp['Y']=0;mp['V']=1;mp['G']=2;mp['C']=3;mp['X']=4;mp['Z']=5;mp['T']=6;mp['F']=7;mp['D']=8;mp['B']=9;
    memset(dp,0x3f,sizeof dp);
    for(int i=0;i<6;i++)dp[0][i]=3; //init pre
}
void PX()
{
    cin>>s;len=s.size();    // 必须
    for(int i=0;i<len;i++){
        if(i==0||s[i]!=s[i-1])a.push_back(mp[s[i]]);
    }
    n=a.size();
    for(int i=1;i<n;i++)for(int j=0;j<6;j++)for(int k=0;k<6;k++)    //dp[i][j] = min( dp[i][j], dp[i-1][k] + cal[k->j] )
    {
        dp[i][j] = min( dp[i][j], dp[i-1][k]+cal(a[i-1],k,a[i],j));
    }
    // int len_=INF;   //  添加
    int len_=1e9+7;   //  添加
    for(int i=0;i<6;i++)len_=min(len_,dp[n-1][i]);
    ll ans=len_+len;
        // cout<<"len:"<<len<<" len_:"<<len_<<'\n';
    cout<<ans<<'\n';
}

int main()
{
    IOS;
    init();
    int T=1;
    // cin>>T;
    while(T--)PX();
    return 0;
}