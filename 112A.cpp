#include <iostream>
#include <ctype.h>
using namespace std;

int main(){

	string x,y;

	cin >> x >> y;

	for (int i = 0; i < x.size(); ++i)
	{
		x[i] = tolower(x[i]);
		y[i] = tolower(y[i]);
	}

	if(x == y) cout << 0 << endl;
	else if(x > y) cout << 1 << endl;
	else cout << -1 << endl;
	return 0;
}