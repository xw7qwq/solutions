#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 0);

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        std::swap(a[x], a[y]);

        for (int j = 0; j < k; j++) {
            std::cout << a[j] << " \n"[j == k - 1];
        }
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
