/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-11-02 20:21:07
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-11-02 20:22:19
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数据结构\sqrtTreeblocks.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include <bits/stdc++.h>

using mint = int;
const int B = 400;
struct sqrtTree {
    std::vector<std::vector<mint>> blocks;
    std::vector<mint> dp;
    std::vector<int> lazy,v;
    int n;
    sqrtTree(int n) : n(n) {
        int k = (n+B-1)/B;
        blocks.resize(k, std::vector<mint>(B));
        lazy.resize(k);
        v.resize(n),dp.resize(n);
    }
    void push(int i) {
        if(!lazy[i]) return;
        for(int j=i*B;j<std::min(n,(i+1)*B);++j) {
            v[j]+=lazy[i];
        }
        lazy[i]=0;
    }
    void pull(int i) {
        assert(lazy[i]==0);
        int l = i*B,r = std::min(n,(i+1)*B);
        int mn = *min_element(v.begin()+l,v.begin()+r);
        auto& b = blocks[i];
        std::fill(b.begin(), b.end(), mint(0));
        for(int j=l;j<r;++j) {
            v[j]-=mn;
            b[v[j]]+=dp[j];
        }
        std::partial_sum(b.begin(), b.end(), b.begin());
        lazy[i]=mn;
    }
    void update(int i, mint v) {
        push(i/B);
        dp[i]=v;
        pull(i/B);
    };
    void update(int l, int r, int sgn) {
        int i = l/B, j = r/B;
        push(i),push(j);
        while(l<=r && l<(i+1)*B) {
            v[l++]+=sgn;
        }
        while(r>=l && r>=j*B) {
            v[r--]+=sgn;
        }
        pull(i);
        if(i!=j) pull(j);
        for(int k=i+1;k<j;++k) {
            lazy[k]+=sgn;
        }
    }
    mint query(int k) {
        mint ans=0;
        for(int i=0;i<(int)blocks.size();++i) {
            int l = k-lazy[i], r = B-1;
            if(l<r) {
                ans+=blocks[i][r];
                if(l>=0) ans-=blocks[i][l];
            }
        }
        return ans;
    }
};
