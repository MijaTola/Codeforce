#include <iostream>

using namespace std;

int main(){
	string x; cin >> x;
	bool flag = true;
	for (int i = 0; i < x.size(); ++i){
		if (x[i] == '?'){
			flag = false; break;
		}	
	}
	if(!flag) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}

