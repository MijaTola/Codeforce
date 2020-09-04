#include <iostream>

using namespace std;

int main(){
	int x; 
	cin >> x;
	if(x >= 0){
		cout << x <<endl;
		return 0;
	}

	int ans1 = x/10;
	int aux = x%10;
	int ans2 = ans1/10;
	ans2 = ans2*10+aux;
	cout << max(ans1,ans2) << endl;
	return 0;
}