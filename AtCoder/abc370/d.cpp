#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int H, W, Q;
    std::cin >> H >> W >> Q;

    std::vector g(H, std::vector<int>(W, 1));
    while (Q--) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;

        if (g[x][y] == 1) {
            g[x][y] = 0;
        } else {
            int lo = 0, hi = y - 1;
            while (lo < hi) {
                int m = (lo + hi + 1) >> 1;
                if (g[x][m] == 1) {
                    lo = m;
                } else {
                    hi = m - 1;
                }
            }
            if (g[x][lo] == 1) {
                g[x][lo] = 0;
            }

            lo = std::min(W - 1, y + 1), hi = W - 1;
            while (lo < hi) {
                int m = (lo + hi + 1) >> 1;
                if (g[x][m] == 1) {
                    lo = m;
                } else {
                    hi = m - 1;
                }
            }
            if (g[x][lo] == 1) {
                g[x][lo] = 0;
            }

            lo = 0, hi = x - 1;
            while (lo < hi) {
                int m = (lo + hi + 1) >> 1;
                if (g[m][y] == 1) {
                    lo = m;
                } else {
                    hi = m - 1;
                }
            }
            if (g[lo][y] == 1) {
                g[lo][y] = 0;
            }

            lo = std::min(H - 1, x + 1), hi = H - 1;
            while (lo < hi) {
                int m = (lo + hi + 1) >> 1;
                if (g[m][y] == 1) {
                    lo = m;
                } else {
                    hi = m - 1;
                }
            }
            if (g[lo][y] == 1) {
                g[lo][y] = 0;
            }
        }
    }

    int cnt = 0;
    for (int x = 0; x < H; x++) {
        for(int y = 0; y < W; y++) {
            cnt += g[x][y];
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
