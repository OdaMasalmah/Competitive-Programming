#include <bits/stdc++.h>
using namespace std;

/*
Next array to get first less then me or greater from left or right
*/

const int N = 100001;

int BR[N], BL[N], LR[N], LL[N];

void solve() {
        int n; cin >> n;
        vector<int> v(n);

        for (int i= 0; i< n; i++) cin >> v[i];

        stack<int> st;

        for (int i= 0; i< n; i++) { // first less then me to the left
                while (st.size() > 0 && st.top() >= v[i]) st.pop();
                if (st.size() == 0) LL[i] = -1;
                else { LL[i] = st.top(); }
                st.push(v[i]);
        }
        while (st.size()) st.pop();

        for (int i = n - 1; i >= 0; i--) { // first less then me to the right
                while (st.size() > 0 && st.top() >= v[i]) st.pop();
                if (st.size() == 0) LR[i] = -1;
                else { LR[i] = st.top(); }
                st.push(v[i]);
        }
        while (st.size()) st.pop();

        for (int i= 0; i< n; i++) { // first greater then me to the left
                while (st.size() > 0 && st.top() <= v[i]) st.pop();
                if (st.size() == 0) BL[i] = -1;
                else { BL[i] = st.top(); }
                st.push(v[i]);
        }
        while (st.size()) st.pop();

        for (int i = n - 1; i >= 0; i--) {  // first greater then me to the right
                while (st.size() > 0 && st.top() <= v[i]) st.pop();
                if (st.size() == 0) BR[i] = -1;
                else { BR[i] = st.top(); }
                st.push(v[i]);
        }
        while (st.size()) st.pop();
        //
        for (int i= 0; i< n; i++) cout << LL[i] << " "; // first one less then me to left
        cout << "\n";
        for (int i= 0; i< n; i++) cout << LR[i] << " "; // first one less then me to right
        cout << "\n";
        for (int i= 0; i< n; i++) cout << BL[i] << " "; // first one greater then me to left
        cout << "\n";
        for (int i= 0; i< n; i++) cout << BR[i] << " "; // first one greater then me to Right
        //
}

int main() {
        int t = 1;
        //cin >> t;
        while ( t-- ) {
                solve();
        }
return 0;
}
