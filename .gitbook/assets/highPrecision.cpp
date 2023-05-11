#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long i64;

bool cmp(auto & a, auto & b) {
    if (a.size() == b.size()) return (a >= b);
    return a.size() > b.size();
}

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

int main () {
    std::string A, B;
    std::vector<int> a, b;
    std::cin >> A >> B;
    for (int i = A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');
    for (int i = B.size() - 1; i >= 0; i--) b.push_back(B[i] - '0');

    if (cmp(A, B)) {
        auto c = sub(a, b);
        for (int i = c.size() - 1; i >= 0; i--) std::cout << c[i];
    } else {
        auto c = sub(b, a);
        std::cout << '-';
        for (int i = c.size() - 1; i >= 0; i--) std::cout << c[i];
    }
}