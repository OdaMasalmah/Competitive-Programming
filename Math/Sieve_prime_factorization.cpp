#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

const int N= 1000001;

vector<int> p;
bitset<10000001> b;

void sieve() {
	b[0] = b[1] = 1;
	for (int i = 2; (i * i) <= N; i++) {
		if (!b[i]) {
			for (int j = i * 2; j <= N; j += i) b[j] = 1;
		}
	}
	for (int i = 2; i <= N; i++) if (!b[i]) p.push_back(i);
}

bool is_prime(int nm) { // last prime is 9999991 up to 14 digit
	if (nm <= N) return !b[nm];
	else {
		for (int i = 0; i < sz(p); i++) {
			if (nm % p[i] == 0) return 0;
		}
		return 1;
	}
}

vector<int> prime_factorization(int nm) {
        vector<int> prf;
	int pf = p[0], c = 0;

	while (pf * pf <= nm) {
                if (nm% pf== 0) prf.push_back(pf);
		while (nm % pf == 0) { nm/= pf; }
		pf = p[++c];
	}

	if (nm > 1) {
		prf.push_back(nm);
	}

	return prf;
}

void solve() {
        int n; cin >> n;
        vector<int> prf= prime_factorization(n);
        if (is_prime(n)) {
                cout << "YES\n";
        } else cout << "NO\n";
        for (int i= 0; i< prf.size(); i++)
                cout << prf[i]<< " ";
        cout << "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;

        sieve();

        cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
