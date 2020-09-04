#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;
        vector<int> v(n);

        for (int &x: v)
            cin >> x;
        
        if(v[0] + v[1] <= v.back()) {
            cout << 1 << " " << 2 << " " << v.size() << "\n";
        } else cout << "-1\n";

        //a + b > c
        //a + c > b
        //b + c > a
    }
    return 0;
}

