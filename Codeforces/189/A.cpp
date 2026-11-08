#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;

    int mx = 0;
    for (int x = 0; x * a <= n; x++) {
        for (int y = 0; x * a + y * b <= n; y++) {
            int nn = n - x * a - y * b;
            if (nn % c == 0) {
                mx = std::max(mx, x + y + nn / c);
            }
        }
    }
    std::cout << mx << "\n";
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
