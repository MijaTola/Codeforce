#include <iostream>

using namespace std;

int v[1010];
int main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> v[i];
	
	int ans = 0;
	for (int i = n-1; i >= 0; --i)
		for (int j = i-1; j >= 0; --j)
			if(v[i] < v[j]) ans++;
	cout << ans << endl;
	return 0;
}
