#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

const int N= 100001;
int in[N];
vector<int> adj[N];

void solve() {
        int n, m; cin >> n>> m;

        for (int i= 0; i< m; i++) {
                int u, v; cin >> u>> v;
                adj[u].push_back(v);
                in[v]++;
        }

        vector<int> prc, ans;
        for (int i= 1; i<= n; i++) if (in[i]== 0) prc.push_back(i);

        while (prc.size()) {
                int x= prc.back();
                ans.push_back(x);
                prc.pop_back();
                for (auto to: adj[x]) {
                        in[to]--;
                        if (!in[to]) prc.push_back(to);
                }
        }

        if (ans.size()!= n) {
                cout << "Cycle\n";
        }else for (int i= 0; i< ans.size(); i++) cout << ans[i]<< " ";

}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
