#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

const int N= 300001;
int f[N], mn[N], sz[N], mx[N];

int get(int u) {
        if (u== f[u]) return u;
        else return f[u]= get(f[u]);
}

void union_(int u, int v) {
        int x= get(u);
        int y= get(v);
        if (x== y) return;
        else {
                if (sz[y]> sz[x]) swap(x, y);
                f[y]= x;
                sz[x]+= sz[y];
                mx[x]= max(mx[y], mx[x]);
                mn[x]= min(mn[y], mn[x]);

        }
}

void solve() {
        int n; cin >> n;
        int m; cin >> m;

        for (int i= 0; i<= n; i++) {
                f[i]= i;
                mx[i]= mn[i]= i;
                sz[i]= 1;
        }

        for (int i= 0; i< m; i++) {
                string str; cin>> str;
                if(str[0]== 'u') {
                        int u, v; cin >> u>> v;
                        union_(u, v);
                } else {
                        int x; cin >> x;
                        int an= get(x);
                        cout << mn[an]<< " "<< mx[an]<< " "<< sz[an]<< "\n";
                }
        }
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
