#include <iostream>

using namespace std;

int main(){

	int n,t,x,y;

	cin >> n >> x;
	
	int minute = 1;
	int seen = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> t >> y;
		seen += y - t + 1;
		while(x +minute <= t) minute+=x;
		seen += t - minute;
		minute = y+1;
	}
	cout << seen << endl;
	return 0;
}