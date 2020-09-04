#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	vector <int> v;
	stack <int> s;
	int posi = 0;
	int pose = 0;
	bool b = false;
	bool sw = false;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> x; v.push_back(x);
	}

	for (int i = 1; i < n; ++i)
	{
		if(v[i] < v[i-1] and !b){b = true; posi = i-1; pose = i-1;}
		if(v[i] > v[i-1] and b){break;}
		if(b) pose++;
	}
	reverse(v.begin()+posi,v.begin()+pose +1);
 	for (int i = 1; i < n; ++i)
		if(v[i] < v[i-1]){
			cout << "no"; return 0;
		}
	
	cout << "yes" << endl;
	cout << posi +1 << " " << pose +1 ;
	return 0;
}  