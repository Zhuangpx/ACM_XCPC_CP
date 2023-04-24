/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-04 14:05:54
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-03-04 15:55:42
 * @FilePath: \apricitye:\桌面\ACM\collection\2019ccpc秦皇岛\f.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
/*  仙人掌图
    找环->至少删一边->2^i-1
    剩下的非环边->01->2^i
*/
#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define ll long long
const int N=3e5+55;
const int M=5e5+55;
const int mod= 998244353;
ll f[M];
void init(){
    f[0]=1;
    for(int i=1;i<M;i++)f[i]=f[i-1]*2%mod;
}
bool vis[N];
bool has[N];
ll dep[N];
ll ans=1;
int n,m;
ll cnt=0;
vector<int>e[M];
void add(int u,int v)
{
    e[u].push_back(v);
    e[v].push_back(u);
}
void dfs(int u,int fa)
{
    vis[u]=1;
    has[u]=1;
    // dep[u]=dep[fa]+1;
    for(auto v:e[u]){
        if(v==fa||(dep[v]>0&&dep[v]==dep[u]-1))continue;
        // if(has[v]){
        //     ll de=f[dep[u]-dep[v]+1]-1; // 2^(length)-1
        //     ans=((ans%mod)*((de+mod)%mod))%mod; // ans=ans*(2^(length)-1)
        //     cout<<"end:"<<v<<'\n';
        //     cout<<"de:"<<de<<'\n';
        //     cout<<"add:"<<((de+mod)%mod)<<'\n';
        //     cout<<"vis:\n";
        //     for(int i=1;i<=n;i++)cout<<i<<' '<<vis[i]<<'\n';
        //     cout<<'\n';
        // }
        // if(vis[v])continue;dfs(v,u);
        // if(!vis[v])dfs(v,u),cout<<"dfs:"<<v<<'\n';    // dfs(v)
        if(dep[v]==0){
            dep[v]=dep[u]+1;dfs(v,u);
        }
        else if(dep[u]>=dep[v]){
            ll de=f[dep[u]-dep[v]+1]-1; // 2^(length)-1
            ans=((ans%mod)*((de+mod)%mod))%mod; // ans=ans*(2^(length)-1)
            cnt+=dep[u]-dep[v]+1;
        }
    }
    has[u]=0;   // multi point
}
void PX()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        add(u,v);
        // add(v,u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])/*cout<<"dfs:"<<i<<'\n',*/dep[i]=1,dfs(i,0);
    }
    m-=cnt;
    if(m>1)ans=(ans%mod)*(f[m]%mod)%mod;
    cout<<ans%mod<<'\n';
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