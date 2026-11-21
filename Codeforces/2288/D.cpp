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

    std::vector<int> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }

    std::vector<std::pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = {std::max(pre[i + 1], suf[i]), a[i]};
    }

    std::sort(p.begin(), p.end(), std::greater<>());

    int sum = 0;
    int mn = pre[n];
    for (int i = 0; i < n; i++) {
        mn = std::min({mn, std::max(sum, p[i].first)});
        sum += p[i].second;
    }
    std::cout << mn << "\n";
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
