#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::map<std::pair<int, int>, int> g;

    while (Q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int X, Y;
            std::cin >> X >> Y;
            X--;
            g[{X, Y}] = true;
        } else if (op == 2) {
            int X;
            std::cin >> X;
            X--;
            g[{X, 0}] = true;
        } else {
            int X, Y;
            std::cin >> X >> Y;
            X--;
            std::cout << (g[{X, 0}] || g[{X, Y}] ? "Yes" : "No") << "\n";
        }
    }
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
