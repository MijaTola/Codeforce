#include <bits/stdc++.h>

using namespace std;

int main(){

	int r1,r2,c1,c2,d1,d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	set<int> p;
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			for (int k = 1; k < 10; ++k)
				for (int l = 1; l < 10; ++l){
					p.clear();
					p.insert(i);
					p.insert(j);
					p.insert(k);
					p.insert(l);
					if(p.size() != 4) continue;
					if(i + j != r1) continue;
					if(i + k != c1) continue;
					if(i + l != d1) continue;
					if(j + k != d2) continue;
					if(j + l != c2) continue;
					if(k + l != r2) continue;
					cout << i << " " << j << endl;
					cout << k  << " " << l << endl;
					return 0;
				}
				cout << -1;
	return 0;
}