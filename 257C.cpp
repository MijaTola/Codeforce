#include <bits/stdc++.h>

using namespace std;
 
const double PI = acos(-1.);
const double eps = 1e-9;
 
double dist(double alpha, double beta) {
	double ans = beta - alpha;
	if (ans < 0) {
		ans += 2 * PI;
	}
	return ans;
}
 
int main() {
	
	vector<double> angles;
 
	int n;
	cin >> n;
 
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		angles.push_back(atan2(y, x));
	}
 
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
 
	sort(angles.begin(), angles.end());
 
	if ( fabs(angles[0] - angles[n-1]) < eps) {
		cout << 0 << endl;
		return 0;
	}
 
	double ans = 0.;
 
	for (int i = 0; i < n-1; ++i) {
		ans = max(ans, dist(angles[i], angles[i+1]));
	}
	ans = max(ans, dist(angles[n-1], angles[0]));
 
	cout << fixed << setprecision(12) << 360 - ans / PI * 180 << endl;
 
 
	return 0;
}
