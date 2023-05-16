# ABC Round 301

### Summarize <a href="#name" id="name"></a>

$$C \gg D$$

## C. AtCoder Cards <a href="#name-3" id="name-3"></a>

### Problem Thought <a href="#problem-thought-3" id="problem-thought-3"></a>

​因为两个字符串长度相同，可以将这样划分两个字符串：$$S = S_{same} + S_{@} + S_r$$，我们只需要考虑后两项。因为对于两个字符串来说 $$S_r$$中再没有相同元素，如果想要使两个字符串相同，就需要替换 $$S_@$$，此时我们判断一下这个字符串的 $$S_@$$ 的长度是否大于等于另一个字符串的 $$S_r$$，若大于等于，则判断 $$S_r$$ 中是否没有出现无法被 $$@$$ 替换的字符即可。若同时满足上述条件，即满足题意。

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
        if (v1[i] && atc.find(i + 'a') == -1 || v2[i] && atc.find(i + 'a') == -1) {
            std::cout << "No\n";
            return 0;
        } 
    } 

    std::cout << "Yes\n";
}

```

## D. Bitmask <a href="#name-4" id="name-4"></a>

### Problem Thought <a href="#problem-thought-4" id="problem-thought-4"></a>

​对于一个含有 $$?$$ 的 $$01$$ 字符串，对其十进制值的大小的影响，位数大的贡献越大，所以我们可以贪心的从最高位的 $$?$$ 开始判断，将 $$?$$ 替换为 $$1$$ 后的十进制值是否小于等于 $$n$$ ，若是，则此项可以置 $$1$$。

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
