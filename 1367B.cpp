#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a = 0, b = 0;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(i % 2 != x % 2) {
                if(x & 1) b++;
                else a++;
            }
        }

        if(a != b) cout << "-1\n";
        else cout << a << "\n";
    }
    return 0;
}

