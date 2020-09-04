#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n,s,t;
        cin >> n >> s >> t;
        if(s + t > n) {
            if(s == t and s == n) {
                cout << "1\n";
                continue;
            }
            int la = n - s;
            int lb = n - t;
            cout << max(la, lb) + 1 << "\n";
        } else 
            cout << max(s,t) + 1 << "\n";
    }
    return 0;
}

