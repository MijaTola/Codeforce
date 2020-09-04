#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        bool flag= 0;
        for (int i = 0; i < 200; ++i) {
            for (int j = 0; j < 200; ++j) {
                if(3 * i + 7 * j == n) flag = 1;
            }
        }
        if(flag) cout <<"YES\n";
        else cout << "NO\n";
    }
    return 0;
}

