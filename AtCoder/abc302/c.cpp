#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> s(N);
    for (int i = 0; i < N; i++) {
        std::cin >> s[i];
    }

    std::vector<int> t(N);
    std::iota(t.begin(), t.end(), 0);
    do {
        bool ok = true;
        for (int i = 0; i + 1 < N; i++) {
            auto x = s[t[i]], y = s[t[i + 1]];
            int cnt = 0;
            for (int j = 0; j < M; j++) {
                if (x[j] != y[j]) {
                    cnt++;
                }
            }
            if (cnt >= 2) {
                ok = false;
                break;
            }
        }

        if (ok) {
            std::cout << "Yes\n";
            return;
        }
    } while (std::next_permutation(t.begin(), t.end()));

    std::cout << "No\n";
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
