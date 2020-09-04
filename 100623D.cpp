#include <bits/stdc++.h>

using namespace std;

long long a[1000011];
long long b[1000011];
int n,m;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("deposits.in","r",stdin);
	freopen("deposits.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b[x]++;
    }

    long long ans = 0;
    for (int i = 1; i <= 1000010; ++i) {
        if(b[i] == 0) continue;
        for (int j = i; j <= 1000010; j += i) {
            ans += b[i] * a[j];
        }
    }
    cout << ans << "\n";
	return 0;
}
