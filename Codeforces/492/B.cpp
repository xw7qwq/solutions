#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, l;
    std::cin >> n >> l;

    std::vector<long double> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    long double mx = 0;
    for (int i = 0; i + 1 < a.size(); i++) {
        mx = std::max(mx, a[i + 1] - a[i]);
    }
    std::cout << std::fixed << std::setprecision(10) << std::max({a[0], mx / 2, l - a.back()}) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
