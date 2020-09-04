#include <bits/stdc++.h>

using namespace std;

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
 
int v[35010];
int dp[35010][55];

void compute(int g, int i, int j, int l, int r) {
    if(i > j) return;
    int mid = (i + j) / 2;
    int bestIndex = l;

    unordered_set<int> s;
    for (int k = min(r,mid) + 1; k <= mid; ++k) 
        s.insert(v[k]);


    for (int k = min(r, mid); k >= l; k--) {
        s.insert(v[k]);
        long long val = dp[k - 1][g - 1] + s.size();
        if(val > dp[mid][g]) {
            dp[mid][g] = val;
            bestIndex = k;
        }
    }
    
    compute(g,i, mid - 1, l, bestIndex);
    compute(g, mid + 1, j, bestIndex, r);
}



int main() {
    int n,k;
    n = in();
    k = in();

    for (int i = 1; i <= n; ++i)
        v[i] = in();

    dp[0][0] = 0;

    for (int i = 1; i <= k; ++i)
        compute(i, 1, n, 1, n);

    printf("%d\n", dp[n][k]);
    return 0;
}

