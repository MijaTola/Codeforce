#include <iostream>
#include <cstring>

using namespace std;

int male[400];
int female[400];
int v[400];

int main(){

	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i){
		char c;
		int x,y;
		cin >> c >> x >> y;
		if(c == 'M'){
			for (int j = x; j<=y; ++j)
				male[j]++;
		}else{
			for (int j = x; j<=y; ++j)
				female[j]++;
		} 
			
	}
	for (int i = 0; i < 370; ++i)
		ans = max(min(male[i],female[i]),ans);
	cout << ans*2<< endl;
	return 0;
}
