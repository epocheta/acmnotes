# Acm Templates

## basic algorithms

### high precision

use python \~\~\~

### binary search

```
// eg: vector<int> a(n);
int l = -1, r = n;
while (l + 1 != r) {
    int mid = l + r >> 1;
    if (check(mid)) l = mid;
    else r = mid;
}
return r or l;
```

### prefix and dif

```cpp
// eg: int a[n]; or int a[n][m];
// 1d prefix
int prefixsum[n];
prefixsum[0] = a[0];
for (int i = 1; i < n; i++) prefixsum[i] = a[i] + prefixsum[i - 1];
// 2d
for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
        sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
}

// query:
int query_1d(int l, int r) {
    return sum[r] - sun[l - 1];
}

int query_2d(int x1, int y1, int x2, int y2) {
    return sum[x1][y1] - sum[x1][y2 - 1] - sum[x2 - 1][y1] + sum[x2 - 1][y2 - 1];
}
```

```cpp
// dif eg: int a[n]; or int a[n][m];
// 1d
dif[0] = a[0];
for (int i = 1; i < n ; i++)
    dif[i] = a[i] - a[i - 1];
// 2d
for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
        dif[i][j] = a[i][j] + a[i - 1][j - 1] - a[i - 1][j] - a[i][j - 1];

// modi
void modi_1d(int l, int r, int k) {
    dif[l] = k, dif[r + 1] = -1;
}

void modi_2d(int x1, int y1, int x2, int y2, int k) {
    dif[x2][y2] += k, dif[x1 + 1][y2] -= k, dif[x2][y1 + 1] -= k, dif[x1 + 1][y1 + 1] += k;
}
```

### double pointer

```cpp
for (int i = 0, j = 0; i < n; i ++) {
    while (check()) j++;
}
```

### discretzation

```cpp
std::vector<int> alls;

std::ranges::sort(alls);
alls.erase(std::unique(alls.begin(), alls.end()), alls.end());
```

## basic datastructure

### link list

```cpp
// forward
const int maxn = 1e5 + 10;
int e[maxn], ne[maxn], h = 0, t = -1, idx;
void add_front(int x) {
    e[idx] = x, ne[idx] = h, h = idx++;
}

void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}
// use array simulate the link list
```

### double link list

```cpp
int e[maxn], l[maxn], r[maxn], h, t, idx;

void init() {
    h = 1, t = 2, idx = 3;
    r[h] = t, l[t] = h;
}

void add_front(int x) {
    e[idx] = x, r[idx] = r[h], l[idx] = h;
    l[r[h]] = idx, r[h] = idx;
    idx += 1;
}

void add_back(int x) {
    e[idx] = x, r[idx] = t, l[idx] = l[t];
    r[l[t]] = idx, l[t] = idx;
    idx += 1;
}

void push_at_left(int k, int x) {
    e[idx] = x, r[idx] = k, l[idx] = l[k];
    r[l[k]] = idx, l[k] = idx;
    idx += 1;
}

void push_at_right(int k, int x) {
    e[idx] = x, l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx;
    idx += 1;
}

void remove(int k) {
    r[l[k]] = r[k], l[r[k]] = l[k];
}

```

### stack

```cpp
int stack[maxn], top = -1;
void push(int x) {
    stack[++top] = x;
}

void pop() {
    top -= 1;
}
bool empty() { return top == -1; }
```

### queue

```cpp
int queue[maxn], tail = -1, head = 0;

void push(int x) {
    queue[++tail] = x;
}
void pop() { head += 1; }

bool emoty() { return tail >= head; }
```

### cycle queue

### monotonic queue

```cpp
int queue[maxn], tail = -1, head = 0;
int a[n];
for (int i = 0; i < n; i++) {
    while (tail >= head && queue[tail] > a[i]) tail -= 1;
    queue[++tail] = a[i];
    std::cout << queue[head] << ' ';
}

// 维护最大的：同理
```

### monotanic stack

```cpp
// 尋找该数左侧第一个小与他的数
int stack[maxn], top = -1;
for (int i = 0; i < n; i++) {
    std::cin >> x;
    while (top != -1 && stack[top] > x) top -= 1;
    if (top != -1) std::cout << stack[top] << ' ';
    else std::cout << -1 << ' ';
}
```

### kmp

忘了咋写了

```cpp
char str[maxn], partten[maxn]; // idx start at 1;
int prefix[maxn]; // 每个字符串的最长公共钱后缀
// match

for (int i = 1, j = 0; i <= n; i++) {
    while ()
    }
// 忘了， 得复习加训了

```

### dsu

```cpp
int father[maxn];

int find(int x) {
    if (father[x] != x) father[x] = find(father[x]);
    return father[x];
}

// 维护集合中点的个数的并查集， 需要开一个 d[maxn] 数组记录

// 维护集合中点的距离的并查集

int d[maxn];
int find(int x) {
    if (f[x] != x) {
        int t = find(f[x]);
        d[x] += d[f[x]];
        f[x] = t;
    }
    return f[x];
}

```

### heap

忘了，只学了 down，up；

### hash table

没学

## graph theory

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



