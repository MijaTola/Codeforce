#include <bits/stdc++.h>

using namespace std;

int main(){
	string mode[10];
	mode[0] = "O-|-OOOO";
	mode[1] = "O-|O-OOO";
	mode[2] = "O-|OO-OO";
	mode[3] = "O-|OOO-O";
	mode[4] = "O-|OOOO-";
	mode[5] = "-O|-OOOO";
	mode[6] = "-O|O-OOO";
	mode[7] = "-O|OO-OO";
	mode[8] = "-O|OOO-O";
	mode[9] = "-O|OOOO-";
	string x;
	cin >> x;
	for (int i = x.size()-1; i >= 0; --i){
		int t = x[i] - 48;
		cout << mode[t] << endl;
	}	
	return 0;
	
}