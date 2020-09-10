#include <bits/stdc++.h>
using namespace std;

struct edge{
        int to, co;
        edge(int a, int b) {
                to= a;
                co= b;
        }
        bool operator<(const edge& p) const{
                return co> p.co;
        }
};

const int N= 200001;
int n, m;
vector<edge> g[N];
int cost[N];

void Dijkstra() {
        for (int i= 0; i< N; i++) cost[i]= 1e9;

        priority_queue<edge> pq;
        pq.push(edge(1, 0));
        cost[1]= 0;

        while ( pq.size() ) {
                edge nd= pq.top();
                pq.pop();

                if (nd.co> cost[nd.to]) continue;

                for (int i= 0; i< (int)g[nd.to].size(); i++) {
                        edge ch= g[nd.to][i];
                        if (cost[ch.to]> cost[nd.to] + ch.co) {
                                cost[ch.to]= cost[nd.to]+ ch.co;
                                pq.push(edge({ch.to, cost[ch.to]}));
                        }
                }

        }
        for (int i= 1; i<= n; i++) cout << cost[i]<< " ";
}

void solve() {
        cin >> n>> m;

        for (int i= 0; i< m; i++) {
                int u, v, c; cin >> u>> v>> c;
                g[u].push_back(edge(v, c));
        }

        Dijkstra();
}

int main() {
ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int t= 1;
        //cin >> t;
        while ( t-- ) {
                solve();
        }
return 0;
}
