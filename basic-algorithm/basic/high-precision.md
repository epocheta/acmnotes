# high precision

```cpp
auto div(auto & a, int b, int & t) {
    std::vector<int> c;
    t = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        t = t * 10 + a[i];
        c.push_back(t / b);
        t %= b;
    }
    std::reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
```

```cpp
auto multi(auto & a,  i64 b) {
    std::vector<int> c;
    for (int i = 0, t = 0; i < a.size() || t; i++) {
        if (i < a.size()) t += (a[i] * b);
        c.push_back(t % 10);
        t /= 10;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

```

```cpp
auto add(auto & a, auto & b) {
    std::vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
```

```cpp
auto sub(auto & a, auto & b) {
    std::vector<int> c;
    for (int i = 0, t = 0; i < a.size(); i++) {
        t = a[i] - t;
        if (i < b.size()) t -= b[i];
        c.push_back((t + 10) % 10);
        t = (t < 0) ? 1 : 0;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
```
