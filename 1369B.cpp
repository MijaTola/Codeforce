#include <bits/stdc++.h>

using namespace std;

bool vis[100010];
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int p = 0;
        while(s[p] != '1' and p < n) p++;

        
        int r = n - 1;
        while(s[r] != '0' and r >= 0) r--;

        for (int i = 0; i < p; ++i)
            cout << s[i];
        
        if(p < r) cout << "0";
        for (int i = n - 1; i > r; i--)
            cout << s[i];

        cout << "\n";
        
        
        

    }

    return 0;
}

