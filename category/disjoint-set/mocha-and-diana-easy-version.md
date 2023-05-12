# Mocha and Diana (Easy Version)

#### Problem Link: [Mocha and Diana (Easy Version)](https://vjudge.net/problem/CodeForces-1559D1)

### &#x20;Problem Description

A 和 B 都有 N 个节点，分别对两个人进行加边操作，加完边后每个人得到了一个森林（无向无环图（树）或节点的集合），求两者可同时最多加相同的几条边，使得两者拥有的仍然是森林。

### Problem Thought

设森林中的每一个节点或树为森林的一个元， 显然，只有边加在不同的元上才可以维持森林的形态，我们可以用并查集来判断两个节点是否是在同一个元里，此题数据范围较小，我们可以直接暴力枚举每一种情况。再判断两次并查集，使得同时满足 A 和 B 都维持森林的形态即可。

### Implementation

```cpp
std::vector<int> fa(1000), fb(1000);

int find(int x, auto & f) {
    if (f[x] != x) f[x] = find(f[x], f);
    return f[x];
}

void sol() {
    int n, m1, m2, cnt = 0;
    std::vector<std::pair<int, int>> ans;
    
    std::cin >> n >> m1 >> m2;

    for (int i = 1; i <= n; i++) fa[i] = fb[i] = i;

    for (int i = 0, u, v; i < m1; i++) {
        std::cin >> u >> v;
        fa[find(u, fa)] = find(v, fa);
    }

    for (int i = 0, u, v; i < m2; i++) {
        std::cin >> u >> v;
        fb[find(u, fb)] = find(v, fb);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int ia = find(i, fa), ib = find(i, fb);
            int ja = find(j, fa), jb = find(j, fb);
            if (ia != ja && ib != jb) {
                cnt += 1;
                ans.push_back({i, j});
                fa[ia] = ja, fb[ib] = jb;
            }
        }
    }
    std::cout << cnt << '\n';
    for (auto [u, v] : ans) std::cout << u << ' ' << v << '\n';
}
```
