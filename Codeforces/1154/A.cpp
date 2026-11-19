#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < 3; i++) {
        std::cout << a[3] - a[i] << " \n"[i == 2];
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
