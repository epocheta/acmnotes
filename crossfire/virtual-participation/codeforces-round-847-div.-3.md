# Codeforces Round 847 Div. 3

### A. Polycarp and the Day of Pi <a href="#name-1" id="name-1"></a>

#### Problem Thought <a href="#problem-thought-1" id="problem-thought-1"></a>

​模拟

#### Implementation <a href="#implementation-1" id="implementation-1"></a>

```cpp
std::string pi = "314159265358979323846264338327";
 
void sol () {
    std::string s;
    std::cin >> s;
 
    int i;
    for (i = 0; i < s.size(); i++) {
        if (s[i] != pi[i]) break;
    }
 
    std::cout << i << '\n';
}
```

### B. Taisia and Dice <a href="#name-2" id="name-2"></a>

#### Problem Thought <a href="#problem-thought-2" id="problem-thought-2"></a>

​选取的最大值即为 $$s - r$$, 使得剩余的 $$r$$，分配在 $$n - 1$$ 个骰子中，且最大值不超过 $$s - r$$ 即可。

#### Implementation <a href="#implementation-2" id="implementation-2"></a>

```cpp
void sol () {
    int n, s, r;
    std::cin >> n >> s >> r;
 
    int max = s - r;
    std::cout << max << ' ';
 
    int cnt = n - 1;
    while (r > 0) {
        if (r > r / cnt) {
            std::cout << r / cnt << ' ';
            r -= r / cnt;
        } else {
            std::cout << r << ' ';
            r = 0;
        }
        cnt--;
    }
 
    std::cout << '\n';
}
```

### C. Premutation <a href="#name-3" id="name-3"></a>

#### Problem Thought <a href="#problem-thought-3" id="problem-thought-3"></a>

​因为 $$n \geq 3$$， 序列中头元素出现超过一次的即为唯一的头元素，将其插入到非其为头元素的序列头部即可。

#### Implementation <a href="#implementation-3" id="implementation-3"></a>

```cpp
void sol () {
    int n;
    std::cin >> n;
 
    std::vector a(n, std::vector<int>(n - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            std::cin >> a[i][j];
        }
    }
 
    std::vector<int> head(n + 1);
    for (int i = 0; i < n; i++) {
        head[a[i][0]]++;
    }
 
    int Head = std::max_element(head.begin(), head.end()) - head.begin();++
 
    for (int i = 0; i < n; i++) {
        if (a[i][0] != Head) {
            std::cout << Head << ' ';
            for (int j = 0; j < n - 1; j++) {
                std::cout << a[i][j] << ' ';
            }
            std::cout << '\n';
            return;
        }
    }
}
```

### D. Matryoshkas <a href="#name-4" id="name-4"></a>

#### Problem Thought <a href="#problem-thought-4" id="problem-thought-4"></a>

​对于每一个 $$set$$, 其中的元素是连续且不重复的，对于某个值 $$k$$, 若 $$k$$ 出现了 $$n$$ 次，且 $$k - 1$$ 出现了 $$m$$ 次，那么就会增加 $$max(0, n - m)$$ 个 $$set$$。

#### Implementation <a href="#implementation-4" id="implementation-4"></a>

```cpp
void sol () {
    int n;
    std::cin >> n;
 
    std::map<int, int> m;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        m[x] += 1;
    }
 
    int ans = 0, cur = 0;
    for (auto [k, v] : m) {
        if (v > m[k - 1]) ans += v - m[k - 1];
    }
 
    std::cout << ans << '\n';
}
```
