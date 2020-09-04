#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        

        int n;
        cin >> n;
        vector<int> v = {2,3};
        int c[2];
        c[0] = c[1] = 0;

        for (int i = 0; i < 2; ++i) {
            while(n % v[i] == 0) {
                n /= v[i];
                c[i]++;
            }
        }

        if(n != 1 or c[0] > c[1]) {
            cout << "-1\n";
            continue;
        }
        
        cout << c[1] + (c[1] - c[0]) << "\n";
        
    }
    return 0;
}

