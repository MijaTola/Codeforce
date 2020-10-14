#include <bits/stdc++.h>

using namespace std;

int v[110][3];
int ans[110];
int main() {

    int t;

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n + 5; ++i)
            v[i][0] = v[i][1] = v[i][2] = -1;

        for (int i = 0; i < n; ++i)
            cin >> v[i][0];

        for (int i = 0; i < n; ++i)
            cin >> v[i][1];

        for (int i = 0; i < n; ++i)
            cin >> v[i][2];
        
        ans[0] = v[0][0];

        for (int i = 1; i < n; ++i) {
            int last = (i - 1 + n) % n;
            for (int j = 0; j < 3; ++j) {
                if(v[i][j] != ans[last] and v[i][j] != ans[(i + 1) % n]) {
                    ans[i] = v[i][j];
                    break;
                }
            }
        }

        for (int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}

