#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string convert(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}
int main(){
	int pos = 1;
	string s = "0";
	while(s.size()< 1010){
		s += convert(pos); pos++;
	}
	int n; cin >> n;
	cout << s[n]<<endl;
	return 0;
}
