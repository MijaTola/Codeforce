#include <bits/stdc++.h>

using namespace std;

string s;
int n,m,t;
long long val[20];
long long dp[1 << 21];
int needed[20];
map<string, int> mp;
vector<pair<int,int> > v;

long long f(int mask, int pos) {
    if(mask == ((1 << n) - 1)) return 0;
    long long &ans = dp[mask];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < n; ++i) {
        if(mask & (1 << i)) continue;
        if(needed[i] == (needed[i] & mask)) 
            ans = max(ans, f(mask | (1 << i), pos + 1) + val[i] * (pos + 1));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        memset(needed, 0, sizeof needed);
        mp.clear();
        v.clear();
        cin >> n >> m;
        cin.ignore();

        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            string number = "";
            while(s.back() != ' ') {
                number += s.back();
                s.pop_back();
            }
            s.pop_back();
            reverse(number.begin(), number.end());

            int x = 0;
            for (char c: number) 
                x = x * 10 + (int)(c - '0');
            mp[s] = i;
            val[i] = x;
        }

        for (int i = 0; i < m; ++i) {
            getline(cin, s);
            string a = "", b = "";
            int pos = 0;
            while(s[pos] != '-') a += s[pos++];
            a.pop_back();
            while(s[pos] != ' ') pos++;
            pos++;
            while(pos < (int)s.size()) b += s[pos++];
            needed[mp[b]] |= (1 << mp[a]);
        }
        cout << f(0,0) << "\n";
    }
    return 0;
}

