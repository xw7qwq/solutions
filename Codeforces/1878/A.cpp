#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    bool ok = false;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == k) {
            ok = true;
        }
    }

    std::cout << (ok ? "YES" : "NO") << "\n";
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
