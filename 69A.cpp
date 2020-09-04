#include <iostream>

using namespace std;

int main(){
	int n;

	cin >> n;
	int x,z,y,x1 = 0,y1 = 0,z1= 0;
	while(n--){
		cin >> x >> y >> z;
		x1 += x;
		y1 += y;
		z1 += z;
 		//sum += ans;
	}	

	if(x1== 0 and y1== 0 and z1== 0) cout <<"YES" << endl;
	else cout << "NO" << endl;
	return 0;
}