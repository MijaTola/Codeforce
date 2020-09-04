#include <iostream>
#include <set>

using namespace std; 

int main(){
	int n,p,t;
	set<int> players;
	cin >> n;
	cin >> t;
	while(t--){ cin >> p; if(p != 0) players.insert(p);}
	cin >> t;
	while(t--){ cin >> p; if(p != 0) players.insert(p);}
	if(players.size() == n) cout << "I become the guy." << endl;
	else cout << "Oh, my keyboard!" << endl;
	return 0;
}