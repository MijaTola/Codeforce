#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MIN_INT MIN;
#define MAX_INT MAX;
int main(){
	int n;
	cin >> n;
	string command;
	char ver;
	int x,ans = 0;
	int p1 = -1e9-1,p2 = 1e9+1;
	while(n--){
		cin >> command >> x >> ver;
 		if(command == ">"){ 
 			if(ver == 'Y') p1 = max(p1,x+1); 
 			else p2 = min(p2,x);
 		}
		if(command == "<"){ 
			if(ver == 'Y') p2 = min(p2,x-1); 
			else p1 = max(p1,x);
		}
		if(command == ">="){ 
			if(ver == 'Y') p1 = max(p1,x); 
			else p2 = min(p2,x-1);
		}
		if(command == "<="){ 
			if(ver == 'Y') p2 = min(p2,x); 
			else p1 = max(p1,x+1);
		}
	}
	if(p1 > p2) cout << "Impossible";
	else cout << p1 << endl;
	return 0;
}