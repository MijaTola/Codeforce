#include <iostream>
#include <algorithm>

using namespace std;

int da[3];
int dx[3];
int main(){
	int a,b,c,x,y,z;
	int ft,st;
	bool flag1 = false;
	bool flag2 = false;
	cin >> da[0] >> da[1] >> da[2];
	a = da[0]; b = da[1]; c = da[2];
	if(a*a + b*b == c*c or b*b +c*c == a*a or a*a + c*c == b*b)
		flag1 = true;
		
	cin >> dx[0] >> dx[1] >> dx[2];
	x = dx[0]; y = dx[1]; z = dx[2];
	if(x*x + y*y == z*z or y*y +z*z == x*x or x*x + z*z == y*y)
		flag2 = true;
	if(flag1 and flag2){
		sort(da,da+3);
		sort(dx,dx+3);
		bool found = true;
		for(int i = 0; i < 3; ++i){
			if(da[i] != dx[i]){
				found = false; break;
			}
		}
		if(found) return cout << "YES" << endl,0;
	}
	cout << "NO" << endl;
	return 0;
}
