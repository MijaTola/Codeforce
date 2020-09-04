#include <bits/stdc++.h>

using namespace std;

char c[110][1010];

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,m,x,y;
        cin >> n >> m >> x >> y;

        int cnt = 0;
        vector<int> v;

        for (int i = 0; i < n; ++i) {
            char last = '#';
            int cur = 0;
            for (int j = 0; j < m; ++j) {
                cin >> c[i][j];
                cnt += c[i][j] == '.';
                if(last == c[i][j]) cur++;
                else {
                    if(last == '.') v.push_back(cur);
                    cur = 1;
                }
                last = c[i][j];
            }
            if(last == '.') v.push_back(cur);
        }


        int ans = 0;
        for (auto z: v) {
            int a = (z / 2) * y + (z & 1) * x;
            ans += min(a, z * x);
        }

        cout << ans << "\n";
    }
    return 0;
}

