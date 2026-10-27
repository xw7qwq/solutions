#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, D;
    std::cin >> N >> D;

    std::vector<int> cnt(1E6 + 10);
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;
        cnt[A]++;
    }

    if (D == 0) {
        int sum = 0;
        for (int i = 0; i < 1E6; i++) {
            sum += std::max(0LL, cnt[i] - 1);
        }
        std::cout << sum << "\n";
        return;
    }

    int sum = 0;
    for (int s = 0; s < D; s++) {
        int tak = 0, skp = 0;
        for (int v = s; v <= 1E6; v += D) {
            int ntak = std::min(tak, skp) + cnt[v];
            int nskp = tak;
            tak = ntak;
            skp = nskp;
        }
        sum += std::min(tak, skp);
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
