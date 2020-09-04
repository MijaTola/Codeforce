#include <iostream>

using namespace std;
long long v[20];
int main(){
 v[0]= 1;  
 v[1]= 	 1;
 v[2]= 	 2;
 v[3]= 	 6;
 v[4]= 	 24;
 v[5]= 	 120;
 v[6]= 	 720;
 v[7]= 	 5040;
 v[8]= 	 40320;
 v[9]= 	 362880;
v[10]= 	 3628800;
v[11]= 	 39916800;
v[12]= 	 479001600;
v[13]= 	 6227020800;
v[14]= 	 87178291200;
v[15]= 	 1307674368000;
v[16]= 	 20922789888000;
v[17]= 	 355687428096000;
v[18]= 	 6402373705728000;
v[19]= 	 121645100408832000;
	
	int t;cin >> t;
	while(t--){
		long long x;
		cin >> x;
		bool sw = false;
		for (int i = 0; i < 20; ++i){
			if(v[i]%x == 0) sw = true;
		}
		if(sw) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	return 0;
}
