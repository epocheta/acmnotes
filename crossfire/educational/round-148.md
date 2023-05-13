# Round 148

### Summarize <a href="#name" id="name"></a>

时间紧张，没有参加



## A. New Palindrome <a href="#name-1" id="name-1"></a>

### Problem Thought <a href="#problem-thought-1" id="problem-thought-1"></a>

​寻找 $$[1, \ \lfloor \frac{n} {2} \rfloor ]$$ 是否有不同的字符即可

### Implementation <a href="#implementation-1" id="implementation-1"></a>

```cpp
void sol() {
    std::string s;
    std::cin >> s;

    for (int i = 1; i < s.size() / 2; i++) {
        if (s[i] != s[i - 1]) {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
}
```

##

## B. Maximum Sum

### Problem Thought <a href="#problem-thought-2" id="problem-thought-2"></a>

​考虑到 $$k$$ 值一定，即无论以如何方法去删数，都会删除前 $$2x$$ 个和后 $$y$$ 个，且 $$x + y = k$$，因此可以想到枚举 $$x$$ 或 $$y$$ 去求出最优解，预处理一个前缀和数组即可，时间复杂度为 $$O(n)$$。

### Implementation <a href="#implementation-2" id="implementation-2"></a>

```cpp
void sol() {
    int n, k;
    std::cin >> n >> k;
 
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
 
    std::ranges::sort(a);
 
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
 
    i64 ans = -1e9;
    for (int i = 0; i <= k; i++) {
        ans = std::max(ans, a[n - k + i] - a[i * 2]);
    }
    
    std::cout << ans << '\n';
}
```



## C. Contrast Value

### Problem Thought <a href="#problem-thought-3" id="problem-thought-3"></a>

​找拐点

### Implementation <a href="#implementation-3" id="implementation-3"></a>

```cpp
void sol() {
    int n, ans = 2;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto & i : a) std::cin >> i;

    int m = std::ranges::unique(a).begin() - a.begin();
    if (m == 1) ans = 1;

    for (int i = 1; i < m - 1; i++) {
        if (a[i + 1] > a[i] ^ a[i] > a[i - 1]) ans++;
    }

    std::cout << ans << '\n';
}
```

## &#x20;<a href="#name-4" id="name-4"></a>

## Name <a href="#name-4" id="name-4"></a>

### Problem Thought <a href="#problem-thought-4" id="problem-thought-4"></a>

​

### Implementation <a href="#implementation-4" id="implementation-4"></a>
