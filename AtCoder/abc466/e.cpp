#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
        C[i] = B[i] - A[i];
    }
    int ans = std::accumulate(A.begin(), A.end(), 0LL);

    constexpr int inf = 1E17;
    std::vector<std::array<int, 2>> dp(K + 1, {-inf, -inf});
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        std::vector<std::array<int, 2>> ndp(K + 1, {-inf, -inf});
        for (int j = 0; j <= K; j++) {
            ndp[j][0] = std::max(dp[j][0], dp[j][1]);
            if (j >= 1) {
                ndp[j][1] = std::max(ndp[j][1], dp[j - 1][0] + C[i]);
            }
            ndp[j][1] = std::max(ndp[j][1], dp[j][1] + C[i]);
        }
        dp = std::move(ndp);
    }

    int mx = 0;
    for (int i = 0; i <= K; i++) {
        mx = std::max({mx, dp[i][0], dp[i][1]});
    }
    std::cout << ans + mx << "\n";
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
