#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;
        if(n == 2) {
            cout << "2\n";
            continue;
        }
        int mid = n / 2;
        int m = mid / 2;
        if(m + (mid - m) == n - mid) cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}

