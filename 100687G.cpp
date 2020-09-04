#include <iostream>
#include <algorithm>

using namespace std;

int v[60];
int main(){
	int n; cin >> n;
	double media = 0;
	for (int i = 0; i < n;++i){
		int x,y; cin >> x >> y;
		int dif = abs(x-y);
		v[i] = dif;
		media += dif;
	}
	media /= n;
	double ans = 0;
	for (int i = 0; i < n; ++i){
		double dif = v[i] - media;
		if(dif < 0) dif *= -1.0;
		ans += dif;	
	}
	cout << ans << endl;
	return 0;
}
