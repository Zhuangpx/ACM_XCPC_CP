<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2023-06-09 16:43:34
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2023-06-09 21:55:20
 * @FilePath: \ACM_XCPC_CP\PX-从零开始的ACM模板\SimpleVersion\图论\TopoSort.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->
# Topo Sort

## Bfs

BFS的拓扑序，若字典序最小/大可用优先队列

```c++
/*https://www.luogu.com.cn/problem/U107394*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+100;
int n, m;
vector<int> E[N], Tp;
int Din[N];
void Add_edge(int u, int v) { E[u].push_back(v);  Din[v]++; }
bool Toposort_bfs()
{
  // 若字典序最小/大: 用优先队列
  // queue<int> q;
  priority_queue<int, vector<int>, greater<int>> q;
  for(int i=1; i<=n; i++) if(Din[i] == 0) q.push(i);
  while(!q.empty()) {
    int u = q.top();
    q.pop();
    Tp.push_back(u);
    for(int i=0; i<E[u].size(); i++) {
      int v = E[u][i];
      if(--Din[v] == 0) q.push(v);
    }
  }
  return Tp.size() == n;
}

int PX(int __Case = 0)
{
  cin >> n >> m;
  for(int u,v, i=0; i<m; i++) {
    cin >> u >> v;
    Add_edge(u, v);
  }
  if(!Toposort_bfs()) cout << "-1\n";
  else {
    for(int i=0; i<Tp.size(); i++) cout << Tp[i] << " \n"[i+1==Tp.size()];
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

## Dfs

DFS的拓扑序，遍历时染色（-1，0，1）。

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+100;

int n, m;
vector<int> E[N], Tp;
int Col[N]; //  -1(st) 0(!vis) 1(vis)
void Add_edge(int u, int v) { E[u].push_back(v); }
bool Dfs(int u)
{
  Col[u] = -1;
  for(int i=0; i<E[u].size(); i++) {
    int v = E[u][i];
    if(Col[v] == -1)  return false; //  环
    else {
      if(!Col[v]) if(!Dfs(v)) return false;
    }
  }
  Col[u] = 1;
  Tp.push_back(u);
  return true;
}
bool Toposort_dfs()
{
  memset(Col, 0, sizeof Col);
  for(int i=1; i<=n; i++) {
    if(!Col[i]) if(!Dfs(i)) return false;
  }
  reverse(Tp.begin(), Tp.end());
  return true;
}

int PX(int __Case = 0)
{
  cin >> n >> m;
  for(int u,v, i=0; i<m; i++) {
    cin >> u >> v;
    Add_edge(u, v);
  }
  if(!Toposort_dfs()) cout << "-1\n";
  else {
    for(int i=0; i<Tp.size(); i++) cout << Tp[i] << " \n"[i+1==Tp.size()];
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
