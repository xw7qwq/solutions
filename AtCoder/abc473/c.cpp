#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> cnt(k);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        a--;
        cnt[a]++;
    }

    std::sort(cnt.begin(), cnt.end());

    auto it = std::lower_bound(cnt.begin(), cnt.end(), cnt.back() - 1);
    std::cout << cnt.end() - it << "\n";
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
