#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    
    cin >> t;

    while(t--) {
        vector<string> s(9);

        for (auto &x: s)
            cin >> x;
        
        int r = 0;
        int l = 0;
        while(r < 9) {
            for (int j = l; j < 9; j += 3, r++) {
                char cur = '1';
                while(s[r][j] == cur) cur++;
                s[r][j] = cur;
            }
            l++;
        }

        for (auto x: s)
            cout << x << "\n";


    }
    return 0;
}

