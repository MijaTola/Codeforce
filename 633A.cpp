#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int a,b,c;
	cin >> a >> b >> c;

	for (int i = 0; i < 10000; ++i)
		for (int j = 0; j < 10000; ++j)
			if(i*a + j*b == c) return cout << "Yes",0;
	
	cout << "No";
	return 0;
}