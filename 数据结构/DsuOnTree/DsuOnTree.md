<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-05-19 15:06:44
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-05-25 21:35:56
 * @FilePath: \apricitye:\桌面\ACM\数据结构\DsuOnTree\DsuOnTree.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->
# DsuOnTree

cf两篇贴:<https://codeforces.com/blog/entry/44351> <https://codeforces.com/blog/entry/67696>

这里的Dsu并不是并查集，而是跟并查集一样的合并方式:启发式合并，因此也叫**树上启发式合并**

离线处理不带修的子树问题

大概就是先一次dfs处理轻重儿子，然后dfs从根开始算贡献，只用一个cnt数组，当前子树根为u，先处理u所有轻儿子的子树，并且算完之后去掉贡献，即从cnt中删除，然后再处理重儿子的贡献，此时保留到cnt里，最后再暴力处理轻儿子更新，那么就能做到轻儿子的贡献合并到了重儿子的贡献里，时间和空间都很优

为什么是`O(nlogn)`呢，粗略证明，大概就是，由于暴力计算是对每个子树u都进行一次dfs就是是`O(n^2)`，但如果把轻儿子合并到中儿子去，每次大概会省去重儿子的重复计算量，这个重复的计算量大概是log次，所以大概是`O(nlogn)`。

其实树链剖分然后莫队功能也差不多，不过没那么优秀

## 原贴

如何在`O(nlogn)`内处理每颗子树上某个节点`v`的出现次数?

例如:
给一棵树，每个节点有一个颜色，问题是，对于`v`为根的子树，有多少个节点颜色为`c`。

首先dfs去处理每颗子树的大小:

```c++
int sz[maxn];
void getsz(int v,int p)
{
    sz[v]=1;    //  根节点
    for(auto u:g[v])
        if(u!=p) {
            getsz(u,v);
            sz[v]+=sz[u];   //  加上子树u
        }
}
```

于是得到子树`v`的的大小`sz[v]`。

显然最暴力的方法是`O(n^2)`的:

```c++
int cnt[maxn];
void add(int v,int p,int x){
    cnt[ col[v] ] += x;
    for(auto u:g[v])
        if(u!=p)
            add(u,v,x);
}
void dfs(int v,int p){
    add(v,p,1);
    //  先对算子树的，再还原，得到树v的贡献
    add(v,p,-1);
    for(auto u:g[v])    //  再算其他子树贡献
        if(u!=p)
            dfs(u,v);
}
```

然后考虑如何优化

### 1.优化剪枝O(nlognlogn),cnt开n^2空间

```c++
map<int,int> *cnt[maxn];    //  n^2的空间
void dfs(int v,int p){
    //  重儿子
    int mx=-1, bigChild=-1;
    for(auto u:g[v])
        if(u!=p){
            dfs(u,v);
            if(sz[u]>mx) mx=sz[u], bigChild=u;
        }
    if(bigChild!=-1) cnt[v]=cnt[bigChild];
    else cnt[v]=new map<int,int>();
    (*cnt[v])[ col[v] ]++;
    for(auto u:g[v])
        if(u!=p&&u!=bigChild){
            for(auto x:*cnt[u])
                (*cnt[v][x.first])+=x.second;
        }
    //  此时就是子树v的c颜色个数就是:(*cnt[v])[c]
}
```

### 2.再优化O(nlogn),空间n^2,开空间保留子树

```c++
vector<int> *vec[maxn];
int cnt[maxn];
void dfs(int v, int p, bool keep){
    //  找重儿子
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
           mx = sz[u], bigChild = u;
    //  处理子树,保留重儿子贡献
    for(auto u : g[v])
       if(u != p && u != bigChild)
           dfs(u, v, 0);
    if(bigChild != -1)
        dfs(bigChild, v, 1), vec[v] = vec[bigChild];
    else
        vec[v] = new vector<int> ();
    vec[v]->push_back(v);
    cnt[ col[v] ]++;
    //  存下所有子树
    for(auto u : g[v])
       if(u != p && u != bigChild)
           for(auto x : *vec[u]){
               cnt[ col[x] ]++;
               vec[v] -> push_back(x);
           }
    // 此时cnt[c]就是子树v上节点c个数
    // *vec[v]存的是v的所有子树
    //  如果当前v是p的重儿子则保留更新，否则消除
    if(keep == 0)
        for(auto u : *vec[v])
            cnt[ col[u] ]--;
}
```

### 3.轻儿子和重儿子分离,O(nlogn)

```c++
int cnt[maxn];
bool big[maxn];
void add(int v, int p, int x){
    cnt[ col[v] ] += x;
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x)
}
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // 处理轻儿子并且不保留贡献
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;  // 处理重儿子并保留贡献
    add(v, p, 1);
    //  此时cnt[c]为子树v上c个数
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);
}
```

### 4.作者的写法,O(nlogn)

```c++
int cnt[maxn];
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, v, 1);  // bigChild marked as big and not cleared from cnt
    for(auto u : g[v])
    if(u != p && u != bigChild)
        for(int p = st[u]; p < ft[u]; p++)
        cnt[ col[ ver[p] ] ]++;
    cnt[ col[v] ]++;
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    if(keep == 0)
        for(int p = st[v]; p < ft[v]; p++)
        cnt[ col[ ver[p] ] ]--;
}
```

### 5.附带题目(部分)

[cf600E](https://codeforces.com/contest/600/problem/E)

[cf570D](https://codeforces.com/contest/570/problem/D)

[sgu507](https://vjudge.net/problem/SGU-507)(原链挂，转vj)

[cf246E](https://codeforces.com/contest/246/problem/E)

[cf208E](https://codeforces.com/contest/208/problem/E)

[cf291E](https://codeforces.com/contest/291/problem/E)(其实是kmp/AC自动机)

[cf1009F](https://codeforces.com/contest/1009/problem/F)

[cf343D](https://codeforces.com/contest/343/problem/D)(树链剖分/DFS序+线段树也可解)

[cf375D](https://codeforces.com/contest/375/problem/D)

[cf716E](https://codeforces.com/contest/716/problem/E)

[cf741](https://codeforces.com/contest/741/problem/D)

## 习惯的板子

```c++
struct DsuOnTree {
#define MAX 500055
    int n, rot;
    int dep[MAX], sz[MAX], bson[MAX];
    vector<int> e[MAX];
    // ==   Infor

    // ==
    inline void dfs_sz(int u,int fa) {
        sz[u]=1;
        if(fa==-1) dep[u]=1;
        else dep[u]=dep[fa]+1;
        int ma=0;
        for(auto v:e[u]) {
            if(v==fa) continue;
            dfs_sz(v,u);
            sz[u]+=sz[v];
            if(sz[v]>ma) ma=sz[v], bson[u]=v;
        }
        if(ma==0) bson[u]=-1;
    }
    inline void update(int u,int fa,int Bson,int val) {
        // == update

        // ==
        for(auto v:e[u]) {
            if(v==fa||v==Bson) continue;
            update(v,u,Bson,val);
        }
    }
    inline void re_update(int u,int fa) {
        // re update
        update(u,fa,-1,-1);
    }
    inline void dfs_cal(int u,int fa,bool keep) {
        for(auto v:e[u]) {
            if(v==fa||v==bson[u]) continue;
            dfs_cal(v,u,0);
        }
        if(bson[u]!=-1) dfs_cal(bson[u],u,1);
        update(u,fa,bson[u],1);     //  cal
        // == GetAns

        // ==
        if(!keep) re_update(u,fa);   //  re cal
    }
};
```

## 题目

### 散题

上述附带题目

### 专题

vj group:<https://vjudge.net/contest/491517>
