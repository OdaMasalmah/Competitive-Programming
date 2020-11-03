#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 998244353

using ll= long long;
const int N= 1005;
const int inf= 1e9+ 9;

int dx[]= {1, -1, 0, 0};
int dy[]= {0, 0, 1, -1};

int r, c;
char arr[N][N];

void bfs() {
        vector<vector<int>> dist(N, vector<int> (N, inf));
        vector<vector<int>> vis(N, vector<int> (N, 0));
        deque<pair<int, int>> dq;

        auto add= [&](int x, int y, bool b) {
                if (b) dq.push_back({x, y});
                else dq.push_front({x, y});
        };


        add(0, 0, 0);
        dist[0][0]= 0;

        while (dq.size()) {
                int x= dq.front().first, y= dq.front().second;
                dq.pop_front();
                if (vis[x][y]) continue;
                vis[x][y]= 1;

                for (int i= 0; i< 4; i++) {
                        int tox= x+ dx[i];
                        int toy= y+ dy[i];
                        if (tox>= 0&& tox< r&& toy>= 0&& toy< c&& !vis[tox][toy]) {
                                if ((arr[tox][toy]== arr[x][y])&& dist[tox][toy]> dist[x][y]) {
                                        add(tox, toy, 0);
                                        dist[tox][toy]= dist[x][y];
                                } else if ((arr[tox][toy]!= arr[x][y])&&dist[tox][toy]> dist[x][y]+ 1){
                                        add(tox, toy, 1);
                                        dist[tox][toy]= dist[x][y]+ 1;
                                }
                        }
                }
        }

//        for (int i= 0; i< r; i++) {
//                for (int j= 0; j< c; j++) {
//                        cout<< (dist[i][j]== inf? -1: dist[i][j])<< " ";
//                }
//                cout << "\n";
//        }
        cout << "\n";
        cout << dist[r- 1][c- 1]<< "\n";
}

void solve() {
        cin >> r>> c;

        for (int i= 0; i< r; i++) {
                for (int j= 0; j< c; j++) {
                        cin >> arr[i][j];
                }
        }

        bfs();
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;
        while ( T-- ) solve();
        return 0;
}
