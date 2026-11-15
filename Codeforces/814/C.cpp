#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::array<int, 26>> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i];
        pre[i + 1][s[i] - 'a']++;
    }

    std::vector<std::array<int, 26>> ans(n + 1);

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            for (int c = 0; c < 26; c++) {
                int u = r - l + 1 - (pre[r + 1][c] - pre[l][c]);
                ans[u][c] = std::max(ans[u][c], r - l + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int c = 0; c < 26; c++) {
            ans[i][c] = std::max(ans[i][c], ans[i - 1][c]);
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int m;
        char c;
        std::cin >> m >> c;
        std::cout << ans[m][c - 'a'] << "\n";
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
