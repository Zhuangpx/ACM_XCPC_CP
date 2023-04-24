/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-04 14:05:23
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-05 11:07:08
 * @FilePath: \apricitye:\桌面\ACM\collection\2019ccpc秦皇岛\a.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
/*  直角三角形
    边转为向量 先格式化
    a,b为直角边: a*b==0 -> ax*bx+ay*by==0 -> ax==by&&bx==-ay || ax==-by&&bx==ay
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2022;
const ll hash_num=3e9+9;    // hash number -> x*(hash_num)+y
pair<int,int>p[N],a[N]; //P A
unordered_map<ll,int>mp;  //mp
int ans[N];
int n,q;
inline void normalize(pair<int,int>& x)
{
    int dx=x.first,dy=x.second;
    int dg=__gcd(abs(dx),abs(dy));  // x,y/=gcd(x,y)->gcd(x,y)==1
    x.first=dx/dg,x.second=dy/dg;
}
inline ll _hash(pair<int,int> x)   // hash->(x,y)->x*(hash_num)+y
{
    return hash_num*1ll*x.first+1ll*x.second;
}
void PX()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>p[i].first>>p[i].second;
    for(int i=1;i<=q;i++)cin>>a[i].first>>a[i].second;
    //  作为斜边
    for(int i=1;i<=q;i++){
        mp.clear(); //claer mp
        for(int j=1;j<=n;j++){
            pair<int,int>now(a[i].first-p[j].first,a[i].second-p[j].second);
            normalize(now);     // 格式化
            mp[_hash(now)]++;   // now->hash->mp++
        }
        for(int j=1;j<=n;j++){
            pair<int,int>now(a[i].first-p[j].first,a[i].second-p[j].second);
            normalize(now);     // 格式化
            ans[i]+=mp[_hash({-1*now.second,now.first})];
            ans[i]+=mp[_hash({now.second,-1*now.first})];
        }
        ans[i]/=2;  // 作为斜边枚举直角边对数 <i,j>和<j,i>相同 重复计算 须/=2
    }
    // cout<<"==\n";
    // for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
    // cout<<"==\n";
    //  作为直角边
    for(int i=1;i<=n;i++){
        mp.clear();
        for(int j=1;j<=n;j++){
            if(i!=j){
                pair<int,int>now(p[i].first-p[j].first,p[i].second-p[j].second);
                normalize(now);     // 格式化
                mp[_hash(now)]++;   // now->hash->mp++
            }
        }
        for(int j=1;j<=q;j++){
            pair<int,int>now(p[i].first-a[j].first,p[i].second-a[j].second);
            normalize(now);     // 格式化
            ans[j]+=mp[_hash({-1*now.second,now.first})];
            ans[j]+=mp[_hash({now.second,-1*now.first})];
        }
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
}

int main()
{
    int T=1;
    // cin>>T;
    while(T--)PX();
}