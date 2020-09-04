#include <iostream>

using namespace std;

int main(){
	freopen("holes.in","r",stdin);
	freopen("holes.out","w",stdout);
	int n;
	cin >> n;
	if(n == 0) return cout << 1 << endl,0;
	if(n == 1) return cout << 0 << endl,0;
	if(n&1){
		n--;
		cout << 4;
		for (int i = 0; i < n/2; ++i){
			cout << 8;
		}
		cout << endl;
	}else {
		for (int i =0; i < n/2; ++i){
			cout << 8;
		} 
		cout << endl;
	}
	return 0;
}
