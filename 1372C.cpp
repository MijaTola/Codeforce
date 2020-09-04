#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        int cnt = 0;

        for (int i = 1; i <= n ;++i) {
            int x;
            cin >> x;
            if(x == i) cnt++;
        }

        if(cnt == n) cout << "0\n";
        else if(cnt == 0) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}

