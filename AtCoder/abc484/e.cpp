#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
    int N, L, R;
    std::cin >> N >> L >> R;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> pre(N + 1);
    for (int i = 0; i < N; i++) {
        pre[i + 1] = pre[i] + A[i];
    }

    std::vector<int> alls;
    alls.push_back(0);
    std::vector<std::pair<int, int>> pb(N + 1);
    for (int i = 0; i < N; i++) {
        alls.push_back(pre[i + 1]);
        alls.push_back(pre[i + 1] - L);
        alls.push_back(pre[i + 1] - R);
        pb[i + 1] = {pre[i + 1] - L, pre[i + 1] - R};
    }

    std::sort(alls.begin(), alls.end());
    alls.erase(std::unique(alls.begin(), alls.end()), alls.end());
    for (int i = 0; i < N; i++) {
        A[i] = std::lower_bound(alls.begin(), alls.end(), A[i]) - alls.begin();
    }
    for (int i = 0; i <= N; i++) {
        pre[i] = std::lower_bound(alls.begin(), alls.end(), pre[i]) - alls.begin();
    }
    for (int i = 0; i <= N; i++) {
        pb[i].first = std::lower_bound(alls.begin(), alls.end(), pb[i].first) - alls.begin();
        pb[i].second = std::lower_bound(alls.begin(), alls.end(), pb[i].second) - alls.begin();
    }

    Fenwick<int> fen(alls.size() + 1);
    fen.add(pre[0], 1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += fen.rangeSum(pb[i + 1].second, pb[i + 1].first + 1);
        fen.add(pre[i + 1], 1);
    }

    std::cout << ans << "\n";
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
