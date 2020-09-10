#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long
#define mod 1000000007

struct edge{
        int fr, to, c;
        edge() { }
        edge (int aa, int bb, int cc) {
                fr = aa;
                to = bb;
                c = cc;
        }
};

bool cmp(edge a, edge b) {
        return a.c <= b.c;
}

const int N= 100001;
vector<edge> g;

void B_F(int f, int n) {
        int cost[N];
        for (int i= 0; i< N; i++) cost[i] = 1e9;
        cost[f] = 0;
        int last = 0;
        for (int i= 0; i< n; i++) {
                for (auto x: g) {
                        if ((cost[x.fr] + x.c) < cost[x.to]) last = i;
                        cost[x.to] = min(cost[x.fr] + x.c, cost[x.to]);
                }
        }
        if (last == n-1) cout << "NEG Cycle";
        for (int i= 0; i<= n; i++) cout << cost[i] << " ";
}

void solve() {
        int n, m; cin >> n>> m;
        lp(i, m) {
                int u, v, c; cin >> u>> v>> c;
                g.push_back(edge(u, v, c));
                g.push_back(edge(v, u, c));
        }
        B_F(1, n);
        return;
}

int32_t main() {
ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int t = 1;
        //cin >> t;
        while ( t-- ) {
                solve();
        }
return 0;
}
/*
5 7
1 3 3
1 4 7
1 2 5
2 4 3
2 6 2
4 6 2
3 4 1

//
4 5
1 2 3
1 3 5
2 4 1
2 3 2
3 4 -7
*/
