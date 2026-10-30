#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());

    std::vector<char> stk;
    while (!s.empty()) {
        auto c = s.back();
        s.pop_back();
        if (!stk.empty() && stk.back() == c) {
            stk.pop_back();
            if (c == 'V') {
                s.push_back('G');
            } else {
                s.push_back('V');
            }
        } else {
            stk.push_back(c);
        }
    }
    std::cout << stk.size() << "\n";
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
