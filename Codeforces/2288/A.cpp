#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int x;
    std::cin >> x;

    int ans = x;
    for (int a = 1; a <= x; a++) {
        int sum = a - 1;
        int d = 0;
        for (int b = a; ; b = std::max(1LL, b - 1)) {
            d += b;
            sum++;
            if (d >= x) {
                ans = std::min(ans, sum);
                break;
            }
        }
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
