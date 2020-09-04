#include <iostream>
using namespace std;

int main(){

	int n,d;
	int songtime = 0;
	cin >> n >> d;
	for (int i = 0; i < n; ++i){
		int x;
		cin >> x;
		songtime += x;
	}
	if(songtime+(n-1)*10 > d){
		cout << -1 << endl;
		return 0;
	}
	cout << (d - songtime)/5<<endl;
	return 0;
}