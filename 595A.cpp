#include <iostream>

using namespace std;

int main(){

	int f,m;

	cin >> f >> m;
	int count = 0;
	bool lit = false;
	int ans = 0;
	for (int i = 0; i < f; ++i)
		for (int i = 0; i < 2*m; ++i){
			int x;
			count++;
			cin >> x;
			if(x == 1) lit = true;
			if(count == 2){
				count = 0;
				if(lit) ans++;
				lit = false;
			}	
		}
	cout << ans << endl;
	return 0;
}