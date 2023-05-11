# basic

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
