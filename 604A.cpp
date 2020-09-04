#include <bits/stdc++.h>

using namespace std;

int main(){
	double x[5] = {500,1000,1500,2000,2500};
	double m[5];
	double w[5];
	double hs,hu;
	for (int i = 0; i < 5; ++i)
		cin >> m[i];
	for (int i = 0; i < 5; ++i)
		cin >> w[i];
	cin >> hs >> hu;
	double ans = 0;
	for (int i = 0; i < 5; ++i)
	{
		double y = (1-(m[i]/250))*x[i]-50*w[i];
		//cout << y << endl;
		//cout << 1-(m[i]/250) <<endl;
		double best = max(0.3*x[i],y);
		ans += best;
	}
	hs *= 100;
	hu *= 50;
	cout << ans + hs - hu<< endl;
	
	
	return 0;
}