#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

/*      in your solution
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
*/

int main() {
	ifstream Mary1,Mary2;
	Mary1.open("C:\\Users\\lenovo\\Desktop\\Desktop\\test_Masalmah\\out.txt", ios::binary); // output for test solution
	Mary2.open("C:\\Users\\lenovo\\Desktop\\Desktop\\test_Masalmah\\out2.txt", ios::binary); // output for Brute solution

//---------- compare two files line by line ------------------//
	char string1[256], string2[256];
	int j = 0;
	bool ok= 1;

	while(!Mary1.eof()) {

		Mary1.getline(string1,256);
		Mary2.getline(string2,256);
		j++;

		if(strcmp(string1,string2) != 0) {
			cout << j << "-the strings are not equal" << "\n";
			cout << "Your solution " << string1 << "\n";
			cout << "Brute solution " << string2 << "\n";
			ok= 0;
		}

	}

        if (ok) puts("Fine");

return 0;
}
