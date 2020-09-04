#include <bits/stdc++.h>

using namespace std;

int main(){
	int v[9];
	int total = 0;
	for (int i = 0; i < 9; ++i){
		cin >> v[i];
	}
	
	for (int i = 1; i <= 100000; ++i)
	{
		int sum = v[1] + v[2] + i;
		int vi = sum - v[1] - v[2];
		int vj = sum - v[3] - v[5];
		int vk = sum - v[6] - v[7];
		if(vi + vj + vk == sum){
			v[0] = vi;
			v[4] = vj;
			v[8] = vk;
			break;
		}
	}
	cout << v[0] <<" " << v[1] << " " << v[2] << endl;
	cout << v[3] <<" " << v[4] << " " << v[5] << endl;
	cout << v[6] <<" " << v[7] << " " << v[8] << endl;
	return 0;
}
