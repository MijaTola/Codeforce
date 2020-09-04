#include <bits/stdc++.h>

using namespace std;

int  v[110];
int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) 
        cin >> v[i];
    

    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        int cost = 0;
        for (int j = 1; j <= n; ++j) {
            int a = abs(i - j);
            int b = abs(j - 1);
            int c = abs(1 - i);
            cost += (a + b + c) * 2 * v[j];
        }
        ans = min(ans, cost);
    }
    cout << ans << "\n";
    return 0;
}

