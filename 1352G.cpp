#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n <= 3) {
            cout << "-1\n";
            continue;
        }
        if(n == 4) {
            cout << "3 1 4 2\n";
            continue;
        }
        int i;
        for (i = 1; i <= n; i += 2)
            cout << i << " ";
            
        i -= 2;
        int ini = i - 3;
        cout << ini << " ";
        for (i = ini + 4; i > ini; i -= 2) {
            if(i <= n and i != ini) cout << i << " ";
        }

        for (i = ini - 2; i >= 1; i -= 2)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

