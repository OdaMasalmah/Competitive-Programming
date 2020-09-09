#include <bits/stdc++.h>
using namespace std;
#define pr(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

const int N= 1001;

int csum[N][N], ar[N][N];

// sum((i, j) (k, l)) where (k, l) is the bottom right 1-based index
int query(int i, int j, int k, int l) {
        return csum[k][l] - csum[k][j-1] - csum[i-1][l] + csum[i-1][j-1];
}

void solve() {
        int n, t; cin >> n>> t;
        vector<int> v(n);
        for (auto& i: v) cin >> i;

        for (int i= 0; i< n; i++) {
                for (int j= 0; j< n; j++) {
                        csum[i+ 1][j+ 1]= v[i]+ v[j];
                }
        }

        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                        csum[i][j] += csum[i][j - 1];
                }
        }
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                        csum[j][i] += csum[j - 1][i];
                }
        }

        int ans= 0;
        for (int i= 1; i<= n; i++) {
                for (int j= 1; j<= n; j++) {

                        for (int k= i, kk= j; k<= n&& kk<= n; k++, kk++) {
                                if (query(i, j, k, kk)== t) {
                                        ans++;
                                }
                        }

                }
        }
        cout << ans<<"\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;
        while ( T-- ) solve();
return 0;
}
