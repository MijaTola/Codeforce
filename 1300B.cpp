#include <bits/stdc++.h>

using namespace std;

int v[300010];
int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < 2 * n; ++i)
            cin >> v[i];

        sort(v, v + 2 * n);
        
        cout << v[n] - v[n - 1] << "\n";
    }
    return 0;
}

