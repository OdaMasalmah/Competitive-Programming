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

const int N= 300011;
const int logN= 20;

int dp[N][logN], depth[N];
vector<int> adj[N];

void dfs(int u, int pa) {
        dp[u][0]= pa;
        for (auto x: adj[u]) {
                if (x== pa) continue;

                depth[x]= depth[u]+ 1;
                dfs(x, u);
        }
}

int lca(int a, int b) {
        if (depth[a]< depth[b]) swap(a, b);

        for (int i= logN- 1; i>= 0; i--) { // put it in the same depth
                if ((depth[a]- (1<< i))>= depth[b]) {
                        a= dp[a][i];
                }
        }

        if (a== b) return a; // in the same V

        for (int i= logN- 1; i>= 0; i--) { // jump to get the node before lca
                if (dp[a][i]!= dp[b][i]) {
                        a= dp[a][i];
                        b= dp[b][i];
                }
        }
        return dp[a][0];
}

int up(int u, int d) { // jump d steps from the u
        if (depth[u]< d) {
                return -1;
        }

        for (int i= logN- 1; i>= 0; i--) { // make a jump
                if (d- (1<< i)>= 0) {
                        u= dp[u][i];
                        d-= (1<< i);
                }
        }

        return u;
}

int lenght(int a, int b) { // length between two node
        int l= lca(a, b);
        return (depth[a]- depth[l]+ depth[b]- depth[l]);
}

void solve(){
        int n, q; cin >> n>> q;
        for (int i= 0; i< n- 1; i++) {
                int u, v; cin >> u>> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        function<void()> precal= [&]()->void{
                memset(dp, -1, sizeof(dp));
                dfs(1, -1);

                for (int k= 1; k< logN; k++) {
                        for (int i= 1; i<= n; i++) {
                                if (dp[i][k- 1]== -1) continue;
                                dp[i][k]= dp[dp[i][k- 1]][k- 1]; // fill parent of i to all power of two
                        }
                }
                return;
        };

        precal();

        while (q--) {
                int a, b; cin >> a>> b;
                cout << lenght(a, b)<< "\n";
        }

}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) solve();
return 0;
}