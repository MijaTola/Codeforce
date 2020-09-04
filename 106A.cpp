#include <bits/stdc++.h>

using namespace std;

int main(){

	map<char,int> v;
	v['2'] = 2;
	v['3'] = 3;
	v['4'] = 4;
	v['5'] = 5;
	v['6'] = 6;
	v['7'] = 7;
	v['8'] = 8;
	v['9'] = 9;
	v['T'] = 10;
	v['J'] = 11;
	v['Q'] = 12;
	v['K'] = 13;
		v['A'] = 14;
	char winner,suit1,suit2;
	char number1, number2;
	int n1,n2;
	cin >> winner >> number1 >> suit1 >> number2 >> suit2;
	n1 = v[number1];
	n2 = v[number2];
	if(winner == suit1 and winner != suit2){cout <<"YES"; return 0;}
	if(winner == suit1 and winner == suit2) {if(n1 > n2) cout << "YES";else cout << "NO"; return 0;}
	if(suit1 == suit2 and n1 > n2) {cout << "YES"; return 0;}
	
	cout << "NO";

	return 0;
}