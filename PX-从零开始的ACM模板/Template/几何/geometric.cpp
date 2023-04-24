
#include<bits/stdc++.h>

namespace Geometric {    //  namespace Geometric
    using point_t = int;  //全局数据类型，可修改为 long long 等

    constexpr point_t eps = 0;
    /*constexpr */long double PI = acosl(-1);

    // 点与向量
    template<typename T> struct point {
        T x, y;

        bool operator == (const point & a) const { return abs(x - a.x) <= eps && abs(y - a.y) <= eps; }
        bool operator < (const point & a) const { if(abs(x - a.x) > eps) return x < a.x - eps; return y < a.y - eps; }
        bool operator > (const point & a) const { return !((*this) < a || (*this) == a); }
        point operator + (const point & a) const { return {x + a.x, y + a.y}; }
        point operator - (const point & a) const { return {x - a.x, y - a.y}; }
        point operator - () const { return {-x, -y}; }
        point operator * (const T k) const { return {x * k, y * k}; }
        point operator / (const T k) const { return {x / k, y / k}; }
        T operator * (const point & a) const { return x * a.x + y * a.y; }
        T operator ^ (const point & a) const { return x * a.y - y * a.x; }
        int toleft (const point & a) const { const auto t = (*this) ^ a; return (t > eps) - (t < -eps); } // a 向量在该向量的左半平面 / 上 / 右半平面
        T len2 () const { return x * x + y * y; }
        T dis2 (const point & a) const { return ((*this) - a).len2(); }

        // 涉及浮点数
        long double len () const { return sqrtl(len2()); }
        long double dis (const point & a) const { return sqrtl(dis2(a)); }
        long double ang (const point & a) const { return acosl(min(1.0l, max(-1.0l, ((*this) * a) / ((len() * a.len()))))); }
        long double toang (const point & a) const { const auto t = ang(a); return (*this ^ a) > 0 ? t : 2 * PI - t; }
        point rot () const { return {-y, x}; }
        point rot (const long double rad) const { return {x * cosl(rad) - y * sinl(rad), x * sinl(rad) + y * cosl(rad)}; }
        point rot (const long double cosr, const long double sinr) const { return {x * cosr - y * sinr, x * sinr + y * cosr}; }
    };

    using Point = point<point_t>;


    // 极角排序
    struct argcmp {
        bool operator () (const Point & a, const Point & b) const {
            const auto quad = [] (const Point & a) {
                if(a.y < -eps) return 1;
                if(a.y > eps) return 4;
                if(a.x < -eps) return 5;
                if(a.x > eps) return 3;
                return 2;
            };
            const int qa = quad(a), qb = quad(b);
            if(qa != qb) return qa < qb;
            const auto t = a ^ b;
            // if(abs(t) <= eps) return a * a < b * b - eps;  // 不同长度的向量需要分开
            return t > eps;
        }
    };

    // 直线
    template<typename T> struct line {
        point<T> p, v;

        bool operator == (const line & a) const { return v.toleft(a.v) == 0 && v.toleft(p - a.p) == 0; }
        int toleft (const point<T> & a) const { return v.toleft(a - p); } // 点 a 在该直线的左半平面 / 上 / 右半平面

        // 涉及浮点数
        long double dis (const point<T> & a) const { return abs(v ^ (a - p)) / v.len(); }
        point<T> inter (const line & a) const { return p + v * ( (a.v ^ (p - a.p)) / (v ^ a.v) ); }
        long double inter_dis (const line & a) const { return v.len() * (a.v ^ (p - a.p)) / (v ^ a.v); }
        point<T> proj (const point<T> & a) const { return p + v * ( (v * (a - p)) / (v * v) ); }
        long double proj_dis (const point<T> & a) const { return v * (a - p) / v.len(); }
    };

    using Line = line<point_t>;


    // 线段
    template<typename T> struct segment {
        point<T> a, b;

        bool operator < (const segment & s) const { return make_pair(a, b) < make_pair(s.a, s.b) ; }

        // 判定性函数建议在整数域使用

        // 判断点是否在线段上
        // -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
        int is_on (const point<T> & p) const {
            if(p == a || p == b) return -1;
            return (p - a).toleft(p - b) == 0 && (p - a) * (p - b) < -eps;
        }

        // 判断线段直线是否相交
        // -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
        int is_inter (const line<T> & l) const {
            if(l.toleft(a) == 0 || l.toleft(b) == 0) return -1;
            return l.toleft(a) != l.toleft(b);
        }

        // 判断两线段是否相交
        // -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
        int is_inter (const segment & s) const {
            if(is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b)) return -1;
            const line<T> l = {a, b - a}, ls = {s.a, s.b - s.a};
            return l.toleft(s.a) * l.toleft(s.b) == -1 && ls.toleft(a) * ls.toleft(b) == -1;
        }

        // 点到线段距离
        long double dis (const point<T> & p) const {
            if((b - a) * (p - a) < -eps || (a - b) * (p - b) < -eps) return min(p.dis(a), p.dis(b));
            const line<T> l = {a, b - a};
            return l.dis(p);
        }

        // 两线段间距离
        long double dis (const segment & s) const {
            if(is_inter(s)) return 0;
            return min({dis(s.a), dis(s.b), s.dis(a), s.dis(b)});
        }
    };

    using Segment = segment<point_t>;

    // 射线
    template<typename T> struct ray {
        point<T> p, v;

        // 判定性函数建议在整数域使用

        // 判断点是否在射线上
        // -1 点在射线端点 | 0 点不在射线上 | 1 点严格在射线上
        int is_on (const point<T> & a) const {
            if(p == a) return -1;
            return v.toleft(a - p) == 0 && v * (a - p) > eps;
        }

        // 判断射线直线是否相交
        // -1 直线经过射线端点 | 0 射线和直线不相交 | 1 射线和直线严格相交
        int is_inter (const line<T> & l) const {
            if(l.toleft(p) == 0) return -1;
            return l.v.toleft(p - l.p) * l.v.toleft(v) == -1;
        }

        // 判断射线线段是否相交
        // -1 在线段端点或射线端点处相交 | 0 射线和线段不相交 | 1 射线和线段严格相交
        int is_inter (const segment<T> & s) const {
            if(is_on(s.a) || is_on(s.b) || s.is_on(p)) return -1;
            const point<T> sv = s.b - s.a;
            return v.toleft(s.a - p) * v.toleft(s.b - p) == -1 && sv.toleft(p - s.a) * sv.toleft(v) == -1;
        }

        // 判断两射线是否相交
        // -1 在某一射线端点处相交 | 0 两射线不相交 | 1 两射线严格相交
        int is_inter (const ray & r) const {
            if(is_on(r.p) || r.is_on(p)) return -1;
            const line<T> l = {p, v}, lr = {r.p, r.v};
            return is_inter(lr) && r.is_inter(l);
        }

        // 点到射线距离
        long double dis (const point<T> & a) const {
            if(v * (a - p) < -eps) return a.dis(p);
            const line<T> l = {p, v};
            return l.dis(a);
        }

        // 线段到射线距离
        long double dis (const segment<T> & s) const {
            if(is_inter(s)) return 0;
            return min({dis(s.a), dis(s.b), s.dis(p)});
        }

        // 射线到射线距离
        long double dis (const ray & r) const {
            if(is_inter(r)) return 0;
            return min(dis(r.p), r.dis(p));
        }

        // 射线从点 p 沿着方向 v 到达 直线/线段/射线 的距离
        // 1. 直线
        long double dis_from_p_in_v (const line<T> & l) const {
            const int t = is_inter(l);
            if(t <= 0) return t ? 0 : -1;
            return line<T>{p, v}.inter_dis(l);
        }

        // 2. 线段
        long double dis_from_p_in_v (const segment<T> & s) const {
            const int t = is_inter(s);
            if(t == 0) return -1;
            if(t == -1) {
                if(s.is_on(p)) return 0;
                else if(is_on(s.a) && is_on(s.b)) return min(p.dis(s.a), p.dis(s.b));
            }
            return line<T>{p, v}.inter_dis(line<T>{s.a, s.b - s.a});
        }

        // 3. 射线
        long double dis_from_p_in_v (const ray & r) const {
            const int t = is_inter(r);
            if(t == 0) return -1;
            if(t == -1) return r.is_on(p) ? 0 : p.dis(r.p);
            return line<T>{p, v}.inter_dis(line<T>{r.p, r.v});
        }
    };

    using Ray = ray<point_t>;

    Point input_point(){
        Point a;
        std::cin >> a.x >> a.y;
        return a;
    }

}   //  ==== namespace Geometric

