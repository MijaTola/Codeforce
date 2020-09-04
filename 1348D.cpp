#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<long long> ans;
        long long cur = 1;
        while(cur <= n) {
            n -= cur;
            ans.push_back(cur);
            cur <<= 1ll;
        }
        if(n) ans.push_back(n);

        sort(ans.begin(), ans.end());

        cout << ans.size() - 1 << "\n";

        for (int i = 1; i < (int)ans.size(); ++i) {
            cout << ans[i] - ans[i - 1] << " ";
        }
        cout << "\n";
    }
    return 0;
}
