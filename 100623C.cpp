#include <bits/stdc++.h>

using namespace std;

int n,r,c;
char ans[110][110];

int main() {
    //freopen("class.in", "r", stdin);
    //freopen("class.out", "w", stdout);
    cin >> n >> r >> c;
    for (int i = 0; i < r; ++i) 
        for (int j = 0; j < c; ++j) 
            ans[i][j] = '.';

    
    ans[0][0] = '#';
    n--;
    int dr = 1, dc = 1;
    while(n and (dr < r or dc < c)) {
        if(dr < r and n) ans[dr++][0] = '#', n--;
        if(dc < c and n) ans[0][dc++] = '#', n--;
    }
    for (int i = 0; i < r and n; ++i) 
        for (int j = 0; j < c and n; ++j) 
            if(ans[i][j] == '.' and n) 
                ans[i][j] = '#', n--;

    cout << min(dr, dc) << "\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) 
            cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}

