#include <bits/stdc++.h>

using namespace std;

char c[110][110];
int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if((i + j) & 1) cout << "W";
            else cout << "B";
        }
        cout << "\n";
    }

        

    return 0;
}

