#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	int n; cin >> n;
	bool fist = true;
	stack <int> s;
	vector <pair<int,int> > ans;
	for (int i = 0; i < 2*n; ++i){
		string c; int x;
		cin >> c >> x;
		if(c == "in"){
			if(!s.empty())
				ans.push_back(make_pair(s.top(),x));
			s.push(x);
		}else{
			s.pop();
		}
	}
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].first << " " << ans[i].second << endl;
	
	return 0;
}
