#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

const int N = 2000001;
int f[N], inv[N];

int fastPower(int a, int b) {
	if (b == 0)
		return 1;
	int res = fastPower(a, b / 2);
	if (b % 2 == 1)
		return ((res* res) % mod* a) % mod;
	return (res* res) % mod;
}

int nCk(int n, int k) {
	return ((f[n] * inv[k]) % mod* inv[n - k]) % mod;
}

void solve() {
	f[0] = 1;
	inv[0] = fastPower(1, mod - 2);
	for (int i = 1; i< N; ++i) {
		f[i] = (i* f[i - 1]) % mod;
		inv[i] = fastPower(f[i], mod - 2);
	}

	int n, m; cin >> n >> m;
	n = n + m - 1;
	cout << nCk(n, m);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
