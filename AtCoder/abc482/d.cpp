#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int l = (a[i] - a[std::max(0LL, i - 1)]) / 2;
        int r = (a[std::min(n - 1, i + 1)] - a[i]) / 2;
        
        int mn = l + r + std::min(std::max({0LL, (a.back() - a[std::min(n - 1, i + 1)]) / 2, (a[std::max(0LL, i - 1)] - a[0]) / 2 - r}), std::max({0LL, (a.back() - a[std::min(n - 1, i + 1)]) / 2 - l, (a[std::max(0LL, i - 1)] - a[0]) / 2}));
        std::cout << mn << "\n";
    }
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
