#include <bits/stdc++.h>

using namespace std;

int c[500][500];

int main() {

    int n;
    cin >> n;
    vector<vector<vector<int> > > m ;
    vector<int> p;

    for (int j = 0; j < 4; ++j) {
        p.push_back(j);
        vector<vector<int> > cur(n);

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (char x: s) 
                cur[i].push_back(x - '0');
            
        }
        m.push_back(cur);
    }

    auto fill = [] (int a, int b, int x, int y, vector<vector<int> > & cur) {
        for (int i = a, l = 0; i <= x; ++i, l++) {
            for (int j = b, r = 0; j <= y; ++j, r++) {
                c[i][j] = cur[l][r];
            }
        }
    };

    auto check = [&] () {
        int a1 = 0, a2 = 0;
        for (int i = 0; i < 2 * n; ++i) 
            for (int j = 0; j < 2 * n; ++j) {
                bool x = (i + j) & 1;
                a1 += x != c[i][j];
                a2 += !x != c[i][j];
            }
        return min(a1, a2);
    };

    int ans = 1e9;
    do {
        fill(0, 0, n - 1, n - 1, m[p[0]]);
        fill(0, n, n - 1, 2 * n - 1, m[p[1]]);
        fill(n, 0, 2 * n - 1, n - 1, m[p[2]]);
        fill(n, n, 2 * n - 1, 2 * n - 1, m[p[3]]);
        ans = min(ans, check());
    } while(next_permutation(p.begin(), p.end()));

    cout << ans << "\n";
    return 0;
}

