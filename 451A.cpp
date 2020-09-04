#include <iostream>

using namespace std;

int main(){

	int m,n;

	cin >> m >> n;

	int stick;

	if(m > n) stick = n;
	else stick = m;

	if(stick %2 == 0) cout << "Malvika" << endl;
	else cout << "Akshat" << endl;
	return 0;
}