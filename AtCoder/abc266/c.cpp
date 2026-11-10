#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::vector<std::pair<int, int>> p(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> p[i].first >> p[i].second;
    }

    for (int x = 0; x < 4; x++) {
        int z = (x + 1) % 4;
        int y = (x + 3) % 4;
        
        int a = p[z].first - p[x].first, b = p[z].second - p[x].second;
        int c = p[y].first - p[x].first, d = p[y].second - p[x].second;
        if (a * d - b * c < 0) {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
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
