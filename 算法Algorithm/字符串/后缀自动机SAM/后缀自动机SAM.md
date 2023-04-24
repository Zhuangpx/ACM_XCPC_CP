<!--
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-10-04 19:08:46
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-11-02 14:38:51
 * @FilePath: \apricitye:\桌面\ACM\算法Algorithm\字符串\后缀自动机SAM\后缀自动机SAM.md
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
-->

# 后缀自动机SAM

文章：<https://oi.men.ci/suffix-automaton-notes/>，<https://oi-wiki.org/string/sam/>

视频：<https://www.bilibili.com/video/BV1wa4y1a7Ag>

<https://www.luogu.com.cn/blog/command-block/hou-zhui-zi-dong-ji-xue-xi-bi-ji-ying-yong-pian-post>

<https://www.luogu.com.cn/training/5322#information>

<https://www.cnblogs.com/UntitledCpp/p/SAM_Practice.html>

<https://www.cnblogs.com/UntitledCpp/p/SAM_Study.html>

## 前置

### 字符集

就是字符（串）的集合。

### 子串结束位置endpos[subs]与状态集

`endpos[subs]` 表示子串`subs`在原串中结束位置的集合，下标可能0/1开始。

`endpos[subs]` 相同的子串，为一个等价类，在`SAM`用一个状态表示。

所有`endpos[subs]` 的集合即为`SAM`的状态集。

#### endpos[subs]相关定义

`substr[sta]`：状态`sta`包含的所有子串的集合
`mxsub[sta]`：状态`sta`包含的子串最长者
`mnsub[sta]`：状态`sta`包含的子串最短者

#### endpos[subs]的性质

- 性质1

> 两个子串s1, s2，设`|s1|<=|s2|`，有：
> `s1==suf(s2) iff endpos[s2]属于endpos[s1]`
> `s1!=suf(s2) iff endpos[s1]与endpos[s2]交集为空`

- 性质2

> 任意状态`sta`，`substr[sta]`任取子串`str`，都有`str`是`mxsub[sta]`的后缀。

- 性质3

> 任意状态`sta`，任取`mxsub[sta]`的后缀`str`，若`|mnsub[sta]| <= |str| <= |mxsub[sta]|`，那么`str`属于`substr[sta]`。

推论：

> 把`substr[sta]`按长度排序，相邻满足后缀关系。

### 后缀链接

构造SAM需要后缀链接。

substr[sta] 包含的是一堆连续的 mxsub[sta] 的后缀，但会在中间某个地方断掉（后缀变短结束的地方最佳状态集也变大），把断掉的状态链接起来就是后缀链接。记作 `link[sta1] = sta2` ，那么显然 `endpos[sta1]` 是比 `endpos[sta2]` 要小的。

### 状态转移

#### next[sta]

一个状态 sta ，找到对应的 endpos 后一个字符，得到下一个字符的集合，记作 next[sta] 。

显然， substr[sta] 后续加上某个 next[sta] 之后都属于同一个状态（结束位置都是 next[sta] 的位置）。

#### 转移函数

要找到 trans(sta, c) 转移过后的状态，其中 c 是某个 next[sta] ，只要找到包含 mxsub[sta]+c 这个串的状态即可。

## 构造

### 存

`maxlen[sta]`：sta包含的最长子串长度
`minlen[sta]`：sta包含的最短子串长度
`trans[sta][c]`：sta的转移函数，c为字符
`link[sta]`：sta的后缀链接

### 后缀链接路径

一段连续后缀显然是若干个后缀链接的状态链接起来的，并且会链接到初始状态（空），称为后缀链接路径，记作 `suffix_path[u->S]` ，其中 `S` 为初始状态，即对应字符串为空。

### 两种情况

- 情况1

suffix_path[u->S] 上的所有节点 u ，都满足 `trans[u][s[i+1]]==NULL`

此时新增状态 z ，令 `trans[u][s[i+1]]==z` 并且令 `link[z]=S` 即可。

- 情况2

suffix_path[u->S] 上的存在节点 u ，都满足 `trans[u][s[i+1]]!=NULL`

此时新增状态 z 。

找到 suffix_path[u->S] 上满足上述的第一个状态 v ，令 `trans[v][s[i+1]]==x` ，根据 `x` 包含的子串的情况，再进行分类。

A：`maxlen[v] + 1 == maxlen[x]` ，则 z 的后缀链接刚好是 x 。只要 `link[z]=x` 即可。

B：`maxlen[v] + 1 < maxlen[x]` 。

此时把 x 里长度 `< maxlen[v] + 1` 的子串拆出来成为 y ，然后：

先 `trans[v..w][c]=y` 。
再把原先的 link[x] 给 link[y] ，即 `link[y]=link[x]`
最后令 `link[x]=link[z]=y` 。

### 复杂度

字符串s长为n，构造的SAM状态个数不超过 `2*n-1` ，转移的数量不超过 `3*n-4` （对于n>=3）。

## 板子

### SAM

```c++
// 1.vector
struct SAM {
    int siz, last;                  //  size & last_upadte
    vector<int> mxlen, link;        //  maxlen[sta] & link[sta]
    vector<vector<int>> trans_to;   //  trans[sta][c]
    SAM(int strlen, int chsiz) : siz(1), last(1) {
        mxlen.resize(strlen*2+2, 0);
        link.resize(strlen*2+2, 0);
        trans_to.resize(strlen*2+2, vector<int> (chsiz+2, 0));
    }
    void sam_extend(int ch) {
        int p=0, now=++siz;
        mxlen[now] = mxlen[last] + 1;
        for(p=last; p>0&&!trans_to[p][ch]; p=link[p]) trans_to[p][ch] = now;
        // 1.
        if(!p) link[now] = 1;
        else {  // 2.
            int res = trans_to[p][ch];
            // A.
            if(mxlen[res] == mxlen[p] + 1) link[now] = res;
            else {  // B.
                int new_p = ++siz;
                mxlen[new_p] = mxlen[p] + 1;
                trans_to[new_p] = trans_to[res], link[new_p] = link[res];
                while(p>0 && trans_to[p][ch] == res) trans_to[p][ch] = new_p, p = link[p];
                link[now] = link[res] = new_p;
            }
        }
        last = now;
    }
};
```

### EXSAM

字典树优化，O(n)构建。

```c++
const int N = 1e5+5;
struct EXSAM {
/*
Use
  1.init 2.ins 3.build
Build
  // add
  sta(c) : xxxc xxc xc
    add(a)
  sta(c)->sta(a) : xxxca xxca xca
  link[sta(c)] : c ca
  link[sta(c)] -> sta(c) : ca c
  // len
  len[sta(c)] : max len of sta(c)
  // fa
  link(sta(c))
  // sta
  1 : Begin & Virtual
  2-tot : Use
  Mean : some substrings -> some path
TrieTree->EXsam->O(n)
*/
    int Fa[N*2], Tr[N*2][26], Len[N*2], tot = 1;
    void init() {
        tot = 1;
    }
    void ins(char s[]) {
        int p = 1;
        int n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            int ch = s[i] - 'a';
            if (Tr[p][ch] == 0)Tr[p][ch] = ++tot;
            p = Tr[p][ch];
        }
    }
    void insert(int last, int ch) {
        int cur = Tr[last][ch];
        int p = Fa[last];               //last->cur finish
        Len[cur] = Len[last] + 1;       //Sz[cur] = 1;
        siz[cur] = 1;                   //叶节点
        while (p && Tr[p][ch] == 0) {
            Tr[p][ch] = cur;
            p = Fa[p];
        }
        if (p == 0)Fa[cur] = 1;
        else {
            int q = Tr[p][ch];
            if (Len[p] + 1 == Len[q]) Fa[cur] = q;
            else {
                int clone = ++tot;
                Len[clone] = Len[p] + 1;
                for (int i = 0; i < 26; ++i)Tr[clone][i] = Len[Tr[q][i]] ? Tr[q][i] : 0;    //len为0的不转移
                while (p && Tr[p][ch] == q) {
                    Tr[p][ch] = clone;
                    p = Fa[p];
                }
                Fa[clone] = Fa[q];
                Fa[q] = Fa[cur] = clone;
            }
        }
    }
    void build() {
        std::queue<std::pair<int, int>>Q;
        for (int i = 0; i < 26; ++i) {
            if (Tr[1][i])Q.push({ 1,i });
        }
        while (Q.size()) {
            auto p = Q.front(); Q.pop();
            insert(p.first, p.second);
            int u = Tr[p.first][p.second];
            for (int i = 0; i < 26; ++i) {
                if (Tr[u][i])Q.push({ u,i });
            }
        }
    }
    // sort & dfs
    bool fl = 0;    //  不同位置的相同子串：0-算一个 1-算多个   fl==0->可求本质不同子串数
    int cnt[N*2], sort_arr[N*2], siz[N*2], sum[N*2];    //  siz[i]=|Endpos[i]| sum[i]-dp[i]
    void sort_dfs() {
        //  基数排序 按Len从小排到大
        for(int i=1;i<=tot;i++) cnt[Len[i]]++;
        for(int i=1;i<=tot;i++) cnt[i]+=cnt[i-1];
        for(int i=1;i<=tot;i++) sort_arr[cnt[Len[i]]] = i, cnt[Len[i]]--;
        //  按长度大到小枚举 相当于模拟dfs
        for(int i=tot;i>=1;i--) siz[Fa[sort_arr[i]]] += siz[sort_arr[i]];
        //  sum[i]表示有经过i的子串数 DAG上转移
        for(int i=1;i<=tot;i++) if(fl) sum[i]=siz[i]; else sum[i]=siz[i]=1;
        siz[1] = sum[1] = 0;
        for(int i=tot;i>=1;i--) for(int c=0;c<26;c++) sum[sort_arr[i]] += sum[Tr[sort_arr[i]][c]];
    }
    void kth(int k, std::vector<char>& res, int sta = 1) {
        if(k<=siz[sta]) return ;
        k-=siz[sta];
        for(int c=0;c<26;c++) {
            int nxt_sta = Tr[sta][c];
            if(!nxt_sta) continue;
            if(k>sum[nxt_sta]) k-=sum[nxt_sta];
            else return res.push_back((char)(c+'a')), kth(k, res, nxt_sta);
        }
    }
} exsam;
```

## 性质

### 性质1 - 空间性质

字符串s长为n，构造的SAM状态个数不超过 `2*n-1` ，转移的数量不超过 `3*n-4` （对于n>=3）。

### 性质2 - 基本性质

SAM是个DAG。

每个子串都是从初始状态开始的某条路径，即子串和路径相互对应。

### 性质3 - ParentTree

把link[i]作为i的parent建树得到的树叫parent树，也就是link树。

根：虚节点

叶：每次insert进去新增的为叶

parent和son：向下len增加

`i` 节点对应的子串出现次数相同 = `i` 子树的叶节点个数

跑dfs可以建树跑，也可以排序模拟：

```c++
// Parent Tree
vector<int> e[N];
int siz[N];
void addedge(int u_pa, int u_son) { //  link[i] is the parent of i
    e[u_pa].push_back(u_son);       //  u_pa -> u_son
}
void build_patree() {
    for(int i=2;i<=tot;i++) addedge(Fa[i], i);
}
void dfs(int u) {
    for(auto v:e[u]) {
        dfs(v);
        siz[u] += siz[v];
    }
}
// sort & dfs
int cnt[N], sort_arr[N], siz[N];
void sort_dfs() {
    //  基数排序 按Len从小排到大
    for(int i=1;i<=tot;i++) cnt[Len[i]]++;
    for(int i=1;i<=tot;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<=tot;i++) sort_arr[cnt[Len[i]]] = i, cnt[Len[i]]--;
    //  按长度大到小枚举 相当于模拟dfs
    for(int i=tot;i>=1;i--) siz[Fa[sort_arr[i]]] += siz[sort_arr[i]];
}
```

### 性质4- 节点性质

节点 `i` 表示一个Endpos集以及该集对应的子串（不一定是后缀）

子串长度范围：`[ Len[link[i]]+1, Len[i] ]`

子串种类数：`Len[i] - Len[link[i]]`

每种子串的次数：`siz[i] = |Endpos[i]| = cnt[叶节点]`

## 应用

### 子串出现次数

建SAM，然后对parent树跑dfs，某个状态对应的子串的出现次数相同且等于该状态所在子树的叶节点个数，建SAM时每次insert的节点是叶节点。

```c++
// Parent Tree
vector<int> e[N];
int siz[N];
int ans;
void addedge(int u_pa, int u_son) { //  link[i] is the parent of i
    e[u_pa].push_back(u_son);       //  u_pa -> u_son
}
void build_patree() {
    for(int i=2;i<=tot;i++) addedge(Fa[i], i);
}
void dfs(int u) {
    for(auto v:e[u]) {
        dfs(v);
        siz[u] += siz[v];
    }
    if(siz[u]>1) chmax(ans, siz[u]*Len[u]); //  cal
}
```

也可以不要dfs，按长度进行排序，倒着跑，相当于模拟dfs，统计贡献即可。

```c++
// sort & cal
int ans = 0;
int cnt[N], sort_arr[N], siz[N];
void cal() {
    //  基数排序 按Len从小排到大
    for(int i=1;i<=tot;i++) cnt[Len[i]]++;
    for(int i=1;i<=tot;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<=tot;i++) sort_arr[cnt[Len[i]]] = i, cnt[Len[i]]--;
    //  按长度大到小枚举 相当于模拟dfs
    for(int i=tot;i>=1;i--) {
        int sta = sort_arr[i];
        siz[Fa[sta]] += siz[sta];
        if(siz[sta]>1) chmax(ans, siz[sta]*Len[sta]);   //  cal
    }
}
```

### 检查子串是否出现

先构建SAM，然后模式串从头开始匹配，沿着边转移，当无法转移时为匹配的最长前缀，如果没有匹配完说明并未出现。

### 检查子串第一次出现位置

### 检查子串所有出现位置

### 检查子串出现次数

### 本质不同子串的个数

用parent树的性质：`i` 节点对应的子串种类数量 = `cal[i] = Len[i] - Len[link[i]]` ，`Ans = sum{cal[i]}`

或者在DAG上DP，计算以虚点为起点的不同路径数即可：`dp[u] = sum{dp[v]} +1` -> Ans = dp[1] - 1(减掉空串)

### 本质不同子串的总长度

上一例的延伸，同样可以的DAG上DP：`dp2[u] = sum{dp[v]+dp2[v]}` -> Ans = len[1] （u相比v状态都多了一个字符，因此有子串个数*1的贡献，再加上v状态的长度和）

或者parent树的性质：每个节点对应的后缀长度和是 `cal2[i] = Len[i]*(Len[i]+1)/2` ，减掉其link[i]的就是该节点的贡献，对节点求和即可。`Ans = sum{cal2[i] - link[cal2[i]]}`

### 字典序第k大子串

上两例的延伸，第k大子串即第k大路径，预处理每个状态的路径数（注意处理需要子串是否可重复贡献），然后从根开始找第k大路径。

### 任意子串出现次数

### 最小循环移位

### 最短的没有出现的子串

### 最长公共子串

## 经典题

### 洛谷 P3804 【模板】后缀自动机 (SAM)

求字符串所有出现次数不为1的子串的出现次数*该子串长度的最大值

建SAM，然后对parent跑dfs，有一个trick，某个状态对应的子串的出现次数相同且等于该状态所在子树的叶节点个数。

### 洛谷 P2408 不同子串个数 & P4070 [SDOI2016]生成魔咒

求不同子串个数

用parent树的性质：`i` 节点对应的子串数量 = `Len[i] - Len[link[i]]`

或者在DAG上DP，计算以虚点为起点的不同路径数即可：dp[u] = sum{dp[v]} +1 -> Ans = dp[1] - 1(减掉空串)

拓扑或者直接跑：

```c++
void dfs(int u) {
    if(dp[u]) return ;
    dp[u] = 1;
    for(int i=0; i<26; i++) {
        if(trans_to[u][i]) {
            dfs(trans_to[u][i]);
            dp[u]+=dp[trans_to[u][i]];
        }
    }
}
```
