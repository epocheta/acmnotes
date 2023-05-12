# Codeforces Round 850 Div.2

VP 之前在和朋友讨论数学建模的选题，感觉自己还挺急的，哈哈。

这次 VP 体验还不错，div.2 的场AC了4道（算是），但是其实这四道题都不是特别难，没什么算法。

### A1. Non-alternating Deck (easy version)

#### Problem Thought

简单模拟

#### Problem Solution

{% code fullWidth="false" %}
```cpp
void sol() {
    int n, a = 1, b = 0;
    std::cin >> n;
    
    n -= 1;
    for (int i = 2, j = 0; n; i++, j = (j + 1) % 4) {
        if (j < 2 && n >= i) b += i, n -= i;
        else if (j < 2 && n < i) b += n, n = 0;
        else if (n >= i) a += i, n -= i;
        else a += n, n = 0;
    }
    
    std::cout << a << ' ' << b << '\n';
}
```
{% endcode %}

### A2. Alternating Deck (hard version) solution 1

#### Problem Thought

在 A1 的基础上的模拟

#### Problem Solution

{% code fullWidth="false" %}
```cpp
void sol() {
    int n, wa = 1, wb = 0, ba = 0, bb = 0;
    std::cin >> n;
 
    n -= 1;
    for (int i = 2, j = 0; n; i++, j = (j + 1) % 4) {
        if (j < 2 && n >= i) {
            if (i % 2) wb += i / 2, bb += i / 2 + 1;
            else wb += i / 2, bb += i / 2;
            n -= i;
        } else if (j < 2) {
            if (n % 2) wb += n / 2, bb += n / 2 + 1;
            else wb += n / 2, bb += n / 2;
            n = 0;
        } 
        else if (n >= i) {
            n -= i;
            if (i % 2) wa += i / 2 + 1, ba += i / 2;
            else wa += i / 2, ba += i / 2;
        } else {
            if (n % 2) wa += n / 2 + 1, ba += n / 2;
            else wa += n / 2, ba += n / 2;
            n = 0;
        }
    }
    
    std::cout << wa << ' ' << ba << ' ' << wb << ' ' << bb << '\n';
}
```
{% endcode %}

### B. Cake Assembly Line solution 1

#### Problem Thought

先将所有的蛋糕与巧克力分配器位置初始化：整体位置左移，使得 $$a_1 - w$$ 和 $$b_1 - h$$ 等于 $$0$$，然后二分分配器的左移距离，对于每一对蛋糕和喷洒器，若出现了 $$b_i - h < a_i - w$$ 更新 $$l$$，若出现了 $$b_i - h > a_i - w$$ 更新 $$r$$，若对于每一对都满足题意，则直接输出 YES 并返回。

#### Problem Solution

{% code fullWidth="false" %}
```cpp
void sol() {
    int n, w, h, a1, b1;
    std::cin >> n >> w >> h;
 
    std::vector<int> a(n), b(n);
    std::cin >> a1, a[0] = a1 - a1 + w;
    for (int i = 1; i < n; i++) std::cin >> a[i], a[i] -= a1 - w;
    std::cin >> b1, b[0] = b1 + h - b1;
    for (int i = 1; i < n; i++) std::cin >> b[i], b[i] += h - b1;
 
    bool flag = false;
    auto check = [&](auto x) {
        for (int i = 0; i < n; i++) {
            if (b[i] - h + x < a[i] - w) return true;
            if (b[i] + h + x > a[i] + w) return false;
        }        
        flag = true;
        return true;
    };
 
    int l = -1, r = 2 * w + 1;
    while (l + 1 != r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            if (flag) {
                std::cout << "YES\n";
                return;
            }
            l = mid;
        } else r = mid;
    }
    
    std::cout << "NO\n";
}
```
{% endcode %}



### B. Cake Assembly Line solution 2

#### Problem Thought

分配器和蛋糕是成对出现的，对于每一对物品，求出为使这一对满足题意的，可以移动的距离的区间，若对于每一对求出的区间存在交集，则满足题意。

#### Problem Solution

{% code fullWidth="false" %}
```cpp
void sol() {
    int n, w, h;
    std::cin >> n >> w >> h;

    std::vector<int> a(n), b(n);
    for (auto & i : a) std::cin >> i;
    for (auto & i : b) std::cin >> i;

    int MAX = -1E9, MIN = 1E9;
    for (int i = 0; i < n; i++) {
        MAX = std::max(MAX, a[i] - w - b[i] + h);
        MIN = std::min(MIN, a[i] + w - b[i] - h);
    }
    
    if (MAX > MIN) std::cout << "NO\n";
    else std::cout << "YES\n";
}
```
{% endcode %}

### C. Monsters (easy version)

#### Problem Thought

构造数列 $$a_i = i$$ 即可，当有不满足数列的情况出现时，从这一位开始向后寻找，存在的数使它成为这一个数，并更新 ans。

#### Problem Solution

```cpp
void sol() {
    int n;
    i64 ans = 0;
    std::cin >> n;
 
    std::map<int, int> m;
    for (int i = 0, x; i < n; i++) std::cin >> x, m[x]++; 
 
    auto it = m.end();
    it--;
    int max = it->first + 1;
    for (int i = 1, j = 0; ; i++) {
        if (m[i] == 0) {
            if (j <= i) j = i;
            for (int k = j; k <= max; k++) {
                if (m[k]) {
                    j = k;
                    break;
                }
            }
            if (m[j] == 0) {
                std::cout << ans << '\n';
                return;
            }             
            ans += j - i, m[j] -= 1, m[i]++; 
        }
    }
    std::cout << ans << '\n';
}
```
