#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> v;
        int p = 1;
        while(n > 0) {
            if(p * (n % 10) != 0) {
                v.push_back(p * (n % 10));
            }
            p*= 10;
            n/=10;
        }

        cout << v.size() << "\n";

        for (int x: v)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}

