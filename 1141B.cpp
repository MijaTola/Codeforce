#include <bits/stdc++.h>

using namespace std;

int v[200010];
int main() {
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    int c = 0;
    int ans = 0;
    for (int i = 0; i < 3 * n; ++i) {
        if(v[i % n] == 1) c++;
        else  {
            ans = max(ans, c);
            c = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}

