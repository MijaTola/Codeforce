#include <bits/stdc++.h>

using namespace std;

int n,m;
char c[1010][1010];
int v[1010][1010];
int h[1010][1010];

int main(){

    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
            cnt += c[i][j] == '*';
        }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            h[i][j] = c[i][j] == '*';

        for (int j = 1; j < m; ++j)
            h[i][j] += h[i][j - 1];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) 
            v[j][i] = c[j][i] == '*';

        for (int j = 1; j < n; ++j)
            v[j][i] += v[j - 1][i];
    }

    auto check = [] (int x, int y, int sz) -> bool {
        bool flag = 1;

        int a = x - sz, b = x + sz;
        if(a < 0 or b >= n) return 0;
        int d = v[b][y];
        if(a) d -= v[a - 1][y];
        flag &= d == b - a + 1;

        a = y - sz, b = y + sz;
        if(a < 0 or b >= m) return 0;
        d = h[x][b];
        if(a) d -= h[x][a - 1];
        flag &= d == b - a + 1;
        return flag;
    };

    vector<tuple<int,int,int> > ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == '.') continue;
            int a = 0, b = n + m;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                if(check(i,j, mid)) a = mid;
                else b = mid;
            }
            if(a) {
                ans.emplace_back(i + 1,j + 1,a);
                cnt -= b * 4 - 1;
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << get<0> (p) << " " << get<1> (p) << " " << get<2> (p) << "\n";
    return 0;
}
