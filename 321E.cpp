#include <bits/stdc++.h>

using namespace std;

int n,k;
int m[4010][4010];
int dp[4010][810];

int cost(int i, int j) {
    return (m[j][j] - m[i - 1][j] - m[j][i - 1] + m[i - 1][i - 1]);
}

void compute(int g, int i, int j, int l, int r) {
    if(i > j) return;
    int mid = (i + j) / 2;
    int bestIndex = l;

    for (int k = l; k <= min(r, mid); ++k) {
        int val = dp[k - 1][g - 1] + cost(k, mid);
        if(val < dp[mid][g]) {
            dp[mid][g] = val;
            bestIndex = k;
        }
    }
    
    compute(g,i, mid - 1, l, bestIndex);
    compute(g, mid + 1, j, bestIndex, r);
}

int in () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

//CF 321E Divide and Conquer Optimization

int main() {

    memset(dp, 30, sizeof dp);
    //O (k * n * log(n))
    n = in();
    k = in();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            m[i][j] = in();
            m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
        }
    
    dp[0][0] = 0;

    for (int i = 1; i <= k; ++i)
        compute(i, 1, n, 1, n);

    printf("%d\n", dp[n][k] / 2);
    return 0;
}

