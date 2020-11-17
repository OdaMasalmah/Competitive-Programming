#include<bits/stdc++.h>
using namespace std;
using ll= long long;
const int MOD= 1e9+ 7;
const int N= 1e6+ 1;
ll f[N], inv[N];

ll fast_power(ll a, ll b) {
    ll pw= a, an= 1;
    while (b> 0) {
        if (b& 1) {
            an= (pw% MOD* an% MOD)% MOD;
        }
        b>>= 1;
        pw= (pw% MOD* pw% MOD)% MOD;
    }
    return an;
}

ll nCk(int n, int k) {
    return ((f[n]* inv[k])% MOD* inv[n- k]% MOD)% MOD;
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    f[0]= 1;
    inv[0]= 1;
    for (int i= 1; i< N; i++) {
        f[i]= (f[i- 1]* i)% MOD;
        inv[i]= fast_power(f[i], MOD- 2);
    }
    int t; cin >> t; while (t--) {
        int a, b; cin >> a>> b;
        cout << nCk(a, b)<< "\n";
    }
    return 0;
}
