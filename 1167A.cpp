#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int p = 0;
        while(s[p] != '8' and p < n) p++;
        if(n - p >= 11) puts("YES");
        else puts("NO");
    }
    return 0;
}

