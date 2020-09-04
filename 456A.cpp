#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,price,quality;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> price >> quality;
		if(price != quality){
			cout << "Happy Alex" << endl;
			return 0;
		}
	}
	cout << "Poor Alex" <<endl;
	return 0;
}