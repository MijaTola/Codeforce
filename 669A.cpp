#include <iostream>

using namespace std;

typedef long long ll;
int main(){
	ll x; cin >> x;
	
	if(x%3LL==0) return cout << x-(x/3) << endl,0;
	if((x+1)%3LL == 0){
		x++;
		return cout << x-(x/3)-1 << endl,0;
	}else if((x-1)%3LL == 0){
		x--;
		return cout << x-(x/3)+1<<endl,0;
	}
	return 0;
}
