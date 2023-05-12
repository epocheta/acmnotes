# Disjoint Set

并查集(disjoint set)是一种快速在不同集合中查询和添加和合并的数据结构。

```
int find (int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}
```

```
// 路径压缩的查询操作
int find(int x) {
    // 如果查询元素的父节点不是它本身, 则递归地查询它的父节点以至于找到祖宗节点
    // 并将它的父节点指向祖宗节点
    if (fa[x] != x) fa[x] = find(fa[x]);
    // 当查询元素的父节点等于元素本身, 即这个元素就是这个集合的祖宗节点, 就反回它
    return fa[x];
}
```
