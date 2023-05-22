# Codeforces Round 874

### Summarize <a href="#name" id="name"></a>

<figure><img src="../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

我的评价是，幸亏写出来了 $$D$$。

## A. Musical Puzzle <a href="#name-1" id="name-1"></a>

### Problem Thought <a href="#problem-thought-1" id="problem-thought-1"></a>

​无

### Implementation <a href="#implementation-1" id="implementation-1"></a>

```cpp
void sol () {
    int n;
    std::string str;
    std::set<std::string> s;
    std::cin >> n >> str;
 
    for (int i = 0; i < n - 1; i += 1) {
        s.insert(str.substr(i, 2));
    }
    
    std::cout << s.size() << '\n';
}
```

## B. Restore the Weather <a href="#name-2" id="name-2"></a>

### Problem Thought <a href="#problem-thought-2" id="problem-thought-2"></a>

​排序，记录原始位置。

### Implementation <a href="#implementation-2" id="implementation-2"></a>

```cpp
void sol () {
    int n, k;
    std::cin >> n >> k;
 
    std::vector<std::pair<int, int>> a(n);
    std::vector<int> b(n), c(n);
 
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (auto & i : b) std::cin >> i;
 
    std::ranges::sort(b);
    std::ranges::sort(a);
    
    for (int i = 0; i < n; i++) {
        c[a[i].second] = b[i];
    }
    for (auto i : c) std::cout << i << ' ';
    std::cout << '\n';
}
```

## C. Vlad Building Beautiful Array <a href="#name-3" id="name-3"></a>

### Problem Thought <a href="#problem-thought-3" id="problem-thought-3"></a>

​若序列中有奇数，则此序列必须转化为全为奇数的序列才可满足题意，即最小的偶数一定要比最小的奇数小。

### Implementation <a href="#implementation-3" id="implementation-3"></a>

```cpp
void sol () {
    int n;
    std::cin >> n;
 
    std::vector<int> a, b;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        if (x % 2) a.push_back(x);
        else b.push_back(x);
    }

    if ((b.size() > 0) ^ (a.size() > 0)) {
        std::cout << "YES\n";
        return;
    }
 
    auto min_odd = std::min_element(a.begin(), a.end());
    auto min_even = std::min_element(b.begin(), b.end());
 
    if (* min_even <= * min_odd) {
        std::cout << "No\n";
        return;
    }   
 
    std::cout << "YES\n";
}
 
```

## D. Flipper <a href="#name-4" id="name-4"></a>

### Problem Thought <a href="#problem-thought-4" id="problem-thought-4"></a>

首先要找到从第二位开始的最大数 $$a_{i\_max}$$，考虑两种情况：

1. 最大数在首位
2. 最大数在中间

对于第一种情况，他相对于第二种情况多了一种选择，即旋转自己，仍可能使得字典序最大，而对于两种情况都具有的就是，$$\{(x, i\_max) \mid x \in [1, i\_max] \}$$。遍历比较字典序大小即可。

### Implementation <a href="#implementation-4" id="implementation-4"></a>

```cpp
void sol () {
    int n;
    std::cin >> n;
 
    std::vector<int> a(n), ans(n);
    for (auto & i : a) std::cin >> i;
 
    int max_idx = 0, max = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max_idx = i, max = a[i];
        }
    }
 
    auto check = [&] (int x, int now) {
        int k1 = -1, k2 = -1;
        for (int i = max_idx - 1, j = max_idx - 1, cnt = 0; cnt < max_idx; i += k1, j += k2, cnt++) {
            if (i < x) i = 0, k1 = 1;
            if (j < now) j = 0, k2 = 1;
            if (a[j] < a[i]) return false;
        }
        return true;
    };
 
    int res;
    if (max_idx == n - 1) {
        ans[0] = a[max_idx];
        for (int i = 0; i < n - 1; i++) {
            ans[i + 1] = a[i];
        }
        res = max_idx;
        for (int i = max_idx; i >= 0; i--) {
            if (check(res, i)) res = i;
        }
        for (int i = max_idx; i >= res; i--) std::cout << a[i] << ' ';
        for (int i = 0; i < res; i++) std::cout << a[i] << ' ';
    } else {
        res = max_idx - 1;
        for (int i = max_idx - 1; i >= 0; i--) {
            if (check(res, i)) res = i;
        }
        for (int i = max_idx; i < n; i++) std::cout << a[i] << ' ';
        for (int i = max_idx - 1; i >= res; i--) std::cout << a[i] << ' ';
        for (int i = 0; i < res; i++) std::cout << a[i] << ' ';
    }     
 
    std::cout << '\n';
}
```

## E. Round Dance <a href="#name-4" id="name-4"></a>

### Problem Thought <a href="#problem-thought-4" id="problem-thought-4"></a>

偷学一手 $$jiangly$$ 的并查集做法以及并查集板子。

蒋老师的题解已经特别清晰了，一语中的，但是作为

### Implementation <a href="#implementation-4" id="implementation-4"></a>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

typedef long long i64;

struct DSU {
    std::vector<int> f;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool merge(int a, int b) {
        int fa = find(a), fb = find(b);

        if (fa == fb) {
            return false;
        } else {
            f[fa] = fb;
            return true;
        }
    }   
};

void sol () {
    int n;
    std::cin >> n;
    std::vector<int> a(n), e(n);
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        a[i] = x - 1;
    }

    DSU dsu(n);
    bool chain = false;
    for (int i = 0; i < n; i++) {
        dsu.merge(i, a[i]);
    }   

    // 若是环的话，则不可能出现 a[a[i]] == i
    for (int i = 0; i < n; i++) {
        if (i == a[a[i]]) {
            e[dsu.find(i)] = 1;
            chain = true;
        }
    }

    int min = 0, max = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) {
            if (!e[i]) {
                min++;
            }
            max++;
        }
    }

    std::cout <<  min + chain << ' ' << max << '\n';
}

int main () {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    std::cin >> T;
    for (; T > 0; T--) {
        sol();
    }

    return 0;
}
```
