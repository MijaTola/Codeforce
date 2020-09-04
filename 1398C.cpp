#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        int sum = 0;
        vector<int> v;

        for (int i = 0; i < n; ++i) {
            sum += (s[i] - '0');
            v.push_back(sum);
        }
        
        map<int,vector<int> > mp;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            int cur = i + 1;
            mp[v[i] - cur].push_back(i);
            b[i] = v[i] - cur;
        }

        
        int last = 0;
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int r = v[i] - last;
            int df = r - 1;
            int cur = b[i] - df;
            const vector<int> &c = mp[cur];
            
            //cout << s[i] << " " << last << " " << v[i] << "\n";
            int pos = lower_bound(c.begin(), c.end(), i) - c.begin();
            ans += c.size() - pos;
            last = v[i];
        }

        cout << ans << "\n";
    }
    return 0;
}

