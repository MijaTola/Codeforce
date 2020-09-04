#include <bits/stdc++.h>

using namespace std;


vector<int> a[30];
int ans[30];
int b[200010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        for (int i = 0; i < 30; ++i) {
            a[i].clear();
            ans[i] = 0;
        }

        int n,m;
        string s;
        cin >> n >> m >> s;

        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            b[i]--;
        }

        for (int i = 0; i < (int)s.size(); ++i) {
            a[s[i] - 'a'].push_back(i);
            ans[s[i] - 'a']++;
        }
        
        
        for (int i = 0; i < m; ++i) {
            int cur = b[i];
            for (int j = 0; j < 30; ++j) {
                if(!a[j].size()) continue;
                int pos = upper_bound(a[j].begin(), a[j].end(), cur) - a[j].begin();
                ans[j] += pos;
            }
        }

        for (int i = 0; i < 26; ++i)
            cout << ans[i] << " ";
        cout << "\n";

    }
    return 0;
}

