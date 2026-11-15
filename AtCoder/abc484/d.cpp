#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> cnt(N + 1);
    std::vector<int> A(N);
    int ans = 1;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];

        if (i && A[i] != A[i - 1]) {
            ans += i - cnt[A[i]];
        }
    
        cnt[A[i]]++;
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
