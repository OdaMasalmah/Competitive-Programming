#include <bits/stdc++.h>
using namespace std;
/*
Generate test cases
*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main() {

        freopen("C:\\Users\\lenovo\\Desktop\\Desktop\\test_Masalmah\\in.txt", "w", stdout);

        int T= 10;
        while (T--) {
                int n= rand(1, 10);
                cout << n<< "\n";
        }
return 0;
}
