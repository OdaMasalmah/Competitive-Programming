#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define int long long
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

typedef int item;

struct segtree{ // zero indexing

        int size;
        vector<item> arr;

        const item NU= INT_MIN; //value don't change the function 0 for sum, INT_MAX for min ...

        item single(int val) { // what is in the leaf of the tree
                return val;
        }

        item merge_(item a, item b) {
                return max(a, b);
        }

        void init(int n) {
                size= 1;
                while (size< n) size*= 2;
                arr.resize(2* size);
        }

        void build(vector<int> &v, int x, int l, int r) {
                if (r- l== 1) {
                        if (l< (int)v.size())
                                arr[x]= single(v[l]);
                        return;
                }
                int md= (l+ r)/ 2;
                build(v, x* 2+ 1, l, md);
                build(v, x* 2+ 2, md, r);
                arr[x]= merge_(arr[x* 2+ 1], arr[x* 2+ 2]);
        }

        void build(vector<int> &v) {
                build(v, 0, 0, size);
        }

        void set(int idx, int val, int x, int l, int r) {
                if (r- l== 1) {
                        arr[x]= single(val);
                        return;
                }
                int md= (l+ r)/ 2;
                if (idx>= md) {
                        set(idx, val, x* 2+ 2, md, r);
                } else
                        set(idx, val, x* 2+ 1, l, md);
                arr[x]= merge_(arr[x* 2+ 1], arr[x* 2+ 2]);
        }

        void set(int idx, int val) {
                set(idx, val, 0, 0, size);
        }

        item calc(int gl, int gr, int x, int l, int r) {
                if (l>= gr|| r<= gl) return NU;
                if (l>= gl&& r<= gr) return arr[x];
                int md= (l+ r)/ 2;
                item an1= calc(gl, gr, x* 2+ 2, md, r);
                item an2= calc(gl, gr, x* 2+ 1, l, md);
                return merge_(an1, an2);
        }

        item calc(int l, int r) { // from l to r- 1
                return calc(l, r, 0, 0, size);
        }

        int first_above(int gl, int gr, int val, int x, int l, int r) {
                if (l>= gr|| r<= gl) return -1;
                if (arr[x]< val) return -1;
                if (r- l== 1) return l;
                int md= (l+ r)/ 2;
                int an= first_above(gl, gr, val, x* 2+ 1, l, md);
                if (an== -1) {
                        an= first_above(gl, gr, val, x* 2+ 2, md, r);
                }
                return an;
        }

        int first_above(int x, int l, int r) {
                return first_above(l, r, x, 0, 0, size);
        }
};

void solve() {
        int n, q; cin >> n>> q;

        vector<int> v(n);
        for(int i= 0; i< n; i++) cin >> v[i];

        segtree st;
        st.init(n);
        st.build(v);

        while (q--) {
                int x; cin >> x;
                int pos= st.first_above(x, 0, n);
                cout << (pos== -1? 0: pos+ 1)<< " ";
                if (pos!= -1) {
                        st.set(pos, v[pos]- x);
                        v[pos]= v[pos]- x;
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
