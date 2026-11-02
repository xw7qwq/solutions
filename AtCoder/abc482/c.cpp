#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int H, W, N, Q;
    std::cin >> H >> W >> N >> Q;

    std::vector<int> R(N), C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> R[i] >> C[i];
        R[i]--, C[i]--;
    }

    std::sort(R.begin(), R.end());
    std::sort(C.begin(), C.end());

    while (Q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int u, d;
            std::cin >> u >> d;
            u--, d--;
            std::cout << std::upper_bound(R.begin(), R.end(), d) - std::lower_bound(R.begin(), R.end(), u) << "\n";
        } else {
            int l, r;
            std::cin >> l >> r;
            l--, r--;
            std::cout << std::upper_bound(C.begin(), C.end(), r) - std::lower_bound(C.begin(), C.end(), l) << "\n";
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
