#include <bits/stdc++.h>

using namespace std;
long long kbonacci[100];
long long sum[100];
#define pb push_back
int main(){

	int s,k;

	cin >> s >> k;
	kbonacci[0]=1;
	int c= 0;
	for (int i = 1; i <= 50; ++i){
		for (int j = i-1; j >= i-k and j >= 0; --j)
			kbonacci[i] += kbonacci[j];
	}
	vector<long long> ans;
	for (int i = 50; i >= 0; --i)
		if(s - kbonacci[i] >= 0){
			ans.pb(kbonacci[i]);
			s-=kbonacci[i];
		} 

	if(ans.size() == 1) ans.push_back(0);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	return 0;
		
}