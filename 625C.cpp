#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,k;
	cin >> n >> k;
	int m[505][505];
	int c = 1;
	for (int i = 0; i < n; ++i)
		for(int j = 0; j < k-1; ++j){
			m[i][j] = c; c++;
		}
	int sum = 0;
	for (int i = 0; i < n; ++i)
		for (int j = k-1; j < n; j++){
			if(j == k-1) sum += c;
			m[i][j] = c; c++;
		}

	cout << sum << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << m[i][j] << " ";
		cout << endl;
	}
	return 0;
}