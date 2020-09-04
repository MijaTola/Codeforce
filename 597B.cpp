#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int ans,n;
	vii data;
	cin >> n;
	int x,y;
	for (int i = 0; i < n; ++i){
		cin >> x >> y;
		data.push_back(ii(y,x));
	}
	sort(data.begin(),data.end());
	ans = 0;
	int toCompare = -1;
	for (int i = 0; i < data.size(); ++i){
		if(data[i].second > toCompare){
			ans++;
			toCompare = data[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}