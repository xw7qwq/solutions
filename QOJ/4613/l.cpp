#include <bits/stdc++.h>

#define int long long

using i64 = long long;


void solve() {
	int n, m, q;
	std::cin >> m  >> n >> q;

	std::map<std::string, int> nids;
	int cur = 0;
	auto n1d = [&](std::string s) {
		if (nids.count(s)) {
			return nids[s];
		} else {
			nids[s] = cur;
			return cur++;
		}
	};


	std::vector<int> E(m), S(m);
	std::vector<bool> st(m);

	std::vector nE(n, std::vector<bool>(m)), nS(n, std::vector<bool>(m));

	std::set<char> ans;
	while (q--) {
		std::string name;
		char problem;
		std::string result;
		int time;
		std::cin >> name >> problem >> result >> time;

		if (time >= 240) {
			break;
		}


		int nid = n1d(name), pid = problem - 'A';
		if (result == "AC") {
			if (!nS[nid][pid]) {
				nS[nid][pid] = true;	
				S[pid]++;
				
			}
		}
		if (!nE[nid][pid]) {
			nE[nid][pid] = true;
			E[pid]++;
		}
		
		if ((E[pid] > 0 && 5 * S[pid] >= E[pid]) || S[pid] >= 50) {
			st[pid] = true;
		 } else if (st[pid]) {
			 st[pid] = false;
			 ans.insert('A' + pid);
		 }
	//	std::cout << pid << " " << st[pid] << "\n";
	}

	if (ans.empty()) {
		std::cout << "-\n";
	} else {
		for (auto c : ans) {
			std::cout << c;
		}
		std::cout << "\n";
	}

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
	


