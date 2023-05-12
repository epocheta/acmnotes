# 区间和

[区间和](https://www.acwing.com/problem/content/804/) 是一道经典的离散化题， 给的数轴是无限长的，按照朴素思想，我们可以开一个桶数组，用数组的下标去代表元素，来进行增加和查询区间和的操作（查询操作用到了前缀和的思想）。但是因为给的元素值可能无限大，没有足够的空间去存储桶数组（设想一下，只给了两个元素， 一个是1， 一个是 1000000000， 显然，开一个长度为 1000000001 的数组是不太现实的）对于这类情况我们就可以采用离散化的方法。

因为我们要求前缀和， 所以存储值的数据结构依然需要用到数组（也许 map 也可以求前缀和？但是我不会 hh）

```cpp
// 读入 add
for (int i = 0, dis, x; i < n; i++) {
    std::cin >> dis >> x;
    // 缓存 add 操作，另外用 alls 存储数轴的值
    add[i] = {dis, x}, alls[i] = dis; 
}
// 读入 query
for (int i = 0, l, r; i < m; i++) {
    std::cin >> l >> r; 
    // 查询的时候需要访问 l， r 所以也许要用 alls 去存储，进行离散化
    query[i] = {l, r}, alls.push_back(l), alls.push_back(r); 
}
```

```cpp
// 去重
std::sort(alls.begin(), alls.end());
alls.erase(std::unique(alls.begin(), alls.end()), alls.end());
```

运行完上面的代码后，可能是无穷大的值就映射到了一个唯一的索引值， 而这个索引值不大于 alls 数组的长度。

但是我们如何获得这个元素的映射的索引值呢？一个方法是二分查找， 使用 c++ 提供的 lower\_bound() 来查找元素的映射值：

```cpp
auto find = [&](int x) {
    // 结尾加一是因为要进行前缀和操作
    return std::lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;         
};
```

前缀和以及查询操作基本和一般算法的形式上没有什么区别， 唯一要注意的一点是， 所有的点都有一个唯一的索引值，在进行上面两项操作的时候我们都是处理它们的索引值而非它们本身。
