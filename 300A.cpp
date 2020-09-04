#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	int v[100];
	stack<int> f;
	stack<int> s;
	stack<int> t;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if(x < 0) f.push(x);
		else if(x > 0) s.push(x);
		else if(x == 0)t.push(x);
	}
	if(f.size() % 2 == 0){
		t.push(f.top()); f.pop();
	}
	if(s.empty()){
		s.push(f.top()); f.pop();
		s.push(f.top()); f.pop();
	}
	cout << f.size();
	while(!f.empty()){
		cout << " "<<f.top();f.pop();
	}
	cout << endl;
	cout << s.size();
	while(!s.empty()){
		cout << " " << s.top();s.pop();
	}
	cout <<endl;
	cout << t.size();
	while(!t.empty()){
		cout << " "<<t.top();t.pop();
	}
	
	return 0;
}