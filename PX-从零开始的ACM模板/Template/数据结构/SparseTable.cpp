/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-11-23 10:38:59
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-11-23 10:39:14
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数据结构\SparseTable.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include <functional>

template <typename T, class F = std::function<T(const T&, const T&)>>
class SparseTable {
  public:
    int n;
    std::vector<std::vector<T>> mat;
    F func;
    SparseTable(const std::vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for(int j=1; j<max_log; j++) {
            mat[j].resize(n-(1<<j)+1);
            for(int i=0; i<=n-(1<<j); i++) {
                mat[j][i] = func(mat[j-1][i], mat[j-1][i+(1<<(j-1))]);
            }
        }
    }
    T get(int from, int to) const {
        assert(0<=from && from<=to && to<=n-1);
        int lg = 32 - __builtin_clz(to-from+1) - 1;
        return func(mat[lg][from], mat[lg][to-(1<<lg)+1]);
    }
};
