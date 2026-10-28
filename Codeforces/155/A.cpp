#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a[0];
    
    int mn = a[0], mx = a[0];
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        std::cin >> a[i];
        if (a[i] > mx) {
            cnt++;
            mx = a[i];
        } else if (a[i] < mn) {
            cnt++;
            mn = a[i];
        }
    }
    std::cout << cnt << "\n";
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
