/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-11-26 21:15:13
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2022-11-26 21:16:23
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数学\matrix.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
struct Mat{
    static const int M = 4;
    int v[M][M];
    Mat() { memset(v ,0 ,sizeof(v)); }
    Mat(){
        //..
    }
    void eye() { for(int i = 0; i < M; i++) for(int j = 0; j < M; j++) v[i][j] = (i == j); }
    int * operator [] (int x) { return v[x]; }
    const int *operator [] (int x) const { return v[x]; }
    Mat operator * (const Mat& B) {
        const Mat &A = *this;
        Mat ret;
        for(int k = 0; k < M; k++){
            for(int i = 0; i < M; i++)
                for(int j = 0; j < M; j++){
                    ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
        return ret;
    }
    Mat operator + (const Mat& B) {
        const Mat &A = *this;
        Mat ret;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < M; j++)
                ret[i][j] = (A[i][j] + B[i][j]) % mod;
        return ret;
    }
    Mat pow(int n) const {
        Mat A = *this, ret; ret.eye();
        for(; n; n >>= 1, A = A * A) if(n & 1) ret = ret * A;
        return ret;
    }
};