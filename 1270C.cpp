#include <bits/stdc++.h>

using namespace std;

int v[200010];
int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        long long sum = 0;
        long long xo = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
            xo ^= v[i];
        }
        cout << "2\n";
        cout << xo << " " << sum + xo << "\n";
    }
        

    return 0;
}

