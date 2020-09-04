#include <iostream>

using namespace std;

bool ver(char x){
	return x == 'a' or x == 'b' or x == 'c' or x == 'd';
}

int main(){
	string x,y; cin >> x >> y;
	
	int ans = 0;
	for(int i = 0; i < x.size(); ++i){
		if(ver(x[i])) if(toupper(x[i]) != y[i]) ans++;
	}
	if (ans >= 3) cout << "Remove" << endl;
	else cout << "Kafo" <<endl;
	return 0;
}
