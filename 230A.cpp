#include <iostream>
#include <queue>
using namespace std;

struct compare
{
	bool operator() (const pair<int, int> a, const pair<int,int> b){
		if(a.first == b.first) return a.second > b.second;
		else return a.first > b.first;
	}
};
int main(){
	int s,n,x,y;
	ios::sync_with_stdio(false); cin.tie(0);
	priority_queue<pair<int,int>, vector<pair<int,int> >, compare > dragons;
	cin >> s >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		dragons.push(make_pair(x,y));
	}
	while(s > dragons.top().first && !dragons.empty()){
		s += dragons.top().second;
		dragons.pop();
	}

	if(dragons.empty()) cout <<"YES" << endl;
	else cout << "NO" << endl;
	return 0;
}