<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2023-06-08 17:36:50
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2023-06-08 18:05:46
 * @FilePath: \ACM_XCPC_CP\PX-从零开始的ACM模板\SimpleVersion\图论\LCA.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->
# LCA

## 倍增

```c++
#include <bits/stdc++.h>
using namespace std;
/* https://www.luogu.com.cn/problem/P3379 */
const int N = 1e6+100;
const int M = 22;
vector<int> Edge[N];
int Fa[N][M];
int Dep[N];
void Add(int u, int v)  { Edge[u].push_back(v); }
void Dfs(int u, int fa)
{
  Fa[u][0] = fa;  Dep[u] = Dep[fa]+1;
  for(int i=1; i<M; i++) Fa[u][i] = Fa[Fa[u][i-1]][i-1];
  for(int i=0; i<Edge[u].size(); i++) {
    int v = Edge[u][i];
    if(v == fa) continue;
    Dfs(v, u);
  }
}
void Dfs_Init(int rt = 1, int frt = 0)
{
  Dfs(rt, frt);
}
int Lca(int u, int v)
{
  if(Dep[u] < Dep[v]) swap(u, v);
  int dis = Dep[u] - Dep[v];
  for(int i=0; i<M; i++) if(dis&(1<<i)) u = Fa[u][i];
  for(int i=M-1; i>=0; i--) {
    int fu = Fa[u][i], fv = Fa[v][i];
    if(fu != fv) u = fu, v = fv;
  }
  return (u==v) ? u : Fa[u][0];
}

int PX(int __Case = 0)
{
  int n, q, s;
  cin >> n >> q >> s;
  for(int u,v, i=1; i<n; i++) {
    cin >> u >> v;
    Add(u, v);  Add(v, u);
  }
  Dfs_Init(s, 0);
  while(q--) {
    int u, v; cin >> u >> v;
    cout << Lca(u, v) << '\n';
  }
  return 1;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  for(int t=1; t<=T; t++) {
    PX(t);
  }
  return 0;
}
```
