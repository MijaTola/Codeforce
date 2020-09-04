#include <iostream>

using namespace std;

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int gifted[101];
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		gifted[x] = i;
	}

	for (int i = 1; i <= n; ++i)
		cout << gifted[i] << " ";
	return 0;
}