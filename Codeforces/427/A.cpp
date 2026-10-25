#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    int mn = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        s += a;
        mn = std::min(s, mn);
    }
    std::cout << std::abs(mn) << "\n";
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
