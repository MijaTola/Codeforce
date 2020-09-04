#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        set<int> s,c;

        for (int &x: v)
            cin >> x;

        sort(v.rbegin(), v.rend());

        for (int x: v)
            cout << x << " ";
        cout << "\n";

    }
    return 0;
}

