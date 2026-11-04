#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::vector<int> pls(N);
    while (Q--) {
        int p, x;
        std::cin >> p >> x;
        p--;
        pls[p] += x;
    }

    auto dfs = [&](this auto &&self, int x, int fa) -> void {
        for (auto y : adj[x]) {
            if (y != fa) {
                pls[y] += pls[x];
                self(y, x);
            }
        }
    };
    dfs(0, -1);

    for (int i = 0; i < N; i++) {
        std::cout << pls[i] << " \n"[i == N - 1];
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
