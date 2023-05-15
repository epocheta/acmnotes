# ABC Round 301

### Summarize <a href="#name" id="name"></a>

$$C \gg D$$

## C. AtCoder Cards <a href="#name-3" id="name-3"></a>

### Problem Thought <a href="#problem-thought-3" id="problem-thought-3"></a>

​

### Implementation <a href="#implementation-3" id="implementation-3"></a>

```cpp
typedef long long i64;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v1(30), v2(30);
    std::string a, b, atc = "atcoder";
    std::cin >> a >> b;
    
    int at1 = 0, at2 = 0;
    for (auto c : a) {
        if (c == '@') at1++; 
        else v1[c - 'a']++;
    }

    int rep = 0;
    for (auto c : b) {
        if (c == '@') at2++;
        else if (v1[c - 'a']) rep++, v1[c - 'a']--;
        else v2[c - 'a']++; 
    }
    if (at1 < a.size() - rep - at2) {
        std::cout << "No\n";
        return 0;
    }
    for (int i = 0;i <= 26; i++) {
        if (v1[i] && atc.find(i + 'a') == std::string::npos || v2[i] && atc.find(i + 'a') == std::string::npos) {
            std::cout << "No\n";
            return 0;
        } 
    } 

    std::cout << "Yes\n";
}

```

## D. Bitmask <a href="#name-4" id="name-4"></a>

### Problem Thought <a href="#problem-thought-4" id="problem-thought-4"></a>

​

### Implementation <a href="#implementation-4" id="implementation-4"></a>

```cpp
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, res = 0;
    std::string s;
    std::cin >> s >> n;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') res += std::exp2l(s.size() - i - 1);  
    }
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            if (i64 it = std::exp2l(s.size() - i - 1); res + it <= n) res += it;
        }
    }

    if (res > n) res = -1;
    std::cout << res << '\n';
}
```
