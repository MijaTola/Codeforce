#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x; 
	cin >> n;
	int c25 = 0;
	int c50 = 0;
	for (int i = 0; i < n; ++i)
 	{
		cin >> x;
		if(x == 25) c25++;
		else if(x == 50){
			if(!c25){
				cout << "NO";
				return 0;
			}
			c25--; c50++;
		}else if(x == 100){
			if(!c25 or (!c50 and c25 < 3))
			{
				cout << "NO";
				return 0;
			}
			if(!c50) c25 -= 3;
			else c25--, c50--;
		}
	}
	cout << "YES";
	return 0;
}