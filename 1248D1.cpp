#include <bits/stdc++.h>
 
using namespace std;
 
int n;
string s;
int v[510];
 
int check() {
    memset(v, 0,sizeof v);
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') c++;
        else c--;
        v[i] = c;
    }
    
    
    int mn = 1e9;
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] < mn) {
            mn = v[i];
            pos = i;
        }
    }
    string t = "";
 
    for (int i = pos + 1; i < n; ++i)
        t += s[i];
 
    for (int i = 0; i <= pos; ++i)
        t += s[i];
 
    memset(v, 0,sizeof v);
 
    c = 0;
    for (int i = 0; i < n; ++i) {
        if(t[i] == '(') c++;
        else c--;
        v[i] = c;
        if(c < 0) return 0;
    }
    
    if(v[n - 1] != 0) return 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += v[i] == 0;
 
    return ans;
 
 
}
int main() {
    cin >> n >> s;
 
    int ans = check();
    int l = 0, r = 0;
 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            swap(s[i], s[j]);
            int x = check();
            if(x > ans) {
                ans = check();
                l = i, r = j;
            }
            swap(s[i], s[j]);
        }
 
    cout << ans << "\n";
    cout << l + 1 << " " << r + 1 << "\n";
    return 0;
}

