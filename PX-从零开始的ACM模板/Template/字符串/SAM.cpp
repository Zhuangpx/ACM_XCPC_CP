/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-10-28 23:27:22
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-11-04 12:03:09
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\字符串\SAM.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include <bits/stdc++.h>


struct EXSAM {  //! 字典树->EXSAM O(n) 含kth dfs处理size
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
#define EXSAM_N (int)(1e6+7)
#define EXSAM_Ch 26
    int Fa[EXSAM_N], Tr[EXSAM_N][EXSAM_Ch+5], Len[EXSAM_N], tot = 1;
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
                for (int i = 0; i < EXSAM_Ch; ++i)Tr[clone][i] = Len[Tr[q][i]] ? Tr[q][i] : 0;    //len为0的不转移
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
        for (int i = 0; i < EXSAM_Ch; ++i) {
            if (Tr[1][i])Q.push({ 1,i });
        }
        while (Q.size()) {
            auto p = Q.front(); Q.pop();
            insert(p.first, p.second);
            int u = Tr[p.first][p.second];
            for (int i = 0; i < EXSAM_Ch; ++i) {
                if (Tr[u][i])Q.push({ u,i });
            }
        }
    }
    // sort & dfs
    bool fl = 0;    //  不同位置的相同子串：0-算一个 1-算多个   fl==0->可求本质不同子串数
    int cnt[EXSAM_N], sort_arr[EXSAM_N], siz[EXSAM_N], sum[EXSAM_N];    //  siz[i]=|Endpos[i]| sum[i]-dp[i]
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
        for(int i=tot;i>=1;i--) for(int c=0;c<EXSAM_Ch;c++) sum[sort_arr[i]] += sum[Tr[sort_arr[i]][c]];
    }
    void kth(int k, std::vector<char>& res, int sta = 1) {
        if(k<=siz[sta]) return ;
        k-=siz[sta];
        for(int c=0;c<EXSAM_Ch;c++) {
            int nxt_sta = Tr[sta][c];
            if(!nxt_sta) continue;
            if(k>sum[nxt_sta]) k-=sum[nxt_sta];
            else return res.push_back((char)(c+'a')), kth(k, res, nxt_sta);
        }
    }
} exsam;


struct SAM {
/*
Data:
    tot:节点数 last:最后更新的节点
    Fa:link后缀链接 Ch:trans_to转移 Len:最大长度
    Sz:endpos大小即出现次数 Cnt:桶 Sort_arr:按Len排序
    Sum:Sum为路径包含的字符串数量，即Sz（同一字符串的出现次数）的总和 同一字符串不同位置算一种，则将sz置1
    1.开数组放全局 引用时先init
    2.开vector注意mle
SAM:
    1为虚节点
    endpos集合为该节点代表的字符串出现的位置集合
Function:
    init:初始化
    sam_extend:插入
    sort_dfs+pre_dfs:按Len基数排序/dfs预处理
    kth:第k小子串
*/
    //! 1.开数组
#define SAM_N (int)(1e6+7)
#define SAM_Ch 30
    int Fa[SAM_N], Ch[SAM_N][SAM_Ch], Len[SAM_N], last, tot;
    int Sz[SAM_N], Cnt[SAM_N], Sort_arr[SAM_N]; //Sz字符串出现次数;
    int Sum[SAM_N];
    bool Vis[SAM_N];
    int Strlen, Chsiz;
    //! 2.开vevtor
    // int Strlen, Chsiz;
    // int tot, last;                          //  n & last_upadte
    // std::vector<int> Len, Fa;               //  maxlen[sta] & link[sta]
    // std::vector<std::vector<int>> Ch;     //  trans[sta][c]
    // std::vector<int> Cnt, Sort_arr, Sum, Sz, Vis;    //  sz[i]=|Endpos[i]| sum[i]-dp[i]
    // SAM(int _strlen, int _chsiz) : tot(1), last(1), Strlen(_strlen*2+2), Chsiz(_chsiz+2) {
    //     Len.resize(_strlen*2+2, 0);
    //     Fa.resize(_strlen*2+2, 0);
    //     Ch.resize(_strlen*2+2, std::vector<int> (_chsiz+2, 0));
    //     //
    //     Sz.resize(_strlen*2+2, 0);
    //     Cnt.resize(_strlen*2+2, 0);
    //     Sort_arr.resize(_strlen*2+2, 0);
    //     Sum.resize(_strlen*2+2, 0);
    //     Vis.resize(_strlen*2+2, 0);
    // }
    void init() {
        Strlen = SAM_N, Chsiz = 27;
        tot = last = 1;
    }
    void sam_extend(int ch) {
        int cur = ++tot, p = last;
        Len[cur] = Len[last] + 1;
        Sz[cur] = 1;
        while (p && Ch[p][ch] == 0) {
            Ch[p][ch] = cur;
            p = Fa[p];
        }
        //  1.
        if (p == 0)Fa[cur] = 1;
        else {  // 2.
            int q = Ch[p][ch];
            // 2A.
            if (Len[p] + 1 == Len[q]) Fa[cur] = q;
            else {  // 2B.
                int clone = ++tot;
                Len[clone] = Len[p] + 1;
                // Ch[clone] = Ch[q];   //! 2.vector的clone
                for (int i = 0; i < Chsiz; ++i)Ch[clone][i] = Ch[q][i]; //！ 1/2.朴素的clone
                while (p && Ch[p][ch] == q) {
                    Ch[p][ch] = clone;
                    p = Fa[p];
                }
                Fa[clone] = Fa[q];
                Fa[q] = Fa[cur] = clone;
            }
        }
        last = cur;
    }
    // sort & dfs
    bool fl = 0;    //!  不同位置的相同子串：0-算一个 1-算多个   fl==0->可求本质不同子串数
    void sort_dfs() {
        //  基数排序 按Len从小排到大
        for (int i = 1; i <= tot; ++i) Cnt[Len[i]]++;
        for (int i = 1; i <= tot; ++i) Cnt[i] += Cnt[i - 1];
        for (int i = tot; i >= 1; --i) Sort_arr[Cnt[Len[i]]--] = i;
        //  按长度大到小枚举 相当于模拟dfs
        for (int i = tot; i >= 1; --i) Sz[Fa[Sort_arr[i]]] += Sz[Sort_arr[i]];
        //  sum[i]表示有经过i的子串数 DAG上转移
        // pre_dfs();   //  dfs或者模拟dfs
        for(int i=1;i<=tot;i++) if(fl) Sum[i] = Sz[i]; else Sum[i] = Sz[i] = 1;
        Sz[1] = Sum[1] = 0;
        for(int i=tot;i>=1;i--) for(int c=0;c<Chsiz;c++) Sum[Sort_arr[i]] += Sum[Ch[Sort_arr[i]][c]];
    }
    void pre_dfs(int from = 1) {
        if (Vis[from])return;
        Sum[from] = Sz[from]; Vis[from] = 1;
        for (int i = 0; i < Chsiz; ++i) {
            if (Ch[from][i]) {
                pre_dfs(Ch[from][i]);
                Sum[from] += Sum[Ch[from][i]];
            }
        }
    }
    //  第k小子串
    void kth(int k, std::vector<char>& res, int sta = 1) {
        if(k<=Sz[sta]) return ;
        k-=Sz[sta];
        for(int c=0;c<Chsiz;c++) {
            int nxt_sta = Ch[sta][c];
            if(!nxt_sta) continue;
            if(k>Sum[nxt_sta]) k-=Sum[nxt_sta];
            else return res.push_back((char)(c+'a')), kth(k, res, nxt_sta);
        }
    }
} ;

