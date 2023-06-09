# Floyd

多源最短路，O(n^3)的DP转移。

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+100;

int n, m;
int Dis[N][N];
void Floyd()
{
  for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        Dis[i][j] = min(Dis[i][j], Dis[i][k]+Dis[k][j]);
}
int PX(int __Case = 0)
{
  cin >> n >> m;
  memset(Dis, 0x3f, sizeof Dis);
  for(int i=1; i<=n; i++) Dis[i][i] = 0;
  for(int u,v,w, i=0; i<m; i++) {
    cin >> u >> v >> w;
    Dis[u][v] = min(Dis[u][v], w);
  }
  Floyd();
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cout << Dis[i][j] << " \n"[j==n];
    }
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
