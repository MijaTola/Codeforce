#include <bits/stdc++.h>

using namespace std;

string s;
int n,k;

vector<int> v[30];
vector<int> cnt[30];

int main() {
    cin >> n >> k >> s;

            
    for (int i = 0; i < n; ++i) {
        v[s[i] - 'a'].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 27; ++i) {
        if(v[i].size() == 0) continue;
        int c = 1;
        int last = 0;
        int sz = v[i].size();

        for (int j = 0; j < sz; ++j) {
            if(v[i][j] + 1 == v[i][j + 1]) c++;
            else {
                cnt[i].push_back(c);
                c = 1;
            }
        }
        int total = 0;
        for (int x: cnt[i]) 
            total += (x / k);
        
        ans = max(ans, total);
    }
    cout << ans << "\n";
    return 0;
}

