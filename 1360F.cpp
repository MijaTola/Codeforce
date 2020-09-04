#include <bits/stdc++.h>

using namespace std;

int dp[12][1 << 11];

int n,m;
vector<string> v;

int f(int pos, int mask) {
    if(pos == m) return 1;
    int &ans = dp[pos][mask];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < 26; ++i) {
        char c = i + 'a';
        int cur = mask;
        bool flag = 1;
        for (int j = 0; j < n; ++j) {
            if(v[j][pos] != c) {
                if(mask & (1 << j)) flag = 0;
                else cur |= (1 << j);
            }
        }
        
        if(flag)ans |= f(pos + 1, cur);
    }
    return ans;
}

void r(int pos, int mask) {
    if(pos == m) return;
    for (int i = 0; i < 26; ++i) {
        char c = i + 'a';
        int cur = mask;
        bool flag = 1;
        for (int j = 0; j < n; ++j) {
            if(v[j][pos] != c) {
                if(mask & (1 << j)) flag = 0;
                else cur |= (1 << j);
            }
        }
        
        if(flag and f(pos + 1, cur)) {
            cout << c;
            r(pos + 1, cur);
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {

        cin >> n >> m;
    
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < (1 << n); ++j)
                dp[i][j] = -1;
        v.clear();

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            v.push_back(s);
        }
    
        if(!f(0,0)) {
            cout << "-1\n";
            continue;
        }
        
        r(0,0);
        cout << "\n";
    }

    return 0;
}

