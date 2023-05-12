# Food chians

#### Problem Link: [https://vjudge.net/problem/POJ-1182](https://vjudge.net/problem/POJ-1182)

### &#x20;Problem Description

有一条食物链: A -> B -> C -> A，有 n 个动物，k 个判断，判断的格式如下：

* `1 x y` 代表判断 x 与 y 是同类
* `2 x y` 代表判断 x 吃 y 求出错误的判断次数

### Problem Thought

食物链上只有三种动物， 而询问是针对每两个动物的，如果两个动物在一条链上， 那么我们就可以通过判断两个动物的距离来判断两个动物的关系（当两个动物距离是1时， 那么在后面的那个就吃前一个， 2 时， 则无关， 3 时则是同类，4 时又回到了距离是 1 的情况，所以对距离模 3 然后判断即可确定关系）如果不在一条链上，那这句话就是对的（因为对未定义的判断就相当于声明）我们设法让两个动物连在一条链上。

在每一次询问时，我们先要判断两个动物是否在一条链上，接着再对距离做文章，这类抽象可以用并查集来解决，对于距离，我们需要维护一个 dist 数组来存储每个元素到祖宗节点的距离即可，两者的相对距离可以由绝对距离转化而来。

### Implementation

如何维护 dist 数组呢， 在 find() 函数递归过程中，被 find 元素会递归到它的祖宗节点，我们可以利用这一过程来更新 dist，因为采用了路径压缩， 所以只有第一次递归到祖宗节点的时候更新的路径是有效的，所以 `dist[x] = dist[f[x]] + 1` 的递推方程并不适用于此。 另外，考虑 dist 数组只会在 “声明” 的时候发生改变，合并集合后，一个路径压缩的集合就多了一个二级节点，当压缩此节点的路径的时候，他的 dist 应该等于他到他父节点的距离 + 他父节点到祖宗节点的距离，所以可以写出如下 find 函数。

```cpp
int find(int x) {
    if (f[x] != x) {
        int u = find(f[x]);
        dist[x] += dist[f[x]];
	f[x] = u;
    }
    return f[x];
}
```

```cpp
void sol() {
    int n, k, op, a, b, res = 0;
    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) f[i] = i;

    while (k--) {
        std::cin >> op >> a >> b;
        int ida = find(a), idb = find(b);
        if (a > n || b > n) res += 1;
        else if (op == 1) {
            if (ida == idb && ((dist[a] + 3) % 3 != (dist[b] + 3) % 3)) 
	            res += 1; 
            if (ida != idb) {
                f[ida] = idb;
                dist[ida] = dist[b] - dist[a];
            }
        } else {
            if (ida == idb && (dist[a] % 3 + 3) % 3 != ((dist[b] + 1) % 3 + 3) % 3) 
                res += 1;
            if (ida != idb) {
                f[ida] = idb;
                dist[ida] = dist[b] + 1 - dist[a];
            }
        }
    }
    std::cout << res << '\n';
}
```
