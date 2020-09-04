#include <iostream>

using namespace std;

int main(){

	int x,y,z;

	cin >> x >> y >> z;

	if(x == 0 || y == 0 || z == 0){
		cout << 0 << endl;
		return 0;
	}
	int sum = 0;
	int case1 = x + y + z;
	int case2 = 2*x + 2*y;
	int case3 = 2*x + 2*z;
	int case4 = 2*y + 2*z;
	int ans = min(case1,case2);
	ans = min(ans,case3);
	ans = min(ans,case4);
	cout << ans << endl;
	return 0;
}