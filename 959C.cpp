#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    if(n < 6) cout << "-1\n";
    else {
        cout << "1 2\n";
        for (int i = 3; i <= n; ++i) {
            if(i % 2 == 0) cout << 1 << " " << i << "\n";
            else cout << 2 << " " << i << "\n";
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << i + 1 << " " << i + 2 << "\n";
    }
    return 0;
}

