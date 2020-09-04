#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	string x,aux;
	cin >> x;
	string maxi = "0"; 
	bool sw = false;
	int pos = -1;
	for (int i = 0; i < x.size(); ++i)
	{
		aux = x;
		int y = x[i] - 48;
		if(y % 2 == 0){
			 if(x[i] < x[x.size()-1]){
			 	swap(x[i],x[x.size()-1]);
			 	cout << x; return 0;
			 }
			 pos = i;
		}
	}
	if(pos == -1) cout << -1;
	else{
		swap(x[pos],x[x.size()-1]);
		cout << x;
	}
	return 0;
}