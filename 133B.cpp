#include <bits/stdc++.h>

using namespace std;

int main(){
	map<char,int> unary;
	unary['>'] = 8;
	unary['<'] = 9;
	unary['+'] = 10;
	unary['-'] = 11;
	unary['.'] = 12;
	unary[','] = 13;
	unary['['] = 14;
	unary[']'] = 15;
	string x;
	cin >> x;
	int ans = 0;
	for (int i = 0; i < x.size(); ++i){
		ans *= 16;
		ans += unary[x[i]];
		ans %= 1000003;
	}

	cout << ans;

	return 0;
}