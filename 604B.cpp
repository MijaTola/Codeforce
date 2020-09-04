#include <bits/stdc++.h>

using namespace std;

int v[200010];
int n,k;
int main(){
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int total = 2 * k;
    int free = total - n;

    int a = 0, b = n - free - 1;
    int ans = v[n - 1];
    while(a < b) {
        ans = max(ans, v[a] + v[b]);
        a++,b--;
    }

    cout << ans << "\n";
	return 0;
}
