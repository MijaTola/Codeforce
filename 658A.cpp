#include <iostream>

using namespace std;

int main(){
	int n,c;
	cin >> n >> c;
	int v[52];
	int s[52];
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < n; ++i) cin >> s[i];
	
	int limak = 0;
	int t = 0;
	for (int i = 0; i < n; ++i){
		t += s[i];
		int p = max(v[i] - c*t,0);
		limak += p;
 	}
 	t = 0;
 	int fr = 0;
	for (int i = n-1; i >= 0; --i){
		t += s[i];
		int p = max(v[i] - c*t,0);
		fr += p;
	}
	
	if(limak > fr) cout << "Limak" << endl;
	else if (fr > limak)cout << "Radewoosh" << endl;
	else cout << "Tie" << endl;
	return 0;
}
