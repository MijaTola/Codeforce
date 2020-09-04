#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int chest = 0;
	int bicep = 0;
	int back = 0;
	int sw = 1;
	int x;
	for (int i = 0; i < n; ++i)
	{	
		cin >> x;
		switch(sw){
			case 1:
				chest += x;
				sw = 2;
				break;
			case 2:
				bicep += x;
				sw = 3;
				break;
			case 3:
				back += x;
				sw = 1;
				break;
		}
	}

	int ans = max(chest,max(back,bicep));
	if(ans == chest) cout << "chest" << endl;
	else if(ans == bicep) cout << "biceps" << endl;
	else if(ans == back) cout <<"back" << endl;
	return 0;
}