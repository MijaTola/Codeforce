#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n,mid;
	string x;
	cin >> n;
	cin >> x;
	mid = n/2;
	//LLRLLL
	for (int i = 0; i < mid; ++i)
	{
		if(x[i] == 'R' and x[i+mid] == 'L')
			cout << i+mid+1 << " " << i+1 << endl;
		else cout << i + 1 << " " << i+mid+1<<endl; 
	}
	return 0;
}