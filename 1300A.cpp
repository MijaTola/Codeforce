#include <bits/stdc++.h>

using namespace std;

int n;
int v[1010];

int main() {

    int t;
    cin >> t;

    while(t--) {
        cin >> n;
    
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if(v[i] == 0) v[i] = 1, ans++;
            sum += v[i];
        }
    

        while(sum == 0) {
            ans++;
            sum++;
        }
        
        cout << ans << "\n";

        
    }
    return 0;
}

