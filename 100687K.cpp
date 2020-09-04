#include <iostream>

using namespace std;

char m[20][40];

int main(){
	int x,y;
	int fx,fy;
	for (int i = 0; i < 16; ++i){
		for (int j = 0; j < 32; ++j){
			cin >> m[i][j];
			if(m[i][j] == ':'){
			  x = i; y = j;
			}
		}
	}
	//cout << x << " " << y <<endl;
	string s; cin >> s;
	for (int i = 0; i < s.size(); ++i){
		if(s[i] == '^') x--;
		if(s[i] == 'v') x++;
		if(s[i] == '<') y--;
		if(s[i] == '>') y++;
	}
	//cout << x << " " << y << endl;
	if(m[x][y] == 'E') cout << "Yes" <<endl;
	else cout << "No" << endl;
	
	return 0;
}
