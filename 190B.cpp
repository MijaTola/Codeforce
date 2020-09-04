#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double a,b,c,x,y,w;

	cin >> a >> b >> c >> x >> y >> w;

	double d = sqrt((x-a)*(x-a)+(y-b)*(y-b) );
	
	cout.precision(10);
	
	if(d <= abs(w-c)) cout << (abs(c-w)-d)/2.0 << endl;
	else if(d >= w+c) cout << (d-w-c)/2.0;
	else cout << 0 << endl;
	return 0;
}
