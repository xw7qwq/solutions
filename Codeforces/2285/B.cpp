#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int x = std::count(s.begin(), s.end(), '0');
    int y = n - x;

    int ans = 0;
    for (int i = x; i <= std::min(x + k, n); i++) {
        int ny = n - i;
        ans = std::max(ans, 1 + (1 + i) * i / 2 + (1 + ny) * ny / 2);
    }
    // std::cout << x << " " << y << " " << ans << "\n";
    // return;
    for (int i = y; i <= std::min(y + k, n); i++) {
        int nx = n - i;
        ans = std::max(ans, 1 + (1 + i) * i / 2 + (1 + nx) * nx / 2);
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
