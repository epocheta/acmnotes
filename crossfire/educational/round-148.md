# Edu Round 148

### Summarize <a href="#name" id="name"></a>

时间紧张，没有参加，没有总结。



## A. New Palindrome <a href="#name-1" id="name-1"></a>

### Problem Thought <a href="#problem-thought-1" id="problem-thought-1"></a>

​寻找 $$[0, \ \lfloor \frac{n} {2} \rfloor ]$$ 是否有不同的字符即可。

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

​考虑到 $$k$$ 值一定，即无论以如何方法去删数，都会删除前 $$2x$$ 个和后 $$y$$ 个，且 $$x + y = k$$，因此可以想到枚举 $$x$$ 或 $$y$$ 去求出最优解，预处理一个前缀和数组即可，时间复杂度为 $$O(2n)$$。

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

排序，去重，看存在多少个单调区间即可。

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

## D1 Red-Blue Operations (Easy Version) <a href="#name-4" id="name-4"></a>

### Problem Thought <a href="#problem-thought-4" id="problem-thought-4"></a>

​当 $$k$$ 小于 $$n$$ 时，所有的操作都可以是加 $$k$$，只要让最小的加上最大的 $$k$$ 就可以保证最小值最大。当 $$k$$ 大于 $$n$$ 时，仍使最大的 $$k$$ 加到最小值上，但是要考虑 当 $$k = 1$$ 时，一定是正的，所以要判断一下第 $$n-1$$ 的奇偶，若是奇数，则可以满足 $$k=1$$一定是加，否则反之，且不将其加到原数组中。接着求出剩下的操作中需要进行多少个减一操作，贪心地先使比最小值大的数进行剩下的操作，如果到最后还剩余有操作数，那就可以批量的处理 $$(k - 1) / n + 1$$ 次。减去即可求出最大的最小值。

### Implementation <a href="#implementation-4" id="implementation-4"></a>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m;

    std::vector<int> A(n);
    for (auto & i : A) std::cin >> i;

    std::ranges::sort(A);

    while (m--) {
        std::cin >> k;
        auto a = A;

        for (int i = 0; i < n && k; i++, k--) {
            if (i < n - 1 || k % 2) a[i] += k; 
        }
                
        int MIN = * std::min_element(a.begin(), a.end());

        if (k % 2) k++;
        k /= 2;

        for (int i = 0; i < n && k > 0; i++) {
            if (a[i] > MIN) k -= a[i] - MIN, a[i] = MIN;
        }          
        
        if (k > 0) MIN -= ((k - 1) / n) + 1;
        std::cout << MIN << ' ';
    }

    return 0;
}
```
