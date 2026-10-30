#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int H, W, Q;
    std::cin >> H >> W >> Q;

    std::vector<std::set<int>> r(H), c(W);
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            r[x].insert(y);
        }
    }
    for (int y = 0; y < W; y++) {
        for (int x = 0; x < H; x++) {
            c[y].insert(x);
        }
    }
    while (Q--) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        if (r[x].find(y) != r[x].end()) {
            r[x].erase(y);
            c[y].erase(x);
        } else {
            auto it = r[x].lower_bound(y);
            if (it != r[x].begin()) {
                it--;
                auto ny = *it;
                r[x].erase(ny);
                c[ny].erase(x);
            }

            it = r[x].lower_bound(y);
            if (it != r[x].end()) {
                auto ny = *it;
                r[x].erase(ny);
                c[ny].erase(x);
            }

            it = c[y].lower_bound(x);
            if (it != c[y].begin()) {
                it--;
                auto nx = *it;
                c[y].erase(nx);
                r[nx].erase(y);
            }

            it = c[y].lower_bound(x);
            if (it != c[y].end()) {
                auto nx = *it;
                c[y].erase(nx);
                r[nx].erase(y);
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < H; i++) {
        sum += r[i].size();
    }
    std::cout << sum << "\n";

    
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
