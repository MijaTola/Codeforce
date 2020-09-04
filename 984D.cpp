#include <bits/stdc++.h>

using namespace std;

int n;
int v[5010];
int dp[5050][5050];
int x[5050][5050];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    for(int j = 1; j <= n; j++) {
		for(int i = 0; i < n - j + 1; i++) {
			int sz = i + j - 1;
			if(i == sz) {
				x[i][sz] = v[i];
				dp[i][sz] = v[i];
			} else {
				x[i][sz] = x[i][sz - 1] ^ x[i + 1][sz];
				dp[i][sz] = max(dp[i][sz - 1], dp[i + 1][sz]);
				dp[i][sz] = max(x[i][sz], dp[i][sz]);
			}
		}
	}
    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        l--,r--;
        cout << dp[l][r] << "\n";
    }
    return 0;
}

