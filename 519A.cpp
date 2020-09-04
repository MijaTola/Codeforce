#include <bits/stdc++.h>

using namespace std;

int main(){
	map<char,int> valuesW;
	map<char,int> valuesB;
	valuesW['Q'] = 9;
	valuesW['R'] = 5;
	valuesW['B'] = 3;
	valuesW['N'] = 3;
	valuesW['P'] = 1;
	valuesW['K'] = 0;
	valuesB['q'] = 9;
	valuesB['r'] = 5;
	valuesB['b'] = 3;
	valuesB['n'] = 3;
	valuesB['p'] = 1;
	valuesB['k'] = 0;
	valuesW['.'] = 0;
	valuesB['.'] = 0;
	char x;
	int black = 0;
	int white = 0;
	for (int i = 0; i < 8; ++i)
		for(int j = 0; j < 8;++j){
			cin >> x;
			black += valuesB[x];
			white += valuesW[x];
		}

	if(black == white) cout << "Draw";
	else if(black < white) cout << "White";
	else cout << "Black";
	return 0;
}