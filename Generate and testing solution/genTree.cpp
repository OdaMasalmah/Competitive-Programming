#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
/*
Generate test cases
*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll= long long;

struct timer {
    unsigned long long begin_cycle;
    double get_time() { return 1.0* (clock()- begin_cycle)/ CLOCKS_PER_SEC; }
    void init() { begin_cycle= clock(); }
} timer;

ll rand(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

int main(int argc, char* argv[]) {
//    freopen("C:\\Users\\lenovo\\Desktop\\Desktop\\testM\\in.txt", "w", stdout);
    int N = rand(1, 100);
    printf("%d\n", N);
    for (int tt = 0; tt < N; tt ++) {
        for (int II = 0; II < 2; II++) {
            int n = rand(1, 10); //atoi(argv[1]);
            int t = rand(-1000, 1000); //atoi(argv[2]);

            vector<int> p(n);

            /* setup parents for vertices 1..n-1 */
            for(int i = 0; i < n; ++i)
                if (i > 0)
                    p[i] = rnd.wnext(i, t);

            printf("%d\n", n);

            /* shuffle vertices 1..n-1 */
            vector<int> perm(n);
            for(int i = 0; i < n; ++i)
                perm[i] = i;
            shuffle(perm.begin() + 1, perm.end());

            /* put edges considering shuffled vertices */
            vector<pair<int,int> > edges;
            for (int i = 1; i < n; i++)
                if (rnd.next(2))
                    edges.push_back(make_pair(perm[i], perm[p[i]]));
                else
                    edges.push_back(make_pair(perm[p[i]], perm[i]));

            /* shuffle edges */
            shuffle(edges.begin(), edges.end());

            for (int i = 0; i + 1 < n; i++)
                printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
        }
    }
return 0;
}
