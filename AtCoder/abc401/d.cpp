#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    for (int i = 0; i < N; i++) {
        if (S[i] == '?') {
            if (i - 1 >= 0 && S[i - 1] == 'o') {
                S[i] = '.';
            } else if (i + 1 < N && S[i + 1] == 'o') {
                S[i] = '.';
            }
        }
    }

    std::vector<std::pair<int, int>> v;
    int cost = 0;
    for (int l = 0; l < N; ) {
        while (l < N && S[l] != '?') {
            l++;
        }
        if (l >= N) {
            break;
        }

        int r = l + 1;
        while (r < N && S[r] == '?') {
            r++;
        }
        v.push_back({l, r - 1});
        cost += (r - l + 1) / 2;
        l = r;
    }

    K -= std::count(S.begin(), S.end(), 'o');

    if (K == 0) {
        for (int i = 0; i < N; i++) {
            if (S[i] == '?') {
                S[i] = '.';
            }
        }
        std::cout << S << "\n";
        return;
    }

    if (cost > K) {

    } else {
        for (int l = 0; l < N; ) {
            while (l < N && S[l] != '?') {
                l++;
            }
            if (l >= N) {
                break;
            }

            int r = l + 1;
            while (r < N && S[r] == '?') {
                r++;
            }
            
            if ((r - l) % 2 == 1) {
                for (int i = l; i < r; i++) {
                    if ((i - l) % 2 == 0) {
                        S[i] = 'o';
                    } else {
                        S[i] = '.';
                    }
                }
            }
            l = r;
        }   
    }
    std::cout << S << "\n";
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
