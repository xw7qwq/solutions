#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

void solve() {
    std::string s;
    std::cin >> s;

    for (auto p : primes) {
        auto t = std::to_string(p);
        if (t.size() == s.size()) {
            bool ok = true;
            for (int i = 0; i < s.size(); i++) {
                for (int j = 0; j < s.size(); j++) {
                    if ((s[i] == s[j] && t[i] == t[j]) || s[i] != s[j] && t[i] != t[j]) {
                        
                    } else {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                std::cout << t << "\n";
                return;
            }
        }
    }
    std::cout << -1 << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(1E7);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
