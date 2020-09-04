#include <iostream>
#include <set>

using namespace std;
set<char> s;
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		char x; cin >> x;
		s.insert(x);
	}
	if(n > 26) return cout << -1 << endl,0;
	int dif = n-s.size();
	cout << dif << endl;
	return 0;
}
