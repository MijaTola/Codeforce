#include <iostream>
#include <map>
using namespace std;

map<string,int> emo;
int main(){
	emo[":)"] = 1;
	emo["(:"] = 1;
	emo[":("] = 2;
	emo["):"] = 2;
	int n; cin >> n;
	string r = "";
	int happy = 0;
	int sad = 0;
	for (int i = 0; i < n; ++i){
		char x; cin >> x;
		r += x;
		if(r.size()==2){
			if(emo[r] == 1) happy++;
			else if(emo[r] == 2) sad++;
			r = x;
		}
	}
	if(happy > sad) cout << "HAPPY" << endl;
	else if(sad > happy) cout << "SAD" << endl;
	else cout << "BORED" << endl;
	return 0;
}
