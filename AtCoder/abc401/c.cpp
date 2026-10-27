#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, K;
    std::cin >> N >> K;

    if (N < K) {
        std::cout << 1 << "\n";
        return;
    }

    std::vector<int> A(N + 1);
    for (int i = 0; i < K; i++) {
        A[i] = 1;
    }

    constexpr int P = 1E9;
    int sum = K;
    for (int r = K, l = 0; r <= N; r++) {
        while (r - l > K) {
            sum -= A[l++];
            sum = (sum % P + P) % P;
        }
        A[r] = sum;
        sum += A[r];
    }
    // for (int i = 0; i <= N; i++) {
    //     std::cout << A[i] << " \n"[i == N];
    // }

    std::cout << A[N] << "\n";
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
