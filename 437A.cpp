#include <bits/stdc++.h>

using namespace std;

int main(){
	int sz[4];
	string x;
	for (int i = 0; i < 4; ++i)
	{
		cin >> x;
		sz[i] = x.size()-2;
	}

	int ver = 0; int ans;
	for (int i = 0; i < 4; ++i)
	{
		 int a = 0; int b = 0;
		 for(int j = 0; j < 4; ++j){
		 	if(i==j) continue;
		 	if(sz[i]*2<= sz[j]) a++;
		 	if(sz[i] >= sz[j]*2) b++;
		 }
		 if(a == 3 || b == 3){
		 	ver++;
		 	ans = i;
		 }
	}
	if(ver == 1) cout << (char)('A'+ans);
	else cout << "C";
	return 0;
}