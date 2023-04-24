/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-08-10 15:33:48
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-08-10 15:33:55
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数据结构\LCA.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n;
namespace LCA   //  LCA
{
    int dp[N][21],dep[N];
    vector<int> g[N];
    inline void dfs(int x,int fa)
    {
        for(int i=0;i<g[x].size();i++)
        {
            int y=g[x][i];
            if (y==fa) continue;
            dep[y]=dep[x]+1;
            dp[y][0]=x; dfs(y,x);
        }
    }
    void ST()
    {
        for(int j=0;j<19;j++)
            for(int i=1;i<=n;i++)
                dp[i][j+1]=dp[dp[i][j]][j];
    }
    inline int lca(int u,int v)
    {
        if (u==v) return u;
        if (dep[v]>dep[u]) swap(u,v);
        for(int i=18;i>=0;i--)
            if (dep[dp[u][i]]>=dep[v]) u=dp[u][i];
        if (u==v) return u;
        for(int i=18;i>=0;i--)
            if (dp[u][i]!=dp[v][i]) u=dp[u][i],v=dp[v][i];
        return dp[u][0];
    }
}