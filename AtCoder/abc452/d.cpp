#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string S, T;
    std::cin >> S >> T;

    const int n = S.size();
    std::vector<std::array<int, 26>> nxt(n + 1);
    nxt[n].fill(-1);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][S[i] - 'a'] = i;
    }

    int sum = 0;
    for (int l = 0; l < n; l++) {
        int u = l;
        for (int r = 0; r < T.size(); r++) {
            u = nxt[u][T[r] - 'a'];
            if (u == -1) {
                break;
            }
            u++;
        }

        if (u != -1) {
            sum += n - u + 1;
        }
    }
    std::cout << (n + 1) * n / 2 - sum << "\n";
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
