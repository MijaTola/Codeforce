#include <iostream>

using namespace std;
int r[100010];
int c[100010];
int colors[100010];
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	colors[0] = 0;
	for (int i = 1; i <= k; ++i){
		int t,x; cin >> t >> x >> colors[i];
		if(t == 1){
			r[--x] = i;
		}else c[--x] = i;
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			cout << colors[max(r[i],c[j])] << " ";
		cout << "\n";
	}
	return 0;
}
