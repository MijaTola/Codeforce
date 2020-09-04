#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x; v.push_back(x);
	}
	for (int i = 1; i < n; ++i)
		for(int j = 0; j <= i; ++j){
			if(i == j) continue;
			int t = v[i] + v[j];
			for(int k = 0; k < n; ++k){
				if(t == v[k]){
					cout << k+1 << " " << i + 1<< " " << j+1;
					return 0;
				}
			}
		}

	cout << -1;
	return 0;
}