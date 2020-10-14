#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        cout << "2\n";
     
        if(n == 2) {
            cout << 1 << " " << 2 << "\n";
            continue;
        }

        if(n == 3) {
            cout << 1 << " " << 3 << "\n";
            cout << 2 << " " << 2 << "\n";
            continue;
        }

        if(n == 4) {
            cout << "2 4\n";
            cout << "3 3\n";
            cout << "3 1\n";
            continue;
        }
        vector<int> v;

        for (int i = 1; i <= n; ++i)
            v.push_back(i);

        int a = v.back(); v.pop_back();
        int b = v.back(); v.pop_back();
        int c = v.back(); v.pop_back();
        cout << c << " " << a << "\n";
        cout << b << " " << b << "\n";

        while(v.size() > 0) {
            cout << v.back() << " " << b << "\n";
            b = (v.back() + b) / 2;
            v.pop_back();
        }

        
    }

    return 0;
}

