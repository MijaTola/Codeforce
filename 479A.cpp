#include <iostream>

using namespace std;

int main(){
	int a,b,c;

	cin >> a >> b >> c;

	int case1 = a+b*c;
	int case2 = a*(b+c);
	int case3 = a*b*c;
	int case4 = (a+b)*c;
	int case5 = a*b+c;
	int case6 = a +b +c;

	/*cout << case1 << endl;
	cout << case2 << endl;
	cout << case3 << endl;
	cout << case4 << endl;
	cout << case5 << endl;*/	

	int ans = max(case1, case2);
	ans = max(case3,ans);
	ans = max(case4,ans);
	ans = max(case5,ans);
	ans = max(case6,ans);

	cout << ans << endl;
	return 0;
}