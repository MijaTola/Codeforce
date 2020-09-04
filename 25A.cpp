#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,x;
	vector<int> v[2];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		if(x%2 == 0) v[0].push_back(i);
		else v[1].push_back(i);	
	}


	if(v[0].size() == 1) cout << v[0][0] +1<< endl;
	else if(v[1].size() == 1) cout << v[1][0]+1 << endl;
	return 0;
}