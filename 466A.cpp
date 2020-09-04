#include <iostream>

using namespace std;

int main(){
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	int ans1 = n*a;
	int ans2 = (n/m)*b + min((n%m)*a,b);
	cout << min(ans1,ans2) << endl;
	return 0;
}