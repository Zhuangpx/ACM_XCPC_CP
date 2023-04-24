/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2023-01-25 14:47:36
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2023-01-25 14:47:47
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数据结构\TrieTree.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        vector<int> son;
        int count;
        Node(): son(11, -1), count(0) {}
    };

    Trie(): pool(32), next(1) {}

    void add(vector<int> &s) {
        int cur = 0;
        for(int i=0; i<s.size(); i++) {
            int c = s[i];
            if (pool[cur].son[c] == -1) {
            	if (pool.size() <= next) pool.resize(pool.size() * 2);
            	pool[cur].son[c] = next++;
            }
            cur = pool[cur].son[c];
            pool[cur].count++;
        }
    }

    int get(vector<int> &s) {
        int ret = 0;
        int cur = 0;
        for(int i=0; i<s.size(); i++) {
            int c = s[i];
            cur = pool[cur].son[c];
            if (cur == -1) break;
            ret++;
        }
        return ret;
    }

    vector<Node> pool;
    int next;
};