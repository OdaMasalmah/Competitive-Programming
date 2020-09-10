#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

const int N= 1001;
int n, m;
string str[N];
int cost[N][N], path[N][N];
int dx[]= {1, -1, 0, 0};
int dy[]= {0, 0, -1, 1};
char tos[]= {'D', 'U', 'L', 'R'};

bool BFS(int x, int y) {

        for (int i= 0; i<= n; i++)
                for (int j= 0; j<= m; j++) cost[i][j]= 1e9;

        queue<pair<int, int>> q;
        q.push({x, y});
        cost[x][y]= 0;

        while (q.size()) {
                int xx= q.front().first;
                int yy= q.front().second;
                q.pop();

                if (str[xx][yy]== 'B') {
                        return 1;
                }

                for (int i= 0; i< 4; i++) {
                        int tox= xx+ dx[i];
                        int toy= yy+ dy[i];
                        if (tox< 0|| tox>= n|| toy< 0|| toy>= m|| str[tox][toy]== '#'|| cost[tox][toy]!= 1e9) continue;
                        cost[tox][toy]= cost[xx][yy]+ 1;
                        path[tox][toy]= i;
                        q.push({tox, toy});
                }

        }
        return 0;
}

void solve(){
        cin >> n>> m;
        for (int i= 0; i< n; i++) cin >> str[i];

        for (int i= 0; i< n; i++)
        for (int j= 0; j< m; j++)
        if (str[i][j]== 'A') if (BFS(i, j)) {
                cout << "YES\n";
        } else { cout << "NO\n"; return; }

        for (int i= 0; i< n; i++)
        for (int j= 0; j< m; j++)
        if (str[i][j]== 'B') {

                cout << cost[i][j]<< "\n";
                stack<char> st;
                while (cost[i][j]!= 0) {
                        int dir= path[i][j];
                        st.push(tos[dir]);
                        i-= dx[dir];
                        j-= dy[dir];

                }

                while (st.size()) {
                        cout << st.top();
                        st.pop();
                }
                return;
        }

}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) solve();
return 0;
}
