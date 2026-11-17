#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> r(N), c(N);
    int cnt = 0;

    std::vector<int> x(M), y(M);
    for (int i = 0; i < M; i++) {
        std::cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    for (int i = M - 1; i >= 0; i--) {
        if (!r[x[i]] && !c[y[i]]) {
            cnt++;
        }
        r[x[i]] = true;
        c[y[i]] = true;
    }

    std::cout << cnt << "\n";
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
