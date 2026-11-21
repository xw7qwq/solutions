#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int x, y, n;
    std::cin >> x >> y >> n;

    std::string s;
    std::cin >> s;

    int ans = x + y;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            if (y) {
                y++;
            } else {
                x--;
                y++;
            }
        } else {
            if (y) {
                y--;
                x++;
            } else {
                x--;
            }
        }
        ans = std::max(ans, x + y);
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
