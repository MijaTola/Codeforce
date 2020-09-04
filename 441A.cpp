#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int n,p,x;
	cin >> n >> p;
	vector<int> v;
	for (int i = 1; i <= n; ++i)
	{
		bool sw = false;
		cin >> x;
		for (int j = 0; j < x; ++j)
		{
			int t;
			cin >> t;
			if(!sw){
				if(t<p){
					v.push_back(i);
					sw = true;
				}
			}
		}
	}
	sort(v.begin(),v.end());
	cout << v.size() << endl;
	if(v.size() != 0) cout << v[0];
	for (int i = 1; i < (int)v.size(); ++i)
		cout << " "<< v[i];
	return 0;
}
