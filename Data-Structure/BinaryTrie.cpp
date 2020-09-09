#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

/*
WE CAN GET MAX OR MIN XOR between x and several number

This code
add & remove number and remove to the tree
get the min xor with x on the added number and get the index of it

This code solve this problem
https://codeforces.com/problemset/problem/948/D
*/

struct Node{
        int nxt[2];
        int pre, nm; //count how many word and prefix
        Node() {
                memset(nxt, -1, sizeof(nxt));
                pre= 0;
                nm= 0;
        }
};

vector<Node> trie;

void add(const int x, int cnt, int nm) {
        int cur= 0;
        for (int i= 30; i>= 0; i--) {
                int ind= ((x& 1<< i)> 0? 1: 0);
                if (trie[cur].nxt[ind]== -1) {
                        trie[cur].nxt[ind]= trie.size();
                        trie.push_back(Node());
                }
                cur= trie[cur].nxt[ind];
                trie[cur].pre+= cnt;
        }
        trie[cur].nm= nm;
}

pair<int, int> get(const int x) {
        int cur= 0, nm= 0;
        for (int i= 30; i>= 0; i--) {
                int ind= ((x& 1<< i)> 0? 1: 0);
                if (ind== 0) {
                        if (trie[cur].nxt[0]!= -1&& trie[trie[cur].nxt[0]].pre> 0) {
                                cur= trie[cur].nxt[0];
                        } else if (trie[cur].nxt[1]!= -1&& trie[trie[cur].nxt[1]].pre> 0){
                                cur= trie[cur].nxt[1];
                                nm+= 1<< i;
                        } else break;
                } else {
                        if (trie[cur].nxt[1]!= -1&& trie[trie[cur].nxt[1]].pre> 0) {
                                cur= trie[cur].nxt[1];
                        } else if (trie[cur].nxt[0]!= -1&& trie[trie[cur].nxt[0]].pre> 0){
                                cur= trie[cur].nxt[0];
                                nm+= 1<< i;
                        } else break;
                }
        }
        return {nm, trie[cur].nm};
}

void solve() {
        trie.push_back(Node());

        int n; cin >> n;

        vector<int> v(n), vm(n);
        for (int i= 0; i< n; i++) {
                cin >> v[i];
        }

        for (int i= 0; i< n; i++) {
                cin >> vm[i];
                add(vm[i], 1, i);
        }

        for (int i= 0; i< n; i++) {
                pair<int, int> res= get(v[i]);
                cout << res.first<<" ";
                add(vm[res.second], -1, res.second);
        }

}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) solve();
return 0;
}
