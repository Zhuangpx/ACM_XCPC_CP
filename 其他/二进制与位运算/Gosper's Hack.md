# Gosper's Hack

一种生成n元集合的k元子集的算法，挑战程序设计竞赛中关于集合的地方有类似的算法。

```c++
void GospersHack(int k, int n)
{
    int cur = (1 << k) - 1;
    int limit = (1 << n);
    while (cur < limit)
    {
        // do something
        int lb = cur & -cur;
        int r = cur + lb;
        cur = ((r ^ cur) >> __builtin_ctz(lb) + 2) | r;
        // 或：cur = (((r ^ cur) >> 2) / lb) | r;
    }
}
```

或者可见知乎：https://zhuanlan.zhihu.com/p/360512296