#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int t;

	cin >> t;
	int total  = 0;
	int sum = 0;
	vector<int> v;
	while(t--){
		int coin;
		cin >> coin;
		sum += coin;
		v.push_back(coin);
	}
	int mid = sum/2;
	int ans = 0;
	int c = 0;
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		ans += v[i];
		c++;
		if(ans > mid) break;
	}

	cout << c << endl;
	return 0;
}