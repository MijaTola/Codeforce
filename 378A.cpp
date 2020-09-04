#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b;

	cin >> a >> b;

	int winA = 0;
	int winB = 0;
	int draw = 0;
	for (int i = 1; i <= 6; ++i)
	{
		int difA = abs(a - i);
		int difB = abs(b - i);

		if(difA < difB) winA++;
		else if(difA > difB) winB++;
		else draw++;
	}

	cout << winA << " " << draw << " " <<  winB << endl;
	return 0;
}