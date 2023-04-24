/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2022-03-23 18:53:11
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2023-04-02 23:57:39
 * @FilePath: \apricitye:\桌面\ACM\PX-从零开始的ACM模板\Template\数据结构\DSU.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */


/*   并查集 DSU

并查集是一种树形的数据结构，通过树结构将元素进行集合**合并**即**查询**，能够维护传递性的关系，通常支持:

查询(Find):查询元素所属集合
合并(Merge/Union):将两个集合合并

Here form DSU1 to DSU7
using namespace

*/

#include <iostream>
#include <numeric>  //  iota
#include <vector>
#include <queue>
#include <array>
#define ll long long
#define int long long
using namespace std;

struct DSU {
	std::vector<int> f, siz;
	std::vector<std::priority_queue<std::array<int, 2>>> Q;
	DSU(int n) : f(n), siz(n, 1), Q(n, priority_queue<array<int, 2>>()) {
		std::iota(f.begin(), f.end(), 0);
	}
	int leader(int x) {
		while (x != f[x]) x = f[x] = f[f[x]];
		return x;
	}
	bool same(int x, int y) {
		return leader(x) == leader(y);
	}
	bool merge(int x, int y) {
		x = leader(x);
		y = leader(y);
		if (x == y) return false;
		if (Q[x].size() < Q[y].size()) {
			swap(x, y);
		}
		while (!Q[y].empty()) {
			Q[x].push(Q[y].top());
			Q[y].pop();
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}
	int size(int x) {
		return siz[leader(x)];
	}
};

namespace DSU1{ //  namespace dsu1
// 朴素并查集+路径压缩
struct dsu {   //   DSU
    vector<int> f;
    dsu(int n) :f(n) { iota(f.begin(), f.end(), 0); }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }   //  路径压缩
    bool same(int x,int y) { return find(x)==find(y);}
    void merge(int x, int y) {  //  大并小
        x = find(x); y = find(y);
        if (x > y)swap(x, y);
        f[y] = x;
    }
};
};  //  namespace dsu1
using namespace DSU1;

namespace DSU2{ //  namespace dsu2
//  路径压缩+启发式合并
struct dsu {   //   DSU
    vector<int> f, size;
    dsu(int n) :f(n), size(n,1) { iota(f.begin(), f.end(), 0); }    //  路径压缩
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    bool same(int x,int y) { return find(x)==find(y);}
    void merge(int x, int y) {  //  启发式合并
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (size[fx] > size[fy]) swap(fx,fy);   //  启发式合并
        f[fx] = fy;
        size[fy] += size[fx];                   //  启发式合并
    }
};
};  //  namespace dsu2
using namespace DSU2;


namespace DSU3{ //  namespace dsu3
// 维护大小+祖先距离
struct dsu {   //   DSU
    vector<int> f, size, d;     //  实际大小应是size[f[x]]
    dsu(int n) :f(n), size(n,1), d(n,0) {  iota(f.begin(), f.end(), 0); }
    int find(int x) {   //  路径压缩
        if(f[x]==x) return x;
        int fa = find(f[x]);
        d[x] += d[f[x]];
        return f[x] = fa;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) {  //  大并小
        x = find(x); y = find(y);
        if(x==y) return;
        if (x > y)swap(x, y);
        size[x] += size[y];
        d[y] = 1;   //  other
        f[y] = x;
    }
};
};  //  namespace dsu3
using namespace DSU3;

namespace DSU4{ //  namespace dsu4
// 带权并查集
/*  带权并查集 例子 权==x-f[x] 通常若权值为M个集合，应取模M，即维护模M意义下的运算群 */
struct dsu {   //   DSU
    vector<int> f, size;
    vector<int> val;    //  权x-f[x]
    dsu(int n) :f(n), size(n,1), val(n,0) {  iota(f.begin(), f.end(), 0); }
    int find(int x) {   //  路径压缩
        if(f[x]==x) return x;
        int fa = find(f[x]);    //  注意顺序
        val[x] += val[f[x]];    //  更新权 val[x]%=M
        return f[x] = fa;       //  路径压缩
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y,int res) {  //  启发式合并 边权x<->y==res
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (size[fx] > size[fy]) swap(fx,fy);   //  启发式合并
        f[fx] = fy;
        size[fy] += size[fx];                   //  启发式合并
        val[fx] = val[y] + res - val[x];        //  更新权 val[fy]%=M
    }
};
};  //  namespace dsu4
using namespace DSU4;


namespace DSU5{ //  namespace dsu5
// 带权并查集求有向图最小环
/*  带权并查集求有向图最小环
    例子:信息传递
    维护带权并查集，边权x-f[x]默认1，每次加边x->y先判是否在一个集合，不在则合并，在则说明成环，环长即val[y]+1
*/
#define inf 0x3f3f3f3f
struct dsu {   //   DSU
    vector<int> f/*, size*/;
    vector<int> val;    //  权x-f[x]
    dsu(int n) :f(n)/*, size(n,1)*/, val(n,0) {  iota(f.begin(), f.end(), 0); }
    int find(int x) {   //  路径压缩
        if(f[x]==x) return x;
        int fa = find(f[x]);    //  注意顺序
        val[x] += val[f[x]];    //  更新权
        return f[x] = fa;       //  路径压缩
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y,int res) {  //  合并 x->y
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        // if (size[fx] > size[fy]) swap(fx,fy);    //  启发式合并
        f[fx] = fy;
        // size[fy] += size[fx];                    //  启发式合并
        val[fx] = val[y] + res - val[x];    //  更新权
    }
};
void Zhuangpx()
{
    int n;cin>>n;
    dsu px(n+1);
    int ans=inf;
    for(int i=1;i<=n;i++){  //  边i->t
        int t;cin>>t;
        if(!px.same(i,t))px.merge(i,t,1);  //  加边i->t
        else ans=min(ans,px.val[t]+1);  //  成环 更新最小ans
    }
    cout<<ans<<'\n';
}
};  //  namespace dsu5
using namespace DSU5;


namespace DSU6{ //  namespace dsu6
// 种类并查集/并查集扩展域
/*  种类并查集/并查集扩展域 通过多个并查集维护多个集合的关系，同时也是循环对称关系
    (例子食物链) i,j同类或i吃j或j吃i 开三倍大小[1,3*n]  <i,j>:i,j同类;<i,j+n>:i吃j;<i,j+2*n>:j吃i
*/
struct dsu {   //   DSU
    vector<int> f, size;
    dsu(int n) :f(n), size(n,1) { iota(f.begin(), f.end(), 0); }    //  路径压缩
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    bool same(int x,int y) { return find(x)==find(y);}
    void merge(int x, int y) {  //  启发式合并
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (size[fx] > size[fy]) swap(fx,fy);   // 启发式合并
        f[fx] = fy;
        size[fy] += size[fx];                   // 启发式合并
    }
};
void Zhuangpx()
{
    int n,k;cin>>n>>k;
    dsu px(3*n+1);
    int ans=0;
    while(k--){ //  有序
        int op,x,y;cin>>op>>x>>y;
        if(x>n||y>n) { ans++;continue; }    //  超过n
        if(op==1) { // 1 x y same(x,y)
            if(px.same(x,y+n)||px.same(x,y+2*n))ans++;  //  x->y / y->x
            else px.merge(x,y),px.merge(x+n,y+n),px.merge(x+2*n,y+2*n); // x<->y
        }
        if(op==2) { // 2 x y x->y
            if(px.same(x,y+2*n)||px.same(x,y))ans++;  //  y->x / x<->y
            else px.merge(x,y+n),px.merge(x+n,y+2*n),px.merge(x+2*n,y); //  x->y
        }
    }
    cout<<ans<<'\n';    //  error time
}
};  //  namespace dsu6
using namespace DSU6;

namespace DSU7{ //  namespace dsu7
// 并查集元素删除
/*  并查集元素删除
    朴素并查集初始化f[x]=x，先进行f[i]=i+n，f[j]=j，其中i为有效点，j为虚拟点
    例子  op=1,x,y -> merge(x->y)   op=2,x,y -> move(x->y)  op=3,x -> size[(x)] + sum[(x)]
*/
struct dsu {   //   DSU
    vector<int> f, size, sum;    //  f[0-n-1]->[n-2*n]  f[n-2*n]->[n-2*n] (visual)
    dsu(int n) :f(2*n), size(2*n,1), sum(2*n,0) {
        for (int i = 0; i < n; i++) {
            f[i] = f[i + n] = i + n;
            size[i + n] = 1;        //  visual size
            sum[i + n] = i;         //  visual sum
        }
    }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    bool same(int x,int y) { return find(x)==find(y);}
    void merge(int x, int y) {  //  合并 merge(x->y)
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        // if (size[fx] > size[fy]) swap(fx,fy);   //  启发式合并
        f[fx] = fy;
        size[fy] += size[fx];
        sum[fy] += sum[fy];
        size[fx] = sum[fx] = 0;
    }
    void del(int x) {    //  删除 del(x)
        int fx = f[x];
        size[fx]--; sum[fx]-=x;
        f[x]=0;             //  o 或者 2*n+1 范围点外即可
    }
    void move(int x, int y) {   //  move (x->y)
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        size[fy]++; sum[fy]+=x;
        size[fx]--; sum[fx]-=x;
        f[x] = fy;
    }
};
void Zhuangpx()
{
    int n;cin>>n;
    dsu px(n+1);
    int m;cin>>m;
    int x,y,op;
    while(m--){
        cin>>op;
        if(op==1){      //  merge(x->y)
            cin>>x>>y;
            if(px.same(x,y))continue;
            else px.merge(x,y);
        }
        else if(op==2){ //  move(x->y)
            cin>>x>>y;
            if(px.same(x,y))continue;
            else px.move(x,y);
        }
        else {          //  answer size[(x)] + sum[(x)]
            cin>>x;
            int fx=px.f[x];
            cout<<px.size[fx]<<' '<<px.sum[fx]<<'\n';
        }
    }
}
};  //  namespace dsu7
using namespace DSU7;
