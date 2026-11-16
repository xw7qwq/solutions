#include <bits/stdc++.h>

// #define int long long

using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;

int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

Z fac[200010];

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }

    std::map<i64, std::vector<int>> whs;
    for (int i = 0; i < n - 1; i++) {
        whs[pre[i + 1] - suf[n - 1 - i]].push_back(i);
    }

    auto count = [&](int l, int r, int x) {
        if (!whs.contains(x)) {
            return 0;
        } else {
            auto &v = whs[x];
            return (int)std::distance(std::lower_bound(v.begin(), v.end(), l), std::upper_bound(v.begin(), v.end(), r));
        }
    };

    while (q--) {
        int i, v;
        std::cin >> i >> v;
        i--;
        int j = n - 1 - i;

        int lo = std::min(i, j), hi = std::max(i, j) - 1;
        i64 tar = i < j ? -v : v;

        int cnt = count(0, lo - 1, 0) + count(lo, hi, tar) + count(hi + 1, n - 2, 0);

        if (m - 1 > cnt) {
            std::cout << 0 << "\n";
        } else {
            std::cout << fac[cnt] * fac[cnt - m + 1].inv() * fac[m - 1].inv() << "\n";
        }
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i <= 2E5; i++) {
        fac[i] = fac[i - 1] * i;
    }


    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
