#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M, S, T;
    std::cin >> N >> M >> S >> T;
    S--, T--;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, S});
    std::vector<int> d(N, -1);
    while (!pq.empty()) {
        auto [w, x] = pq.top();
        pq.pop();
        
        if (w < d[x] || adj[x].empty()) {
            continue;
        }
        int mn = *min_element(adj[x].begin(), adj[x].end());
        for (auto y : adj[x]) {
            int nw = w + (y != mn);
            if (d[y] == -1 || nw < d[y]) {
                d[y] = nw;
                pq.push({nw, y});
            }
        }
    }
    std::cout << d[T] << "\n";
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
