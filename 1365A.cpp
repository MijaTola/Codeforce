#include <bits/stdc++.h>

using namespace std;

int c[55][55];
int dx[55];
int dy[55];

int main() {

    int t;
    cin >> t;

    while(t--) {
        memset(c, 0, sizeof c);
        memset(dx, 0, sizeof dy);
        memset(dy, 0, sizeof dx);
        int n,m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> c[i][j];
                if(c[i][j] == 1) {
                    dx[i] = 1;
                    dy[j] = 1;
                }
            }

        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            cnt1 += !!!dx[i];
        }
        for (int i = 0; i < m; ++i) {
            cnt2 += !!!dy[i];
        }
        
        if(cnt1 < cnt2) {
            if(cnt1 & 1) cout << "Ashish\n";
            else cout << "Vivek\n";
        } else {
            if(cnt2 & 1) cout << "Ashish\n";
            else cout << "Vivek\n";
        }
    }
    return 0;
}

