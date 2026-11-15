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

    std::vector<int> pre(2 * N + 1);
    for (int i = 0; i < 2 * N; i++) {
        pre[i + 1] = pre[i] + A[i];
    }

    constexpr int inf = 1E17;
    std::vector<std::vector<int>> dpmn(2 * N, std::vector<int>(2 * N, inf));
    for (int i = 0; i < 2 * N; i++) {
        dpmn[i][i] = 0;
    }
    std::vector<std::vector<int>> dpmx(2 * N, std::vector<int>(2 * N, -inf));
    for (int i = 0; i < 2 * N; i++) {
        dpmx[i][i] = 0;
    }

    for (int len = 2; len <= N; len++) {
        for (int l = 0; l + len - 1 < 2 * N; l++) {
            int r = l + len - 1;
            for (int m = l; m + 1 <= r; m++) {
                dpmn[l][r] = std::min(dpmn[l][r], pre[r + 1] - pre[l] + dpmn[l][m] + dpmn[m + 1][r]);
                dpmx[l][r] = std::max(dpmx[l][r], pre[r + 1] - pre[l] + dpmx[l][m] + dpmx[m + 1][r]);
            }
        }
    }

    int mn = inf, mx = -inf;
    for (int i = 0; i < N; i++) {
        mn = std::min(mn, dpmn[i][i + N - 1]);
        mx = std::max(mx, dpmx[i][i + N - 1]);
    }
    std::cout << mn << "\n" << mx << "\n";

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
