#include <bits/stdc++.h>

using namespace std;

int main(){

	double a,b,c,d;
	cin >> a >> b >> c >> d;

	double x = a/b; double y = c/d;

	cout.precision(9);
	cout << fixed << x/(1-(1-x)*(1-y));
	return 0;
}