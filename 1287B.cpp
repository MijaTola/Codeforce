#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    map<string,int> mp;
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        mp[s]++;
        v.push_back(s);
    }


    auto check = [] (char x, char y) {
        if(x == 'S' and y == 'T') return 'E';
        if(x == 'S' and y == 'E') return 'T';
        if(x == 'E' and y == 'T') return 'S';
        if(x == 'E' and y == 'E') return 'E';
        if(x == 'S' and y == 'S') return 'S';
        if(x == 'T' and y == 'T') return 'T';
        return '*';
    };
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string cur = "";
            for (int l = 0; l < k; ++l) {
                char x = check(v[i][l], v[j][l]);
                if(x == '*') x = check(v[j][l], v[i][l]);
                cur += x;
            }
            if(cur == v[i] and cur == v[j]) {
                ans += mp[cur] - 2;
            } else ans += mp[cur];
        }
    }
    cout << ans/ 3<< "\n";
    return 0;
}

