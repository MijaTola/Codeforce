#include <iostream>

using namespace std;

int v[110];
int main(){
	
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	
	int ans = v[m];
	for (int i = m-1, j = m+1; i >= 1 or j <= n; --i,++j){
		bool flag = true;
		if(i >= 1 and v[i] == 0) flag = false;
		if(j <= n and v[j] == 0) flag = false;
		if(flag){
			if(i >= 1) ans += v[i];
			if(j <= n) ans += v[j];
		}
	}
	cout << ans << "\n";
	return 0;
}
