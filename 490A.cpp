#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,x;
	vector<int> v[3];
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		v[x-1].push_back(i);
	}
	// cout <<"asdfasdfasf "<<endl;
	int mid = min(v[0].size(),min(v[1].size(),v[2].size()));
	cout << mid << endl;
	for (int i = 0; i < mid; ++i)
		cout << v[0][i]+1 << " " << v[1][i]+1 << " " << v[2][i] +1<< endl; 	
	return 0;
}