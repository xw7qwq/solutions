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
