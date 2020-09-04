#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &x: v)
        cin >> x;

    if(n <= 3) {
        int i = 0;
        for (; i < n; ++i) {
            cout << i + 1 << " " << i + 1 << "\n";
            if(v[i] > 0) cout << -v[i] << "\n";
            else cout << -v[i] << "\n";
        }
        for (int k = i; k < 3; ++k) {
            cout << "1 " << n << "\n";
            for (int j = 0; j < n; ++j)
                cout << "0 ";
            cout << "\n";
        }
        return 0;
    }

    int sz = 1;

    if(n & 1) sz = 2;

    cout << 1 << " " << n - sz << "\n";
    
    int len = n - sz;

    for (int i = 0; i < n - sz; ++i) {
        int cur = 0;
        while((v[i] + cur) % n != 0) 
            cur += len;
        v[i] += cur;
        cout << cur << " ";
    }

    cout << "\n";
    cout << 1 + sz << " " << n << "\n";

    for (int i = sz; i < n; ++i) {
        int cur = 0;
        while((v[i] + cur) % n != 0) 
            cur += len;
        v[i] += cur;
        cout << cur << " ";
    }

    cout << "\n";
    cout << 1 << " " << n << "\n";
    
    for (int i = 0; i < n; ++i) {
        if(v[i] > 0) cout << -v[i] << " ";
        else cout << -v[i] << " ";
    }
    cout << "\n";

    return 0;
}

