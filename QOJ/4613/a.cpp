#include <bits/stdc++.h>

#define int long long

using i64 = long long;


void solve() {
	int n, s, t;
	std::cin >> n >> s >> t;

	int d = ((s - t) % n + n) % n + 1;
	d = (d) / 2;

	t = (t + d - 1) % n + 1;
	std::cout << t << "\n";	

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
	


