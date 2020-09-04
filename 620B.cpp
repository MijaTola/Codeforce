#include <bits/stdc++.h>

using namespace std;

string convert(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}
int main(){
	int x, y;
	cin >> x >> y;
	int v[10] = {6,2,5,5,4,5,6,3,7,6};
	int ans = 0;
	for (int i = x; i <= y; ++i)
	{
	    int t = i;
   		while (t > 0) {
    	ans += v[t % 10];
    	t /= 10;
   		 }
	}
	cout << ans;
	return 0;
}