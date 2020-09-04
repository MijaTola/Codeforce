#include <bits/stdc++.h>

using namespace std;

int main(){

	int a[500][500];
	int b[500][500];

	int da,db,pa,pb;

	cin >> da >> db;

	for (int i = 100; i < da+100; ++i)
		for (int j = 100; j < db+100; ++j){
			char t;
			cin >> t;
			a[i][j] = t - '0';
		}
			
			
	cin >> pa >> pb;
	for (int i = 100; i < pa+100; ++i)
		for (int j = 100; j < pb+100; ++j){
			char t;
			cin >> t;
			b[i][j] = t - '0';
		}

	int ans = -1;
	int ans1 = 0;
	int ans2 = 0;
	for (int x = -50; x <= 50; ++x)
	{
		for (int y = -50; y <= 50; ++y){
			int sum = 0;
			for (int i = 100; i < da+100; ++i)
				for (int j = 100; j < db+100; ++j)
					sum += a[i][j]*b[i+x][j+y];
			if(sum > ans){
				ans = sum;
				ans1 = x;
				ans2 = y;
			}
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}