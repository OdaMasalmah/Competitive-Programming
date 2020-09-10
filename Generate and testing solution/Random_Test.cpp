#include <bits/stdc++.h>
using namespace std;
/*
Generate test cases
*/
int rand(int a, int b) {
        return a+ rand()% (b- a+ 1);
}

int main() {

        freopen("C:\\Users\\lenovo\\Desktop\\Desktop\\test_Masalmah\\in.txt", "w", stdout); // output file

        srand(time(0));

        int T= 100;
        cout << T<< "\n";

        while ( T-- ) {
                int n= rand(2, 50);

                cout << n<< "\n";
                for (int i = 0; i< n; i++) {
                        int x= rand(1, 10);
                        cout << x% 2 << " \n"[i== n-1];
                }

        }
return 0;
}
