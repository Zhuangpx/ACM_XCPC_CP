# Treap

## 简介

Treap(树堆)是一种弱平衡的平衡树，treap即tree+heap，它有一个随机附加域，并且满足堆的性质。我们知道普通的平衡树是有可能退化为链表的，如果加上一个随机附加域让树满足二叉搜索树的条件下再满足二叉堆性质，那么其插入就是随机的(随机大法好!)，只要足够随机就能实现平衡。简而言之就是平衡树的基础上融合了满足优先级的二叉堆。

Treap有旋转式和无旋式，后者也称为fhqTreap(发明者范浩强)。
fhqTreap有平衡树双子星之一一说，非常实用且简单，并且还能处理某些区间问题。而旋转Treap在普通平衡树里是常数最小的。
