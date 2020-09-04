#include <bits/stdc++.h>

using namespace std;

int n,q,t;
int m[110][110];
int c[110][110];
// a b -> t = X
// (a + X + b + X) % c;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q >> t;
    
    for (int i = 0; i < n; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        m[x][y] = z;
        c[x][y] = 1;
    }
    
    for (int i = 1; i < 110; ++i) {
        for (int j = 1; j < 110; ++j) {
            if(i) m[i][j] += m[i - 1][j], c[i][j] += c[i - 1][j];
            if(j) m[i][j] += m[i][j - 1], c[i][j] += c[i][j - 1];
            if(i and j) m[i][j] -= m[i - 1][j - 1], c[i][j] -= c[i - 1][j - 1];
        }
    }
    t++;
    while(q--) {
        int tt,x1,y1,x2,y2;
        cin >> tt >> x1 >> y1 >> x2 >> y2;
        int curt = tt % t;
        int ans = m[x2][y2];
        int cnt = c[x2][y2];
        if(x1) ans -= m[x1 - 1][y2], cnt -= c[x1 - 1][y2];
        if(y1) ans -= m[x2][y1 - 1], cnt -= c[x2][y1 - 1];
        if(x1 and y1) ans += m[x1 - 1][y1 - 1], cnt += c[x1 - 1][y1 - 1];
        cout << (ans + (curt * cnt)) << "\n";
    }
    return 0;
}

