#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int x;
    std::cin >> x;

    int u = x / 97;
    if (((x % 97) + 24) / 25 > u) {
        std::cout << "No\n";
        return;
    }
    std::cout << "Yes\n";
    for (int i = 0; i < u; i++) {
        if (i + 1 < ((x % 97) + 24) / 25) {
            std::cout << 'z';
        } else if (i + 1 == ((x % 97) + 24) / 25) {
            std::cout << (char)((((x % 97 / 25 == (((x % 97) + 24) / 25))) ? 25 : (x % 97 % 25)) + 'a');
        } else {
            std::cout << 'a';
        }
    }
    std::cout << "\n";

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
