#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;

int main() {

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> k >> s;
        vector<int> v(n + 10, 0);
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') cnt++;
            else cnt = 0;
            v[i] = cnt;
        }

        cnt = 0;
        int cur = k + 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i] == '1') cur = 0;
            else {
                if(cur >= k and (v[i + 1] >= k or  i + v[i + 1] == n - 1)) {
                    cur = 0;
                    ans++;
                } else cur++;
            }
        }

        cout << ans << "\n";
        
    }

    return 0;
}

