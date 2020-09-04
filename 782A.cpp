#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    
    int n;
    cin >> n;
    
    int c = 0;
    int ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        if(v[x]) {
            v[x]--;
            c--;
        } else v[x]++, c++;
        ans = max(ans, c);
    }
    cout << ans << "\n";
    return 0;
}

