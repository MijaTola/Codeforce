#include <bits/stdc++.h>

using namespace std;

int v[300010];
int main() {
    int n;
    string s;
    cin >> n >> s;
    
    long long ans = 0;
    
    vector<int> c;
    c.push_back(0);
    for (int i = 1; i < n; ++i) 
        if(s[i] != s[i - 1]) c.push_back(i);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(c.begin(), c.end(), i) - c.begin();
        if(c[pos] > i) pos--;
        if(i + 1 == n or (s[i] != s[i + 1] and c.size() - pos <= 2)) continue;
        int sz = n - i - 1;
        int r = 0;
        bool flag = pos + 1 < (int)c.size();
        if(s[i] != s[i + 1]) {
            r = c[pos + 2] - c[pos + 1];
            flag = 0;
        }
        ans += sz - flag  - r;
    }
    cout << ans << "\n";
    return 0;
}



