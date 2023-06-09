# Kruskal

## 并查集优化

并查集优化合并。

```c++
/*https://www.luogu.com.cn/problem/P3366*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+100;
const int Inf = INT_MAX;

int n, m, Ans, Cnt;
struct Edge {
  int u, v, w;
  bool operator<(const Edge& t) const { return w < t.w; }
} E[N];
int Dis[N], Vis[N];
void Add_edge(int i, int u, int v, int w) { E[i] = {u, v, w}; }
int Fa[N];
int Find(int x) { return (Fa[x] == x) ? x : Fa[x] = Find(Fa[x]); }
void Merge(int x, int y) { Fa[x] = y; }
bool Kruskal()
{
  Ans = Cnt = 0;
  sort(E, E+m);
  for(int i=0; i<=n; i++) Fa[i] = i;
  for(int i=0; i<m; i++) {
    int fu = Find(E[i].u), fv = Find(E[i].v);
    if(fu != fv) Merge(fu, fv), Ans += E[i].w, Cnt++;
  }
  return Cnt == n-1;
}

int PX(int __Case = 0)
{
  cin >> n >> m;
  for(int u,v,w, i=0; i<m; i++) {
    cin >> u >> v >> w;
    Add_edge(i, u, v, w);
  }
  if(!Kruskal()) cout << "orz\n";
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
