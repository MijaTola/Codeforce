#include <bits/stdc++.h>

using namespace std;

int main(){
	string a = "abcd";
	int n;
	cin >> n;
	while(a.size() < n) a += a;

	for (int i = 0; i < n; ++i)
		cout << a[i];
	return 0;
}