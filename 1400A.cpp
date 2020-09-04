#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        for (int i = 0, j = 0; i < n; ++i, j++) {
            cout << s[i + j];
        }
        cout << "\n";
    }
    return 0;
}

