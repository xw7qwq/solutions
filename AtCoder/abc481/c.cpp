#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int Q;
    std::cin >> Q;

    std::map<std::string, int> id;
    int cur = 1;
    for (int i = 0; i < Q; i++) {
        std::string s;
        std::cin >> s;
        if (!id.contains(s)) {
            id[s] = cur++;
        } 
        std::cout << id[s] << "\n";
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
