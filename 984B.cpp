#include <bits/stdc++.h>

using namespace std;

char c[110][110];
int n,m;

int dx[] = {1,1,1,0,-1,-1,-1,0};
int dy[] = {1,0,-1,-1,-1,0,1,1};

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> c[i][j];

    
    bool flag = 1;

    auto check = [] (int x, int y) {
        int ans = 0;
        for (int i = 0; i < 8; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            ans += c[u][v] == '*'; 
        }
        return ans;
    };

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(c[i][j] == '.') flag &= check(i,j) == 0;
            else if(c[i][j] != '*') flag *= check(i,j) == c[i][j] - '0';
        }
    }

    cout << (flag ? "YES" : "NO") << "\n";

    return 0;
}

