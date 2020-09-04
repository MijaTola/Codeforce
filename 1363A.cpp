#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,z;
        cin >> n >> z;
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x & 1) a++;
            else b++;
        }
        
        bool flag = 0;
        for (int i = 1; i <= a; ++i) {
            for (int j = 0; j <= b; ++j) {
                if(i & 1 and i + j == z and i) {
                    flag = 1;
                }
            }
        }

        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

