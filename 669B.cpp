#include <iostream>

using namespace std;
long long v[100000];
int main(){
	int n;
	string x;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) cin >> v[i];
	int pos = 0;
	bool sw = true;
	while(true){
		if(x[pos] == '<'){
			int p = pos;
			pos -= v[pos];
			v[p] = 0;
		}else{
			int p = pos;
			pos += v[pos];
			v[p] = 0;
		}
		//cout << pos << endl;
		if(pos >= n or pos < 0) return cout << "FINITE" << endl,0;
		if(v[pos] == 0)return cout << "INFINITE" << endl,0;
	}
	return 0;
}
