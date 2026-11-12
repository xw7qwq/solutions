#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(a.begin(), a.end());

    if (a[0].first == a[1].first) {
        std::cout << a.back().second + 1 << "\n";
    } else {
        std::cout << a[0].second  + 1<< "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
