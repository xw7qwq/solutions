#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        p--;
        adj[p].push_back(i);
    }

    std::queue<int> q;
    std::vector<int> w(n, -1);
    q.push(0);
    w[0] = 0;
    std::vector<int> ans;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        if (w[x] == 0) {
            ans.push_back(x);
        }
        for (auto y : adj[x]) {
            if (w[y] == -1) {
                w[y] = (w[x] + 1) % k;
                q.push(y);       
            }
        }
    }
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
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
