#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i].first >> p[i].second;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int a = p[i].first - p[j].first, b = p[i].second - p[j].second;
                int c = p[k].first - p[j].first, d = p[k].second - p[j].second;
                cnt += (a * d - b * c) != 0;
            }
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
