#include <bits/stdc++.h>

using namespace std;

const int N=50000;
long long a[N], s[N], h[N], ans;
int x,n;
string ss;

int main() {
	cin >> x >> ss;
	n = ss.size();

	for (int i = 0; i < n; i++) {
		a[i + 1] = ss[i] - '0';
		s[i + 1] = s[i] + a[i + 1];
	}
	for (int i = 1;i <= n; i++)
		for (int j = 0; j < i; j++)
			h[s[i] - s[j]]++;

	if (!x) 
        for (int i = 0;i <= s[n]; i++) ans += h[0] * h[i];
	
    for (int i = 1; i <= s[n]; ++i)
		if ((x % i== 0) && (x / i <= s[n]))
			ans += h[i] * h[x/i];

	cout << ans << "\n";
	return 0;
}
