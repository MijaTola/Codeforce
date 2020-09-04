#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        long long s,i,e;
        cin >> s >> i >> e;
        
        int a = -1, b = e;

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(s + mid > e + i - mid) b = mid;
            else a = mid;
        }

        if(s + e <= i) cout << "0\n";
        else cout << e - b + 1<< "\n";
    }
    return 0;
}

