#include <bits/stdc++.h>

using namespace std;


int main(){
	int n,t;
	cin >> n >> t;
	char x;
	for (int i = 0; i < n; ++i){
			for (int j = 0; j < t; ++j)
			{
				cin >> x;
				if(x == '.'){
					if((i+j)%2 == 0) cout << 'B';
					else cout << 'W';
				}else cout << "-";
			}
			cout << endl;}
	return 0;
}