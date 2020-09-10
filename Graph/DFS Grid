#include <bits/stdc++.h>
using namespace std;

const int N= 1001;
int n, m;
string str[N];
bool vis[N][N];
int dx[]= {1, -1, 0, 0};
int dy[]= {0, 0, -1, 1};

int DFS(int x, int y) {
        if (x< 0|| x>= n|| y< 0|| y>= m|| vis[x][y]|| str[x][y]== '#') return 0;
        vis[x][y]= 1;
        for (int i= 0; i< 4; i++) {
                int tox= dx[i]+ x;
                int toy= dy[i]+ y;
                DFS(tox, toy);
        }
        return 1;
}

void solve(){
        cin >> n>> m;
        for (int i= 0; i< n; i++) cin >> str[i];

        int an= 0;

        for (int i= 0; i< n; i++)
        for (int j= 0; j< m; j++)
        an+= DFS(i, j);

        cout << an<< "\n";

}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) solve();
return 0;
}
