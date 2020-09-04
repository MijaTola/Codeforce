#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        
        set<int> ans;
        ans.insert(0);
        for (long long i = 1; i * i <= x; ++i) {
            ans.insert(x/i);
            ans.insert(i);
        }

        cout << ans.size()  << "\n";
        for (auto x: ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}

