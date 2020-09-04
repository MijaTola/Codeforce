#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a,b;

        for (int i = 0; i < 2 * n; ++i) {
            int x;
            cin >> x;
            if(x & 1) b.push_back(i + 1);
            else a.push_back(i + 1);
        }
        
        
        if((int)b.size() & 1 or (int)a.size() & 1) {
            a.pop_back();
            b.pop_back();
        } else {
            if((int)a.size() >= 2) {
                a.pop_back();
                a.pop_back();
            } else {
                b.pop_back();
                b.pop_back();
            }
        }

        for (int i = 0; i < (int)a.size(); i += 2)
            cout << a[i] << " " << a[i + 1] << "\n";

        for (int i = 0; i < (int)b.size(); i += 2)
            cout << b[i] << " " << b[i + 1] << "\n";
    }

    return 0;
}

