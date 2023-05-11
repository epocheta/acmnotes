# graph theory

### storage

邻接表存图

```cpp
int h[maxn], ne[maxn], e[maxn], idx;

memset(h, -1, sizeof h);
void add(int a, int b) { // 添加一条 a -> b 的有向边
    e[idx] = x, ne[idx] = h[a], h[a] = idx++;
}

```

```cpp
// dfs
bool st[maxn];
void dfs() {
    // 忘了
}
```
