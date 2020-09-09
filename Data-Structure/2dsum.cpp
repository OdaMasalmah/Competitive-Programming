#include <bits/stdc++.h>
using namespace std;

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

int main(){
        int T= 1;
        cin >> T;
        while ( T-- ) solve();
return 0;
}
