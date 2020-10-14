#include <bits/stdc++.h>

using namespace std;

int main(){

 
    int t; 
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        
        bool flag = 0;
        for (int n = 1; n == 1 or  n * n - (n / 2) * (n / 2) <= x; ++n) {
            int l = n * n - x;
            if(l < 0) continue;
            int sq = sqrt(l);
            if(sq <= 0) continue;
            
            int k = n / sq;

            if(k > 0 and n * n - (n / k) * (n / k) == x) {
                cout << n << " " << k << "\n";
                flag = 1;
                break;
            }
        }

        if(!flag) cout << "-1\n";
    }
    return 0;
}

