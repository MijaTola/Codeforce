#include <iostream>
using namespace std;
int day[2000000];
/*int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= 1000100 ; i++){
		day[i] = 0;
		if ( i % 6 == 0 || i % 7 == 0 )
			day[i] = 1;
	}
	int ans1 = 0, ans2 = 0;
	for ( int i = 1 ; i <= n ; i++ ){
		ans1 += day[i];
	}
	for (int i = 1, c = 1; i <= 1000100 ; i++){
		day[i] = 0;
		if ( c == 1 || c == 2 )
			day[i] = 1;
		c++;
		if( c == 8 ) c = 1;
	}
	for ( int i = 1 ; i <= n ; i++ ){
		ans2 += day[i];
	}
	cout << ans1 << " " << ans2 << endl;
}
*/
