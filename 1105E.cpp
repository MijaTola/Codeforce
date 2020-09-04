#include <bits/stdc++.h>

using namespace std;

int dp[100010][55];

vector<pair<int, int> > v;
unordered_map<string, int> mp;
int n,m,c;
string s;

int f(int pos, int handle) {
    if(pos == n) return 0;
    int &ans = dp[pos][handle];
    if(ans != -1) return ans;
    ans = 0;
    if(v[pos].first == 1) {
        for (int i = 1; i <= m; ++i) 
            ans = max(ans, f(pos + 1, i));
    } else {
        int p = v[pos].second;
        ans = max(ans, f(pos + 1, handle) + (p == handle));
    }
    return ans;
}

int main() {
    
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if(c == 1) v.push_back(make_pair(1, -1));
        else {
            cin >> s;
            if(!mp.count(s)) mp[s] = cur++;
            int val = mp[s];
            v.push_back(make_pair(2,val));
        }
    }
    
    cout << f(0, 0) << "\n";
    return 0;
}

