#include <bits/stdc++.h>

#define int long long

constexpr int P = 1E9 + 7;
using i64 = long long;
using u64 = unsigned long long;

i64 mul(i64 a, i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 1;
    std::sort(a.begin(), a.end(), std::greater<>());
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && a[i] == a[i + 1]) {
            break;
        }
        ans += power(a[i] - 1, i + 1, P);
        ans %= P;
    }

    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
