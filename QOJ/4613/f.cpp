#include <bits/stdc++.h>

#define int long long

using i64 = long long;


void solve() {
	int x, y, l, r, v;
	std::cin >> x >> y >> l >> r >> v;

	int pu, qu;
	if (x <= l) {
		if (r <= y) {
			pu = v, qu = 1;
		} else {
			pu = v * (y - l), qu = r - l;
		}
	} else {
		if (r <= y) {
			pu = v * (r - x), qu = r - l;
		} else {
			pu = v * (y - x), qu = r - l;
		}	
	}


	int d = y - x;


	int g = std::gcd(d * qu, pu);
	std::cout << d * qu / g << "/" << pu / g << "\n";

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
	


