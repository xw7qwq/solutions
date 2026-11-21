#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            s.push_back('+');
        } else {
            s += "--+";
        }
    }
    std::cout << s << std::endl;

    int k;
    std::cin >> k;

    std::cout << n + (k + 2) / 3 << std::endl;
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
