#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, a1, a2, b1, b2, c1, c2;
cin >> n >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	int a, b, c;
	a = min(n, min(a2, n - b1 - c1));
	n -= a;
	b = min(n, min(b2, n - c1));
	n -= b;
	c = n;
	cout << a << " " << b << " " << c << endl;
	return 0;
}