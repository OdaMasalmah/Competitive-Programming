// range query update point (add(v[i]), update(delta))-> first code
// range update point query (add(delate), update(v[i]))-> second code
const int N= 2e5+ 10;

int y[N];

// x[i] += d start from 1
void add(int i, int d) {
        for (; i < N; i += i&(-i)) {
                y[i] += d;
        }
}

// return x[1] + x[2] + ... + x[i]
int sum(int i) {
        int ans = 0;
        for (; i > 0; i -= i&(-i)) {
                ans += y[i];
        }
        return ans;
}

int query(int x, int y) {
        return sum(y)- sum(x- 1);
}

void update(int pos, int to, int cur) {
        add(pos, to- cur);
}

void solve() {
        int n, q; cin >> n>> q;
        vector<int> v(n); for (auto& i: v) cin >> i;

        for (int i= 0; i< n; i++) add(i+ 1, v[i]);

        while ( q-- ) {
                int w, a, b; cin >> w>> a>> b;
                if (w== 2) cout << query(a, b)<< "\n";
                else {
                        update(a, b, v[a- 1]);
                        v[a- 1]= b;
                }
        }
}

// This Range qyeary update 

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
 
const int N= 2e5+ 10;
 
int y[N];
 
// x[i] += d start from 1
void add(int i, int d) {
        for (; i < N; i += i&(-i)) {
                y[i] += d;
        }
}
 
// return x[1] + x[2] + ... + x[i]
int sum(int i) {
        int ans = 0;
        for (; i > 0; i -= i&(-i)) {
                ans += y[i];
        }
        return ans;
}
 
int query(int x, int y) {
        return sum(y)- sum(x- 1);
}
 
void update(int pos, int to, int cur) {
        add(pos, to- cur);
}
 
void range_add(int l, int r, int val) {
        add(l, val);
        add(r+ 1, -val);
}
 
void solve() {
        int n, q; cin >> n>> q;
        vector<int> v(n); for (auto& i: v) cin >> i;
 
        int cur= 0;
        for (int i= 0; i< n; i++) { add(i+ 1, v[i]- cur); cur= v[i]; }
 
        while ( q-- ) {
                int k; cin >> k;
                if (k== 2) {
                        int kk; cin >> kk;
                        cout << sum(kk)<< "\n";
                } else {
                        int l, r, val; cin >> l>> r>> val;
                        range_add(l, r, val);
                }
        }
}
 
int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) solve();
return 0;
}
