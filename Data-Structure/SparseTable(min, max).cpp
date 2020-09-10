#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

const int N= 200011;
const int K= 25;
int Log[N], dp[N][K];

void solve() {
        int n, k; cin >> n>> k;

        vector<int> v(n);
        for (auto& i: v) cin>> i;

        for (int i= 0; i< n; i++) {
                dp[i][0]= v[i];
        }

        for (int i= 1; i< K; i++) {
                for (int j= 0; j< n; j++) {
                        if (j+ (1<< (i- 1))< n)
                                dp[j][i]= min(dp[j][i- 1], dp[j+ (1<< (i- 1))][i- 1]);
                }
        }

        while (k--) {
                int a, b; cin >> a>> b;
                a--, b--;

                int l= Log[b- a+ 1];
                cout << min(dp[a][l], dp[b- (1<< l)+ 1][l])<< "\n";
        }
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;

        Log[1]= 0;
        for (int i= 2; i< N; i++) Log[i]= Log[i/ 2] + 1;

        while ( T-- ) {
                solve();
        }
return 0;
}
