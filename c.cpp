#include <bits/stdc++.h>

using namespace std;

int n, t;
string s;

int dp[200010];
int can[200010];

int main() {

    cin >> n >> t >> s;
    
    n = s.size();
    int p = 0;
    vector<int> v;

    while(s[p] != '.' and p < n) p++;


    for (int i = 0; i < n; ++i) {
        if(s[i] == '.') continue;
        else v.push_back(s[i] - '0');
    }
    
    int sz = v.size();

    can[sz - 1] = v.back() >= 5;
    dp[sz - 1] = v.back() >= 5 ? 0 : 1e9;

    int id = sz - 1;
    for (int i = sz - 2; i >= p - 1; i--) {
        if(can[i + 1]) {
            if(v[i] >= 5 and i > p - 1) dp[i] = 0, can[i] = 1;
            else {
                dp[i] = dp[i + 1] + 1;
                if(v[i] + 1 >= 5) {
                    can[i] = 1;
                }
            }
            
            if(dp[i] <= t) {
                id = i;
            }
        } else if(v[i] >= 5) can[i] = 1, dp[i] = 0;
        else dp[i] = 1e9;
        
    }

    
    if(id == sz) return cout << s << "\n", 0;
    int lim = id;
    while(id >= 0 and id < sz - 1) {
        v[id]++;
        if(v[id] == 10) {
            v[id] = 0;
            id--;
        } else break;
    }
    string ans = "";
    int f = 0;
    for (int i = 0; i <= lim; ++i) {
        if(p == i) {
            ans += ".";
            f = 1;
        }
        ans += (char)(v[i] + '0');
    }

    while(ans.size() and ans.back() == '0' and f) ans.pop_back();
    if(ans.size() and ans.back() == '.') ans.pop_back();
    if(ans[0] == '0' and (int)v.size() > 1 and id == -1) ans = "1" + ans;
    cout << ans << "\n";
    return 0;
}

