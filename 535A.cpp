#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie();
	string units[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	string dec[10] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	string esp[10] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	
	string x;
	cin >> x;
	string num = "";
	int d = x[0] - 48;
	
	if(x.size() == 1){int u = x[0] - 48; cout << units[u];}
	else{
		int u = x[1] - 48;
		int d = x[0] - 48;
		if(d == 1) cout << esp[u];
		else if(u == 0) cout << dec[d];
		else cout << dec[d] <<"-"<<units[u];
	}
	return 0;
}