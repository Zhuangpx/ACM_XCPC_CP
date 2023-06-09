# Prim

## 堆优化

堆优化BFS。

```c++
/*https://www.luogu.com.cn/problem/P3366*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+100;
const int Inf = INT_MAX;

int n, m, Ans, Cnt;
struct Edge{ int v, w; };
vector<Edge> E[N];
int Dis[N], Vis[N];
void Add_edge(int u, int v, int w) { E[u].push_back({v, w}); }
bool Prim(int s = 1)
{
  Ans = Cnt = 0;
  for(int i=0; i<=n; i++) Dis[i] = Inf;
  Dis[s] = 0;
  priority_queue<pair<int,int>> q;
  q.push({0, s});
  while(!q.empty()) {
    int u = q.top().second;
    q.pop();
    if(Vis[u]) continue;
    else Vis[u] = 1;
    Ans += Dis[u];
    Cnt++;
    for(int i=0; i<E[u].size(); i++) {
      int v = E[u][i].v, w = E[u][i].w;
      if(Dis[v] > w) Dis[v] = w, q.push({-1*Dis[v], v});
    }
  }
  return Cnt==n;
}

int PX(int __Case = 0)
{
  cin >> n >> m;
  for(int u,v,w, i=0; i<m; i++) {
    cin >> u >> v >> w;
    Add_edge(u, v, w);  Add_edge(v, u, w);
  }
  if(!Prim(1)) cout << "orz\n";
  else cout << Ans << '\n';
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
