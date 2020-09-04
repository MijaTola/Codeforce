#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
	ll n, a, b, c, ans;
int main()
{

	cin >> n >> a >> b >> c;
	if (n < a && n<b)
	{
		cout << 0;
		return 0;
	}
	if (a <= b - c)
	{
		cout << n/a;
		return 0;
	}
	if (n >= b)
	{
		n -= b;
		ans += n / (b - c);
		n %= (b-c);
		n += b;
	}
	while (n >= b) ans++, n-=b-c;
	ans += max(n/a, n/b);
	cout << ans;
	return 0;
}