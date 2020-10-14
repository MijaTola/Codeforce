#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        
        int n;
        cin >> n;
        vector<int> v(n);

        for (auto &x: v)
            cin >> x;

        for (int i = n - 1; i >= 0; i--)
            cout << v[i] << " ";
        cout << "\n";
    }

    return 0;
}

