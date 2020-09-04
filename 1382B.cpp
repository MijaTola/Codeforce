#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
    
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        int win = 1;
        for (int i = n - 2; i >= 0; i--) {
            if(win) {
                if(v[i] > 1) win = 1;
                else win = 0;
            } else {
                win = 1;
            }
        }

        if(win) cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}

