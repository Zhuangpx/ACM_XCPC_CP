
#include<bits/stdc++.h>
const int N = 1e6+5;
/*
    有根树 维护节点前k大子链
	dp[i]:i往下最大链
	M[i]:不含根的前k大
*/
//对于需要的前k大，可以进行相对应的修改
//前k大把结构体M进行修改，判断更新换一下就可
//每个结点的前k大子链的值在结构体中
//也可以在更新的时候用to数组保存对应i大的儿子

std::vector<int> e[N];
int dp[N], w[N];
struct ma
{
    int m1, m2, m3, m4;	//	前k大
    int sum;			//	前k大和
} M[N];
void Dfs(int u, int fa, int pre)
{
    for (auto v : e[u]) {
        if (v == fa) continue;
        if (dp[v] >= M[u].m1) M[u] = {dp[v], M[u].m1, M[u].m2, M[u].m3};
        else if (dp[v] >= M[u].m2) M[u] = {M[u].m1, dp[v], M[u].m2, M[u].m3};
        else if (dp[v] >= M[u].m3) M[u] = {M[u].m1, M[u].m2, dp[v], M[u].m3};
        else if (dp[v] > M[u].m4) M[u].m4 = dp[v];
    }
    for (auto v : e[u]) {
        if (v == fa) continue;
        if (dp[v] == M[u].m1) Dfs(v, u, std::max(M[u].m2, pre) + w[u]);
        else Dfs(v, u, std::max(M[u].m1, pre) + w[u]);
    }
    M[u].sum = std::max(M[u].sum, std::max(pre, M[u].m4) + M[u].m3 + M[u].m2 + M[u].m1);
}
