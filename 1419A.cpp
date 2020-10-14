#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n;
        string s;
        cin >> n >> s;

        bool a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            int val = s[i] - '0';
            if(i % 2 == 0) {
                a |= val % 2 != 0;
            } else {
                b |= val % 2 == 0;
            }
        }
        
        if(n & 1) {
            if(a) cout << "1\n";
            else cout << "2\n";
        } else {
            if(b) cout << "2\n";
            else cout << "1\n";
        }
    }
    return 0;
}

