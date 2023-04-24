struct Splay {
    int Ch[N][2], Fa[N], Val[N], Cnt[N], Sz[N], V[N];
    bool Rev[N];
    int rt, tot, n, cnt = -1;
    void pushup(int x) { Sz[x] = Sz[Ch[x][0]] + Sz[Ch[x][1]] + Cnt[x]; }
    void pushdown(int x) {
        if (Rev[x]) {
            Rev[x] = 0;
            swap(Ch[x][0], Ch[x][1]);
            Rev[Ch[x][0]] ^= 1; Rev[Ch[x][1]] ^= 1;
        }
    }
    void update(int x, int top = 0) {
        if (x == top)return;
        update(Fa[x], top);
        pushdown(x);
    }
    bool chk(int x) { return x == Ch[Fa[x]][1]; }
    void rotate(int x) {
        int y = Fa[x], z = Fa[y], chx = chk(x), chy = chk(y);
        Ch[y][chx] = Ch[x][!chx]; if (Ch[x][!chx])Fa[Ch[x][!chx]] = y;
        Ch[x][!chx] = y; Fa[y] = x;
        if (z)Ch[z][chy] = x; Fa[x] = z;
        pushup(y);
        pushup(x);
    }
    void splay(int x, int top = 0) {
        update(x, top);
        for (int f = Fa[x]; f = Fa[x], f != top; rotate(x)) {
            if (Fa[f] != top)rotate(chk(x) == chk(f) ? f : x);
        }
        if (top == 0)rt = x;
        pushup(x);
    }
    int kth(int rt, int k) {
        pushdown(rt);
        if (k <= Sz[Ch[rt][0]])return kth(Ch[rt][0], k);
        k -= Sz[Ch[rt][0]] + Cnt[rt];
        if (k <= 0)return rt;
        return kth(Ch[rt][1], k);
    }
    int find(int v) {
        int cur = rt;
        while (cur) {
            if (v == Val[cur])return cur;
            if (v < Val[cur])cur = Ch[cur][0];
            else cur = Ch[cur][1];
        }
        return 0;
    }
    void ins(int v) {
        if (!rt) {
            rt = ++tot;
            Val[tot] = v;
            Cnt[tot] = 1;
            pushup(rt);
            return;
        }
        int x = find(v);
        if (x) {
            splay(x);
            Cnt[x]++;
            pushup(x);
            return;
        }
        int cur = rt, last = 0;
        while (cur) {
            if (v < Val[cur])last = cur, cur = Ch[cur][0];
            else last = cur, cur = Ch[cur][1];
        }
        Val[++tot] = v; Cnt[tot] = 1;
        Ch[last][v > Val[last]] = tot; Fa[tot] = last;
        splay(tot);
    }
    int pre() {
        int cur = Ch[rt][0];
        if (!cur)return cur;
        while (Ch[cur][1])cur = Ch[cur][1];
        return cur;
    }
    int nxt() {
        int cur = Ch[rt][1];
        if (!cur)return cur;
        while (Ch[cur][0])cur = Ch[cur][0];
        return cur;
    }
    void del(int v) {
        int x = find(v);
        if (!x)return;
        splay(x);
        if (Cnt[rt] > 1) {
            Cnt[rt]--;
            pushup(rt); return;
        }
        int flag = -1;
        if (x = pre())flag = 1;
        else if (x = nxt())flag = 0;
        if (flag != -1) {
            splay(x);
            int x = rt, y = Ch[rt][flag], z = Ch[Ch[rt][flag]][flag];
            Ch[x][flag] = z; if (z)Fa[z] = x;
            pushup(rt);
            return;
        }
        rt = 0;
    }
    void reverse(int l, int r) {
        if (l == r)return;
        int L = kth(rt, l), R = kth(rt, r + 2);
        splay(L), splay(R, rt);
        pushdown(L), pushdown(R);
        int d = Ch[R][0];
        Rev[d] ^= 1;
    }
    void print(int x) {
        if (Rev[x])pushdown(x);
        if (Ch[x][0])print(Ch[x][0]);
        if (Val[x] != INF && Val[x] != -INF)
            V[++cnt] = Val[x];
        if (Ch[x][1])print(Ch[x][1]);
    }
    void build() {
        for (int i = 0; i <= n + 1; ++i) ins(V[i]);
    }
} ;