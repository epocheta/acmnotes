# Phase\_Shift

#### Problem Link:[ ](https://codeforces.com/problemset/problem/1735/C)[https://codeforces.com/problemset/problem/1735/C](https://codeforces.com/problemset/problem/1735/C)

### Problem Description

给出一个字符串，构造一个字符串环，使得存在一个字符串通过环的映射(一个字母通过环的映射，成为在环上的顺时针方向的后继元素)构成的字符串等于给出的字符串，且其的字典序最小。

### Problem Thought

贪心地去从第一个字母开始去找它在环上的前驱字母，找的时候用并查集判断是否在一个集合（这个字母是否已经是某个字母的前驱了）并用一个 `vis` 数组记录这个字母是否已经是某个字母的前驱了, 结果用 `map` 记录，注意当有26个不同的字母的时候，最后一个字母一定是在环上的，但是并查集判断的时候却一定在同一集合（祖宗节点相同）因为最后字母的前驱一定是最后一个字母的祖宗节点（因为要构成环），所以要特判一下。

### Implementation

```cpp
// 全局变量
std::vector<int> fa(30);
```

并查集的 `find()` 函数与一般的没有什么区别，所以就没有写。

```cpp
void sol() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::iota(fa.begin(), fa.end(), 0); // 初始化父节点数组
    std::vector<int> vis(30); 
    std::map<char, char> ans; 

    for (auto c : s) {
        if (ans.count(c)) continue; // 重复元素不用再进行处理
        int idc = find(c - 'a'); 
        for (int i = 0; i < 26; i++) {
            int idi = find(i); 
            if (vis[i] == 0 && idc != idi) { 
                fa[idi] = idc, ans[c] = i + 'a'; 
                vis[i] = 1; 
                break;
            } else if (vis[i] == 0 && ans.size() == 25) {
                ans[c] = i + 'a';
            }
        }
    }
    c
    for (auto c : s)
        std::cout << ans[c];
    std::cout << '\n';
}
```
