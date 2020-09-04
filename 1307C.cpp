#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> v[30];
long long check[30];
int main() {

    cin >> s;
 

    for (int i = 0; i < (int)s.size(); ++i) {
        v[s[i] - 'a'].push_back(i);
    }

    long long ans = 0;
    
    auto get = [](long long x) {
        return (x * (x - 1)) / 2;
    };

    for (int i = 0; i < 26; ++i) {
        if(!v[i].size()) continue;

        ans = max(ans, get(v[i].size()));
        ans = max(ans, (long long)(v[i].size()));
        if(!v[i].size()) continue;
        memset(check, 0, sizeof check);
        for (int j = 0; j < (int)v[i].size(); ++j) {
            for (int l = 0; l < 26; ++l) {
                if(!v[l].size()) continue;
                
                int pos = upper_bound(v[l].begin(), v[l].end(), v[i][j]) - v[l].begin();
                int tot = v[l].size() - pos;
                check[l] += tot;
               
            }
        }

        for (int j = 0; j < 30; ++j)
            ans = max(ans, check[j]);
    }

    cout << ans << "\n";
    return 0;
}

