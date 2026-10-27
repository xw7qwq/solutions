#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> f(m);
    for (int i = 0; i < m; i++) {
        std::cin >> f[i];
    }
    std::sort(f.begin(), f.end());
    int mn = 1E18;
    for (int i = 0; i + n - 1 < m; i++) {
        mn = std::min(mn, f[i + n - 1] - f[i]);
    }
    std::cout << mn << "\n";
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
