#include <iostream>

using namespace std;

int main(){
	int h[31],g[31];
	int n;
	cin >> n;;
	for (int i = 0; i < n; ++i)
		cin >> h[i] >> g[i];

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if(i != j and h[i] == g[j])
				ans++;
	cout << ans << endl;
	return 0;
}