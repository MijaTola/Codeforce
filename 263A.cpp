#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){


	int x,y,t;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> t;
			if(t == 1)x = i,y = j;
		}
	}
	x = abs(x - 2);
	y = abs(y - 2);
	cout << x + y << endl;
	return 0;
}