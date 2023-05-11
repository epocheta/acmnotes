# Sending a Sequence Over the Network

#### Problem Link: [826\_Div.3\_E](https://codeforces.com/contest/1741/problem/E)

#### Problem Description

描述这样一个操作：一串数可以在原来顺序的基础上分割成几个子段，将分割后的子段的长度加在这个子段首或子段尾，然后按照原来的顺序重新组合，这样就形成了一个新的序列。

给一个序列，询问其是否是某一个序列经过上述操作形成的。

#### Problem Thought

若这个序列满足题述要求，则对于序列的最后一个数 $$a_n$$，存在两种情况：1. 是最后一个子序列的最后一位，2. 是最后一个子序列的长度。满足两种情况的其中之一即可判断序列 $$a$$ 合法。对于第一种情况来说：因为无法知道最后一个序列的具体长度，所以很难递推入手。对于第二种情况来说：则必须满足$$a_{0 \rightarrow n - a_i - 1}$$是一个合法序列。

因为 $$a_n$$ 情况特殊，无法作为子段头的长度声明，所以考虑更一般的情况 $$a_i$$：

1. 是某个子段的首部长度声明
   * 则若 $$a_{0 \rightarrow i - 1}$$ 合法，$$a_{0 \rightarrow i + a_i}$$合法
2. 是某个子段的尾部长度声明
   * 则若 $$a_{0 \rightarrow i - a_i - 1}$$合法, $$a_{0 \rightarrow i}$$ 合法
3. 是某个子段的非长度声明的元素

#### solution code

```cpp
void sol() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), f(n);
    for (auto & i : a) std::cin >> i;

    for (int i = 0; i < n; i++) {
        if (i + a[i] < n && (i - 1 == -1 || i - 1 >= 0 && f[i - 1])) f[i + a[i]] = 1;
        if (i - a[i] - 1 == -1 || (i - a[i] - 1 >= 0 && f[i - a[i] - 1])) f[i] = 1;
    }

    if (f[n - 1]) std::cout << "YES\n";
    else std::cout << "NO\n";
}
```
