#include <bits/stdc++.h>

using namespace std;

int main() {
	c_false;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i] >> a[i] >> b[i];
		for(int d = a[i]; d <= b[i]; d++) {
			if (s[i] == 'M') boy[d]++;
			else girl[d]++;
		}
	}
	for(int i = 1; i < days; i++) {
		if (ans < 2 * min(boy[i], girl[i])) {
			ans = 2 * min(boy[i], girl[i]);
			day = i;
		}
	}
	cout << ans << endl;
	return 0;
}	