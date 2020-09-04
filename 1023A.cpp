#include <bits/stdc++.h>

using namespace std;

string s,t;
int main(){
    int n,m; 
    cin >> n >> m;
    cin >> s >> t;
    
    bool f = 0;
    for (int i = 0; i < n; ++i) 
        if(s[i] == '*') f = 1;
    
    if(!f) {
        if(s == t) cout << "YES\n";
        else cout << "NO\n";
        return 0;
    }
    int l = 0, i = 0;
    for (i = 0; i < n and i < m; ++i) {
        if(s[i] == '*' or s[i] != t[l]) break;
        l++;
    }
    l--;
    int j = m - 1;
    int r = n - 1;
    for (r = n - 1; r >= 0 and j >= 0; --r, j--) {
        if(s[r] == '*' or s[r] != t[j]) break;
    }
    j++;
    
    if(l < j and s[i] == '*' and s[r] == '*') cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

