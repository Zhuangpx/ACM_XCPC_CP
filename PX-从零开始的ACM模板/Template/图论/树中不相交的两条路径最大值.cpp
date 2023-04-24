/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-11-05 11:57:26
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-11-05 12:28:33
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\图论\树中不相交的两条路径最大值.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include <bits/stdc++.h>
const int N = 1e6+5;

/*
    有根树求两条不相交路径最大值 根为1
    dp[i]:i子树两条不相交路径最大值
    f[i]:i子树最大路径
    d[i]:i子树最大链+i
    g[i]:i提两条子链最大值 a-i-b
*/

std::vector<int> e[N];
int dp[N], f[N], g[N], d[N], w[N];
void Dfs(int u, int fa)
{
	dp[u] = f[u] = g[u] = d[u] = w[u];
	int res = 0;
	for (auto v : e[u]) {
		if (v == fa) continue;
		Dfs(v, u);
		dp[u] = std::max({dp[u], dp[v], g[u] + d[v], f[u] + f[v], g[v] + d[u]});
		f[u] = std::max({f[u], f[v], d[v] + d[u]});
		g[u] = std::max({g[u], g[v] + w[u], d[v] + w[u] + res, d[u] + f[v]});
		d[u] = std::max(d[u], d[v] + w[u]);
		res = std::max(res, f[v]);
	}
}
