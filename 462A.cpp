#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

char map[105][105];
int sum[105][105];
int n;
int main() {
	cin >> n;
	for(int i=1;i<=n;i++) cin >> map[i]+1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		if(map[i][j]=='o') {
			sum[i-1][j]++;
			sum[i+1][j]++;
			sum[i][j-1]++;
			sum[i][j+1]++;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		if((sum[i][j]%2)==1) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}