#include <iostream>

using namespace std;

int main(){

	int n;
	cin >> n;
	int schooltime = 0;
	bool sw = false;
	int count = 0;
	for (int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x == 1){	
			if(count == 1 && sw){
			 schooltime++;
			}
			count = 0;
			schooltime++;
			sw = true;
		}else if(x == 0){
			count++;
		}
	}
	cout << schooltime << endl;
	return 0;
}