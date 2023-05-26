# Edu Round 149

### Summarize <a href="#name" id="name"></a>

像 $$Div. 3$$

## A - Grasshopper on a Line <a href="#name-1" id="name-1"></a>

### Problem Thought <a href="#problem-thought-1" id="problem-thought-1"></a>

​无

### Implementation <a href="#implementation-1" id="implementation-1"></a>

```cpp
void sol() {
    int n, k;
    std::cin >> n >> k;

    if (n % k) {
        std::cout << 1 << "\n";
        std::cout << n << "\n";
    } else {
        std::cout << 2 << "\n";
        std::cout << n - 1 << ' ' << 1 << "\n";
    }
}
```

## B. Comparison String <a href="#name-2" id="name-2"></a>

### Problem Thought <a href="#problem-thought-2" id="problem-thought-2"></a>

​最长子序列

### Implementation <a href="#implementation-2" id="implementation-2"></a>

```cpp
void sol() {
    int n, ans = 0, flag = 1, ok = 0;
    std::string str;
    std::cin >> n >> str;
 
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == str[i - 1]) {
            ok = 1, flag++;
            ans = std::max(ans, flag);
        } else flag = 1;
    }
    if (ok == 0) ans++;
    
    std::cout << ans + 1 << "\n";
}
```

## C. Best Binary String <a href="#name-3" id="name-3"></a>

### Problem Thought <a href="#problem-thought-3" id="problem-thought-3"></a>

​以 $$0$$ 分割的子串中，若有 $$1$$，则所有的 $$?$$ 都置 $$1$$。

### Implementation <a href="#implementation-3" id="implementation-3"></a>

```cpp
void sol() {
    std::string s;
    std::cin >> s;
 
    auto proc = [&](auto i, auto j) -> void {
        if (s[j] != '0') j++;
        bool have_one = false;
        for (int o = i; o < j; o++) {
            if (s[o] == '1') have_one = true;
        }
        for (int o = i; o < j; o++) {
            if (s[o] == '?') s[o] = (int)have_one + '0';
        }
    };
 
    for (int i = 0, j = 0; i < s.size(); i++) {
        while (j < s.size() && s[j] != '0') j++;
        proc(i, j);
        i = j, j++;
    }
 
    std::cout << s << '\n';
}
```

## D. Bracket Coloring <a href="#name-4" id="name-4"></a>

### Problem Thought <a href="#problem-thought-4" id="problem-thought-4"></a>

​

### Implementation <a href="#implementation-4" id="implementation-4"></a>

```cpp
void sol () {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> ans(n, 0);

    int res = 0;
    bool orderly = false, reverse = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            res++;
            if (res > 0) ans[i] = 1;
            else ans[i] = 2;
        } else if (s[i] == ')') {
            res--;
            if (res >= 0) ans[i] = 1;
            else ans[i] = 2;
        }
        if (ans[i] == 1) orderly = true;
        else if (ans[i] == 2) reverse = true;
    }

    if (res == 0) {
        std::cout << orderly + reverse << '\n';
        if (orderly + reverse == 1) {
            for (int i = 0; i < n; i++) {
                std::cout << 1 << ' ';
            }
        } else {
            for (int i = 0; i < n; i++) {
                std::cout << ans[i] << ' ';
            }
        }
    } else {
        std::cout << "-1";
    }

    std::cout << '\n';
}
```
