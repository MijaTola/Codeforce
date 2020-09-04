#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

stack<int> s[100000];
struct cmp{
	bool operator()(const pair<double,int> a, const pair<double,int> b){
		if(a.first == b.first) return a.second >b.second;
		return a.first > b.first;
	}
};
priority_queue<pair<double,int>,vector<pair<double,int> >,cmp > q;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,k; cin >> n >> k;
	for (int i = 1; i <= k; ++i)
		q.push(make_pair(0,i));
	
	for (int i = 0; i < n; ++i){
		int p1; cin >> p1;
		int pos = q.top().second;
		q.pop();
		cout << pos << " ";
		double p2 = 0,p=p1;
		if(!s[pos].empty()){
			p2 = s[pos].top();
			p = (p1+p2)/2;
		}
		s[pos].push(p1);
		int c = s[pos].size();
		double x = p*c;
		q.push(make_pair(x,pos));
	}
	cout << endl;
	return 0;
}
