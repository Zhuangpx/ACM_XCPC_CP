/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-09 18:24:07
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-09 18:24:07
 * @FilePath: \apricitye:\桌面\ACM\collection\2021icpc上海\g.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

 #include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+55;
const ll mod = 998244353;
ll n,ans;
vector<ll>e[N];
inline void add(ll x,ll y)
{
    e[x].push_back(y);
}
ll cal(ll x)
{
    ll res=1;
    x-=1;
    while(x>=1){
        res*=x;res%=mod;x-=2;
    }
    return res%mod;
}
ll dfs(ll u,ll f)
{
    ll res=0;
    for(auto v:e[u]){
        if(v==f)continue;
        res+=dfs(v,u);
    }
    if(res%2==1){
        ans=ans*res%mod;    // u-v
        ans=ans*cal(res-1)%mod;    // v-->...
        return 0;
    }
    else {
        ans=ans*cal(res)%mod;    // u
        return 1;
    }
}
int main()
{
    cin>>n;ans=1;
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        add(x,y),add(y,x);
    }
    dfs(1,0);
    cout<<ans<<'\n';
}