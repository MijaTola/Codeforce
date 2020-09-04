#include <iostream>

using namespace std;

int v[1010];
int beg,en;
void print(){
	cout << beg+1 << " " << en+1 <<endl;;
}
int main(){
	int n; cin >> n;
	bool flag = false;
	bool sw = false;
	for (int i = 0; i < n; ++i) cin >> v[i];
	
	int last = -1;
	beg = -1;
	en = n+1;
	bool first = true;
	for (int i = 0; i < n; ++i){
		if(v[i] < last){
			if(sw)	 return cout << 0 << " " << 0 << endl,0;
			if(first){
				beg = i-1;
				first = false;
			}
			if(i+1 == n) en = i;
			flag = true;
		}
		if(v[i] > last and flag){
			en = i-1;
			flag = false;
			sw = true;
		}
		last = v[i];
	}
	if(en == n-1 and v[en] > v[beg-1]) print();
	else if(beg == 0 and v[beg] < v[en+1]) print();
	else if(beg == 0 and en == n-1) print();
	else if(v[beg] < v[en+1] and v[en] > v[beg-1]) print();
	else cout << 0 << " " << 0 << endl; 
	return 0;
}
