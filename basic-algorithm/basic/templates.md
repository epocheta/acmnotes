---
layout: landing
---

# Templates

### 单调队列

```
int queue[maxn], tail = -1, head = 0;
int a[n];
for (int i = 0; i < n; i++) {
    while (tail >= head && queue[tail] > a[i]) tail -= 1;
    queue[++tail] = a[i];
    std::cout << queue[head] << ' ';
}
// 维护最大的：同理
```

### 并查集

```
struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) {
            return false;
        }
        siz[fb] += siz[fa];
        f[fa] = fb;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};
```

### 树状数组

```
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};
```

### 素数筛

```
const int maxn = 1e5 + 10;
int primes[maxn], cnt;
bool st[maxn];
```

```
// 埃氏筛法
void sieve_prime_era (int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (int j = i; j <= n; j += i) st[j] = true;
        }
    }
}
```

```
// 线性筛法
void sieve_prime_liner (int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
```

```
// trial division determin prime number
bool is_prime (int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0) return false;
    return true;
}
```

### 前缀和和差分

```
// 一维 
int prefixsum[n];
prefixsum[0] = a[0];
for (int i = 1; i < n; i++) prefixsum[i] = a[i] + prefixsum[i - 1];

// 二维
for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
        sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
}

// 查询
int query_1d(int l, int r) {
    return sum[r] - sun[l - 1];
}

int query_2d(int x1, int y1, int x2, int y2) {
    return sum[x1][y1] - sum[x1][y2 - 1] - sum[x2 - 1][y1] + sum[x2 - 1][y2 - 1];
}
```

```
// 差分
// 1d
dif[0] = a[0];
for (int i = 1; i < n ; i++)
    dif[i] = a[i] - a[i - 1];
    
// 2d
for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
        dif[i][j] = a[i][j] + a[i - 1][j - 1] - a[i - 1][j] - a[i][j - 1];

// 修改
void modi_1d(int l, int r, int k) {
    dif[l] = k, dif[r + 1] = -1;
}

void modi_2d(int x1, int y1, int x2, int y2, int k) {
    dif[x2][y2] += k, dif[x1 + 1][y2] -= k;
    dif[x2][y1 + 1] -= k, dif[x1 + 1][y1 + 1] += k;
}
```

### 离散化

```
std::vector<int> alls;

std::ranges::sort(alls);
alls.erase(std::unique(alls.begin(), alls.end()), alls.end());
```

### 快速幂

```
constexpr int MAXN = 2e5 + 10, MODP = 1000000007;
constexpr i64 ksm (i64 a, i64 b, i64 p = MODP) {
    i64 res = 1;
    for (; b; b >>= 1, a = a * a % p) 
        if (b & 1) res = res * a % p;
    return res;
}
```

### 图

**邻接表 Vector 存图**

```
struct Graph {
    int N, M;
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<int> dis;

    Graph() {}
    Graph(int n) {
        init(n);
    }

    void init(int n) {
        N = n;
        adj.resize(n);
        dis.resize(n, -1);
    }

    void add(int u, int v, int d) {
        adj[u].emplace_back(v, d);
        M++;
    }

    void dijkstra_naive() {
        std::vector<int> dis_temp(N, 1e9), vis_temp(N, 1);
        dis_temp[0] = 0;

        for (int _ = 0; _ < N; _++) {
            auto min_dis = inf, u = 0;
            for (int i = 0; i < N; i++) {
                if (vis_temp[i] && dis_temp[i] < min_dis) {
                    u = i, min_dis = dis_temp[i];
                }
            }
            vis_temp[u] = 0;

            for (auto [v, w] : adj[u]) {
                dis_temp[v] = std::min(dis_temp[v], dis_temp[u] + w);
            }
        }
        dis = dis_temp;
    }

    void dijkstra() {
        std::vector<int> dis_temp(N, -1);
        std::priority_queue<std::pair<int, int>> h;
        h.emplace(0, 0);

        while (!h.empty()) {
            auto [u, d] = h.top();
            h.pop();

            if (dis_temp[u] != -1) continue;

            dis_temp[u] = -d;
            for (auto [v, w] : adj[u]) {
                h.emplace(d - w, v);
            }
        }
        dis = dis_temp;
    }

    void dfs(int u) {
        std::vector<int> vis(N, 1);

        auto recursive = [&](auto self, auto cur) -> void {
            vis[cur] = 0;

            for (auto [v, w] : adj[cur]) {
                if (vis[v] == 0) continue;
                self(self, v); 
            }
        };

        recursive(recursive, u);
    }

    void bfs(int origin) {
        std::vector<int> vis(N, 1);
        std::queue<int> q;
        q.emplace(origin);

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            vis[u] = 0;
            
            for (auto [v, _] : adj[u]) {
                if (vis[v] == 0) continue;
                q.emplace(v);
            }
        }
    }
};
```

### 线段树

```
template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};
```
