#include <iostream>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
	int n,m; cin >> n >> m;
	double ma = 0,mb = 0;
	for (int i = 0; i < n-1; ++i){
		int x; cin >> x;
		ma += x;
	}
	for (int i = 0; i < m; ++i){
		int x; cin >> x;
		mb += x;
	}
	double mda = ma/(n-1);
	double mdb = mb / m;
	int ans1 = -1; int ans2 = 1e6;
	for (int i = 1; i < 100; ++i){
		double maa = ma+i/n;
		double mbb = mb+i/m+1;
	}
	}
	return 0;
}
