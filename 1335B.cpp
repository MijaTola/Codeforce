#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;

    cin >> t;

    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;
        
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cout << (char)(cur + 'a');
            cur = (cur + 1) % b;
        }
        cout << "\n";
    }
    return 0;
}

