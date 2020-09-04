#include <bits/stdc++.h>

using namespace std;

int n,m;
int c[1010][1010];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];

    
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if(!c[i][j] and cnt) {
                ans++;
            }
            cnt += c[i][j];
        }
        
        cnt = 0;
        for (int j = m - 1; j >= 0; j--) {
            if(!c[i][j] and cnt) ans++;
            cnt += c[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if(!c[j][i] and cnt) ans++;
            cnt += c[j][i];
        }
        
        cnt = 0;
        for (int j = n - 1; j >= 0; j--) {
            if(!c[j][i] and cnt) ans++;
            cnt += c[j][i];
        }
    }
    
    cout << ans << "\n";
    return 0;
}

