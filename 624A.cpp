#include <bits/stdc++.h>

using namespace std;

int main(){

	double l,d,v1,v2;
	cin >> d >> l >> v1 >> v2;
	cout.precision(6);
	cout << fixed <<  (l-d)/(v1+v2) << endl;
	return 0;
}