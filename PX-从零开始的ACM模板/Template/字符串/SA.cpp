
#include <bits/stdc++.h>

// SA
class SuffixArray {
public:
    using size_type = unsigned;
    using pointer = size_type*;
    using const_pointer = const size_type*;
    const_pointer sa, rk, ht;

private:
    std::unique_ptr<size_type[]> data;

private:
    template<typename S>
    inline static bool substring_equal(const S& s, size_type p1, size_type p2, size_type len) {
        for (size_type i = 0;i < len;++i)
            if (s[p1 + i] != s[p2 + i])
                return false;
        return true;
    }

    template<typename S>
    inline static void induced_sort(
        const S& s,
        pointer sa,
        bool* type,
        pointer pos,
        pointer lbuk,
        pointer sbuk,
        size_type n,
        size_type m,
        size_type n0) {
        std::fill_n(sa, n, 0);
        lbuk[0] = 0;
        for (size_type i = 1;i < m;++i)
            lbuk[i] = sbuk[i - 1];
        for (size_type i = n0;i-- > 0;)
            sa[--sbuk[s[pos[i]]]] = pos[i];
        sbuk[m - 1] = n;
        for (size_type i = 1;i < m;++i)
            sbuk[i - 1] = lbuk[i];
        sa[lbuk[s[n - 1]]++] = n - 1;
        for (size_type i = 0;i < n;++i)
            if (sa[i] > 0 && !type[sa[i] - 1])
                sa[lbuk[s[sa[i] - 1]]++] = sa[i] - 1;
        lbuk[0] = 0;
        for (size_type i = 1;i < m;++i)
            lbuk[i] = sbuk[i - 1];
        for (size_type i = n;i-- > 0;)
            if (sa[i] > 0 && type[sa[i] - 1])
                sa[--sbuk[s[sa[i] - 1]]] = sa[i] - 1;
    }

    template<typename S>
    static void sais(
        const S& s,
        pointer sa,
        bool* type,
        pointer len,
        pointer pos,
        pointer lbuk,
        pointer sbuk,
        size_type n,
        size_type m) {
        type[n - 1] = false;
        for (size_type i = n - 1;i-- > 0;)
            type[i] = s[i] != s[i + 1] ? s[i] < s[i + 1] : type[i + 1];
        size_type n0 = 0;
        for (size_type i = 1;i < n;++i)
            if (!type[i - 1] && type[i])
                pos[n0++] = i;
        std::fill_n(len, n, 0);
        for (size_type p = n - 1, i = n0;i-- > 0;p = pos[i])
            len[pos[i]] = p - pos[i] + 1;
        std::fill_n(sbuk, m, 0);
        for (size_type i = 0;i < n;++i)
            ++sbuk[s[i]];
        for (size_type i = 1;i < m;++i)
            sbuk[i] += sbuk[i - 1];
        induced_sort(s, sa, type, pos, lbuk, sbuk, n, m, n0);
        sbuk[m - 1] = n;
        for (size_type i = 1;i < m;++i)
            sbuk[i - 1] = lbuk[i];
        size_type m0 = -1;
        size_type ppos = -1, plen = 0;
        for (size_type i = 0;i < n;++i) {
            if (len[sa[i]] == 0) continue;
            if (len[sa[i]] != plen || !substring_equal(s, sa[i], ppos, plen)) ++m0;
            plen = len[sa[i]];
            len[sa[i]] = m0;
            ppos = sa[i];
        }
        const pointer s0 = sa;
        const pointer sa0 = sa + n0;
        for (size_type i = 0;i < n0;++i)
            s0[i] = len[pos[i]];
        if (++m0 < n0)
            sais(s0, sa0, type + n, len, pos + n0, lbuk, lbuk + n0, n0, m0);
        else for (size_type i = 0;i < n0;++i)
            sa0[s0[i]] = i;
        for (size_type i = 0;i < n0;++i)
            pos[i + n0] = pos[sa0[i]];
        induced_sort(s, sa, type, pos + n0, lbuk, sbuk, n, m, n0);
    }

public:
    template<typename S>
    SuffixArray(const S& s, size_type n, size_type m)
        : data(std::make_unique<size_type[]>(3 * n)) {
        const auto type = std::make_unique<bool[]>(2 * n);
        const auto lbuk = std::make_unique<size_type[]>(std::max(n, m));
        const auto sbuk = std::make_unique<size_type[]>(m);
        const pointer sa = data.get(), rk = sa + n, ht = rk + n;
        sais(s, sa, type.get(), rk, ht, lbuk.get(), sbuk.get(), n, m);
        for (size_type i = 0;i < n;++i)
            rk[sa[i]] = i;
        for (size_type k = 0, i = 0;i < n;++i) {
            if (rk[i] == 0) continue;
            if (k > 0) --k;
            for (size_type j = sa[rk[i] - 1], l = n - std::max(i, j);k < l;++k)
                if (s[i + k] != s[j + k]) break;
            ht[rk[i]] = k;
        }
        this->sa = sa;
        this->rk = rk;
        this->ht = ht;
    }

    inline size_type suffix(size_type p) const {
        return sa[p];
    }

    inline size_type rank(size_type p) const {
        return rk[p];
    }

    // height start from 1
    inline size_type height(size_type p) const {
        return ht[p];
    }
};
//  -- SA


//  SAIS
const int MAXLEN = 4e5+7;
struct SAIS {
    // 后缀类型
    #define L_TYPE 0
    #define S_TYPE 1

    int st[MAXLEN];
    int rl[MAXLEN],rk[MAXLEN],lcp[MAXLEN];
    int n;

    void init(const std::string &s)
    {
        n = s.size();
        for (int i=1;i<=n;++i) st[i] = s[i-1];
        // st中的字符必须调成正数!!!!!!!!!!!!!!
    }

    // 判断一个字符是否为LMS字符
    inline bool is_lms_char(int *type, int x) {
        return x > 1 && type[x] == S_TYPE && type[x - 1] == L_TYPE;
    }

    // 判断两个LMS子串是否相同
    inline bool equal_substring(int *S, int x, int y, int *type) {
        do {
            if (S[x] != S[y])
                return false;
            x++, y++;
        } while (!is_lms_char(type, x) && !is_lms_char(type, y));

        return S[x] == S[y] && type[x] == type[y];
    }

    // 诱导排序(从*型诱导到L型、从L型诱导到S型)
    // 调用之前应将*型按要求放入SA中
    inline void induced_sort(int *S, int *SA, int *type, int *bucket, int *lbucket,
                            int *sbucket, int n, int SIGMA) {
        for (int i = 1; i <= n; i++)
            if (SA[i] > 1 && type[SA[i] - 1] == L_TYPE)
                SA[lbucket[S[SA[i] - 1]]++] = SA[i] - 1;
        for (int i = 0; i <= SIGMA; i++)  // Reset S-type bucket
            sbucket[i] = bucket[i];
        for (int i = n; i >= 1; i--)
            if (SA[i] > 1 && type[SA[i] - 1] == S_TYPE)
                SA[sbucket[S[SA[i] - 1]]--] = SA[i] - 1;
    }

    // SA-IS主体
    // S是输入字符串，length是字符串的长度, SIGMA是字符集的大小
    int *sais(int *S, int length, int SIGMA) {
        int n = length;
       // assert(S[n]==0);
        int *type = new int[n + 5];  // 后缀类型
        int *position = new int[n + 5];  // 记录LMS子串的起始位置
        int *name = new int[n + 5];  // 记录每个LMS子串的新名称
        int *SA = new int[n + 5];  // SA数组
        int *bucket = new int[SIGMA + 5];  // 每个字符的桶
        int *lbucket = new int[SIGMA + 5];  // 每个字符的L型桶的起始位置
        int *sbucket = new int[SIGMA + 5];  // 每个字符的S型桶的起始位置

        // 初始化每个桶
        memset(bucket, 0, sizeof(int) * (SIGMA + 5));
        for (int i = 1; i <= n; i++)
            bucket[S[i]]++;
        for (int i = 0; i <= SIGMA; i++) {
            if (i==0)
            {
                bucket[i] = bucket[i];
                lbucket[i] = 1;
            }else
            {
                bucket[i] += bucket[i - 1];
                lbucket[i] = bucket[i - 1] + 1;
            }
            sbucket[i] = bucket[i];
        }

        // 确定后缀类型(利用引理2.1)
        type[n] = S_TYPE;
        for (int i = n - 1; i >= 1; i--) {
            if (S[i] < S[i + 1])
                type[i] = S_TYPE;
            else if (S[i] > S[i + 1])
                type[i] = L_TYPE;
            else
                type[i] = type[i + 1];
        }
        // 寻找每个LMS子串
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (is_lms_char(type,i))
                position[++cnt] = i;
        // 对LMS子串进行排序
        std::fill(SA, SA + n + 3, -1);
        for (int i = 1; i <= cnt; i++)
            SA[sbucket[S[position[i]]]--] = position[i];
        induced_sort(S, SA, type, bucket, lbucket, sbucket, n, SIGMA);

        // 为每个LMS子串命名
        std::fill(name, name + n + 3, -1);
        int lastx = -1, namecnt = 1;  // 上一次处理的LMS子串与名称的计数
        bool flag = false;  // 这里顺便记录是否有重复的字符
        for (int i = 2; i <= n; i++) {
            int x = SA[i];

            if (is_lms_char(type, x)) {
                if (lastx >= 0 && !equal_substring(S, x, lastx, type))
                    namecnt++;
                // 因为只有相同的LMS子串才会有同样的名称
                if (lastx >= 0 && namecnt == name[lastx])
                    flag = true;

                name[x] = namecnt;
                lastx = x;
            }
        }  // for
        name[n] = 0;

        // 生成S1
        int *S1 = new int[cnt+5];
        int pos = 0;
        for (int i = 1; i <= n; i++)
            if (name[i] >= 0)
                S1[++pos] = name[i];
        int *SA1;
        if (!flag) {
            // 直接计算SA1
            SA1 = new int[cnt + 5];

            for (int i = 1; i <= cnt; i++)
                SA1[S1[i]+1] = i;
        } else
            SA1 = sais(S1, cnt, namecnt);  // 递归计算SA1

        // 从SA1诱导到SA
        for (int i = 0; i <= SIGMA; i++) {
            if (i==0)
                lbucket[i] = 1;
            else
                lbucket[i] = bucket[i - 1] + 1;
            sbucket[i] = bucket[i];
        }
        std::fill(SA, SA + n + 3, -1);
        for (int i = cnt; i >= 1; i--)  // 这里是逆序扫描SA1，因为SA中S型桶是倒序的
            SA[sbucket[S[position[SA1[i]]]]--] = position[SA1[i]];
        induced_sort(S, SA, type, bucket, lbucket, sbucket, n, SIGMA);

        delete[] S1;
        delete[] SA1;
        delete[] bucket;
        delete[] lbucket;
        delete[] sbucket;
        delete[] position;
        delete[] type;
        delete[] name;
        // 后缀数组计算完毕
        return SA;
    }

    void build()
    {
        st[0]=st[n+2]=-1;
        st[n+1]=0;
        int SIGMA = 0;
        for (int i=1;i<=n;++i) SIGMA = std::max(SIGMA,st[i]);
        int * sa = sais(st,n+1,SIGMA);
        for (int i=2;i<=n+1;++i) rk[sa[i]]=i-1;
        delete[] sa;
        for (int i=1;i<=n;++i) rl[rk[i]]=i;
        for (int i=1,len=0;i<=n;++i)
        {
            if (len) --len;
            while (i+len<=n && rl[rk[i]-1]+len<=n && st[i+len]==st[rl[rk[i]-1]+len]) ++len;
            lcp[rk[i]]=len;
        }
    }

    #undef L_TYPE
    #undef R_TYPE
} ; //  SA

