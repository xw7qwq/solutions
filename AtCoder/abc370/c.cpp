#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string S, T;
    std::cin >> S >> T;

    std::vector<std::string> ans;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] > T[i]) {
            S[i] = T[i];
            ans.push_back(S);
        }
    }
    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] < T[i]) {
            S[i] = T[i];
            ans.push_back(S);
        }
    }

    std::cout << ans.size() << "\n";
    for (auto s : ans) {
        std::cout << s << "\n";
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
