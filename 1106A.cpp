#include <bits/stdc++.h>

using namespace std;

int n;
char m[510][510];

bool ver(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < n and m[x][y] == 'X';
}
int main() {


    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < n; ++j) {
            if(m[i][j] == 'X') {
                int  c = 0;
                int x = i - 1;
                int y = j - 1;
                c +=  ver(x,y);
                x = i - 1;
                y = j + 1;
                c +=  ver(x,y);
                x = i + 1;
                y = j - 1;
                c +=  ver(x,y);
                x = i + 1;
                y = j + 1;
                c +=  ver(x,y);
            if(c == 4) ans++;
            }
        }
    }
    cout  << ans << "\n";
    return 0;
}

