#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> A(2 * N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i + N] = A[i];
    }

    std::vector<std::vector<int>> dp(2 * N, std::vector<int>(2 * N));
    for (int len = 2; len <= N; len++) {
        for (int l = 0; l + len - 1 < 2 * N; l++) {
            int r = l + len - 1;
            for (int m = l; m + 1 <= r; m++) {
                dp[l][r] = std::max(dp[l][r], dp[l][m] + dp[m + 1][r] + A[(l + 2 * N - 1) % (2 * N)] * A[m] * A[r]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = std::max(ans, dp[i][i + N - 1]);
    }
    std::cout << ans << "\n";
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
