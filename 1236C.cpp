#include <bits/stdc++.h>

using namespace std;

vector<int> v[310];

int main() {

    int n;
    cin >> n;
    
    int pos = 0;
    for (int i = 1; i <= n * n; ++i) {
        v[pos].push_back(i);
        pos++;
        pos %= n;
    }

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {
            if(j % 2 == 0) cout << v[i][j] << " ";
            else cout << v[n - i - 1][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

