#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) { cin >> a; a--; }

		vector<int> last_idx(N, -1);
		vector<int> prv_occ(N);
		for (int i = 0; i < N; i++) {
			prv_occ[i] = last_idx[A[i]];
			last_idx[A[i]] = i;
		}
		vector<int> dp(N+1);
		dp[0] = 0;
		for (int i = 0; i < N; i++) {
			// we can delete this guy
			dp[i+1] = dp[i] + 1;
			if (prv_occ[i] != -1) {
				dp[i+1] = min(dp[i+1], dp[prv_occ[i]] + (i - prv_occ[i] - 1));
			}
		}
		cout << dp[N] << '\n';	
	}

	return 0;
}

