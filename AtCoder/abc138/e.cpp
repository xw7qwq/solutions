#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    const int n = s.size();
    std::vector<std::array<int, 26>> nxt(n + 1);
    nxt[n].fill(n);

    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }

    int u = 0;
    int ans = 0;

    for (auto c : t) {
        if (nxt[0][c - 'a'] == n) {
            std::cout << -1 << "\n";
            return;
        }

        if (nxt[u][c - 'a'] == n) {
            ans++;
            u = 0;
        }
        u = nxt[u][c - 'a'] + 1;
    }
    std::cout << ans * n + u << "\n";
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
