#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<string, int> > S;
	for(int i = 0; i < n; ++i) {
		string X;
		cin >> X;
		
		int s = X.size();
		
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());
		//cout << X <<endl;
		if(X.size() <= 2) {
			S.emplace_back(X, s);
		}
	}
	
	int best = 0;
	for(char a = 'a'; a <= 'z'; ++a) {
	for(char b = a + 1; b <= 'z'; ++b) {
		int my = 0;
		for(const pair<string, int>& X : S) {
			bool ok = true;
			for(char c : X.first) {
			//	cout << X.first << endl;
				if(c != a && c != b) ok = false;
			}
			if(ok) my += X.second;
		}
		best = max(best, my);
	}
	}
	
	cout << best << endl;
	
	return 0;
}