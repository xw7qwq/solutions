#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    if (n < 4) {
        std::cout << -1 << "\n";
    } else {
        std::cout << "4 3 2 1 ";
        for (int i = 5; i <= n; i++) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
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
