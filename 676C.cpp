#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;
int dal[100010];
int dar[100010];
int dbl[100010];
int dbr[100010];
vector<int> a,b;
set<int> st;
int main() {
    cin >> n >> k >> s;
    
    for (int i = 0; i < n; ++i) {
        st.insert(s[i]);
        if(s[i] == 'a') dal[i] = dar[i] = 1, a.push_back(i);
        else dbl[i] = dbr[i] = 1, b.push_back(i);
    }
    if(st.size() == 1) return cout << n << "\n",0;
    
    int c = 0;
    int cb = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'a') c++;
        else c = 0;
        dal[i] = c;
        if(s[i] == 'b') cb++;
        else cb = 0;
        dbl[i] = cb;
    }
    c = cb = 0;
    for (int i = n - 1; i >= 0; i--) {
        if(s[i] == 'a') c++;
        else c = 0;
        dar[i] = c;
        if(s[i] == 'b') cb++;
        else cb = 0;
        dbr[i] = cb;
    }
    int ans = k;
    if(k == 0) {
        for (int i = 0; i < n; ++i) 
            ans = max(ans, max(dal[i], dbl[i]));
        
        cout << ans << "\n";
        return 0;
    }
    for (int i = 0; i < (int)a.size(); ++i) {
        int l = i;
        int r = min((int)a.size() - 1, i + k - 1);
        int total = a[r] - a[l] + 1;
        ans = max(ans, total + dbl[a[l] - 1] + dbr[a[r] + 1]);
    }
    for (int i = 0; i < (int)b.size(); ++i) {
        int l = i;
        int r = min((int)b.size() - 1, i + k - 1);
        int total = b[r] - b[l] + 1;
        ans = max(ans, total + dal[b[l] - 1] + dar[b[r] + 1]);
    }
    cout << ans << "\n";
    return 0;
}

