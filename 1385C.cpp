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
        
        auto ver = [&] (int l, int r) {
            int last = -1;

            while(l < r) {
                if(v[l] <= v[r]) {
                    if(last > v[l]) break;
                    last = v[l];
                    l++;
                } else {
                    if(last > v[r]) break;
                    last = v[r];
                    r--;
                }
            }
            if(l >= r) return 1;
            return 0;
        };

        int a = -1, b = n - 1;
        
        while(b - a > 1) {
            int mid = (a + b) / 2;

            if(ver(mid, n - 1)) b = mid;
            else a = mid;
        }

        cout << b << "\n";
    }
    return 0;
}

