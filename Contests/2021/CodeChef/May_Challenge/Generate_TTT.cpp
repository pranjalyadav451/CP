#include<bits/stdc++.h>
using namespace std;

void print_ttt(string &str) {
	cout << str[0] << str[1] << str[2] << endl;
	cout << str[3] << str[4] << str[5] << endl;
	cout << str[6] << str[7] << str[8] << endl;
	cout << endl;

}

void generate_ttt(int count , string &str) {

	if (count == 9) {
		print_ttt(str);
		return;
	}
	string str1 = str + ('X'), str2 = str + ('O'), str3 = str + ('_');
	generate_ttt(count + 1, str2 );
	generate_ttt(count + 1, str1 );
	generate_ttt(count + 1, str3 );

}

int main() {
	clock_t begin = clock();
	string str;
	generate_ttt(0, str);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}