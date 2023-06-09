<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2023-06-09 17:15:29
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2023-06-09 21:43:27
 * @FilePath: \ACM_XCPC_CP\PX-从零开始的ACM模板\SimpleVersion\图论\Dijkstra.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->
# Dijkstra

## 堆优化

单源最短路，堆优化。

```c++
/*https://www.luogu.com.cn/problem/P4779*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+100;
const int Inf = INT_MAX;
int n, m, s;
struct Edge { int v, w; };
vector<Edge> E[N];
int Dis[N], Vis[N];
void Add_edge(int u, int v, int w) { E[u].push_back({v, w}); }
void Dijkstra(int s)
{
  for(int i=0; i<=n; i++) Dis[i] = Inf;
  Dis[s] = 0;
  priority_queue<pair<int, int>> q;
  q.push({0, s});
  while(!q.empty()) {
    int u = q.top().second;
    q.pop();
    if(Vis[u]) continue;
    else Vis[u] = 1;
    for(int i=0; i<E[u].size(); i++) {
      int v = E[u][i].v, w = E[u][i].w;
      if(Dis[v] > Dis[u]+w) {
        Dis[v] = Dis[u] + w;
        q.push({-1*Dis[v], v});
      }
    }
  }
}

int PX(int __Case = 0)
{
  cin >> n >> m >> s;
  for(int u,v,w, i=0; i<m; i++) {
    cin >> u >> v >> w;
    Add_edge(u, v, w);
  }
  Dijkstra(s);
  for(int i=1; i<=n; i++) cout << Dis[i] << " \n"[i==n];
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
