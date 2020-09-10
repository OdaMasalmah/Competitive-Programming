#include <bits/stdc++.h>
using namespace std;

struct node{
        int to, co;
        node(int a, int b) {
                to= a;
                co= b;
        }
        bool operator<(const node& p) const{
                return co> p.co;
        }
};

const int N= 200001;
int n, m;
vector<node> g[N];
int cost[N];

void Dijkstra() {
        for (int i= 0; i< N; i++) cost[i]= 1e9;

        priority_queue<node> pq;
        pq.push(node(1, 0));
        cost[1]= 0;

        while ( pq.size() ) {
                node nd= pq.top();
                pq.pop();

                if (nd.co> cost[nd.to]) continue;

                for (int i= 0; i< (int)g[nd.to].size(); i++) {
                        node ch= g[nd.to][i];
                        if (cost[ch.to]> cost[nd.to] + ch.co) {
                                cost[ch.to]= cost[nd.to]+ ch.co;
                                pq.push(node({ch.to, cost[ch.to]}));
                        }
                }

        }
        for (int i= 1; i<= n; i++) cout << cost[i]<< " ";
}

void solve() {
        cin >> n>> m;

        for (int i= 0; i< m; i++) {
                int u, v, c; cin >> u>> v>> c;
                g[u].push_back(node(v, c));
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
