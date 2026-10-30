#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M, D;
    std::cin >> N >> M >> D;

    std::vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int mx = -1;
    for (int i = 0; i < N; i++) {
        auto it = std::lower_bound(B.begin(), B.end(), A[i] + D + 1);
        if (it != B.begin()) {
            it--;
            if (std::abs(*it - A[i]) <= D) {
                mx = std::max(mx, *it + A[i]);
            }
        }
    }
    std::cout << mx << "\n";
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
