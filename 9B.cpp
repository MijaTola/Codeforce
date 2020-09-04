#include <iostream>
#include <cmath>
using namespace std;
double v[110];
double x,y;
const double eps = 1e-9;
double ans = 1e9;
int main(){
	double n,vs,vb;
	cin >> n >> vb >> vs;
	for (int i = 1; i <= n; ++i) cin >> v[i];	
	cin >> x >> y;
	double best,b;
	int id = 1;
	for (int i = 1; i <= n; ++i){
		double t2 = sqrt((v[i]-x)*(v[i]-x) + y*y);
		double t1 = (double)v[i]/vb + (double)t2/vs;
		if((t1 < ans or t1 - ans < eps) and v[i] != 0){
			ans = t1;
			id = i;
		}
	}
	cout << id << endl;
	return 0;
}
//v = d/t;
//v/d = 1/t;
// t = d/v;
