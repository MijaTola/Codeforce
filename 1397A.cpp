#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        vector<int> a(30,0);
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i){ 
            string s;
            cin >> s;

            for (auto c: s)
                a[c - 'a']++;
        }

        bool flag = 1;
        
        for (int i = 0; i < 30; ++i)
            flag &= a[i] % n == 0;
        
        if(flag) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}

