#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        long long a = -1, b = 1e5;
        
        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(mid * (mid - 1) / 2 > n) b = mid;
            else a = mid;
        }
        b--;
        cout << 1;
        for (int i = 0; i < b - 2; i++)
            cout << 3;
        
        int left = n - ( (b * (b - 1)) / 2 );
        for (int i = 0; i < left; ++i)
            cout << 1;
        cout << "337\n";
    }
    return 0;
}

