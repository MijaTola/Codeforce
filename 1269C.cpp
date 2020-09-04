#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;
set<int> st;
string ans = "";
int main() {
    cin >> n >> k >> s;
    
    
    for (int i = 0; i < n; ++i)
        ans += s[i % k];
    
    while(ans < s) {
        int p = k - 1;
        while(s[p] == '9') p--;

        for (int i = p; i < n; i += k) 
            ans[i] = (s[p] + 1);
        
        for (int i = 0; i < n; ++i) 
            if((i % k) > p) ans[i] = '0';
    }
    cout << ans.size() << "\n";
    cout << ans << "\n";
    return 0;
}

