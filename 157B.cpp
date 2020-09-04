#include <bits/stdc++.h>

using namespace std;

const double pi = 3.14159265358979323846;
int main(){
	double n,x;
	vector<double> v;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	
	double ans = 0;
	for (int i = v.size()-1; i >= 0; --i){
		double areat = pi*v[i]*v[i];
		if(i&1) ans-= areat;
		else ans += areat;
	}
	cout << setprecision(5) << fixed ;
	cout << abs(ans);
	return 0;
}