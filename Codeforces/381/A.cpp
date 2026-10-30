#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int l = 0, r = n - 1;
    int cur = 0;
    std::vector<int> sum(2);
    while (l <= r) {
        if (a[l] > a[r]) {
            sum[cur] += a[l];
            l++;
        } else {
            sum[cur] += a[r];
            r--;
        }
        cur ^= 1;
    }
    std::cout << sum[0] << " " << sum[1] << "\n";
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
