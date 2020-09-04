#include <bits/stdc++.h>

using namespace std;

vector<int> v[10];
bool vis[1000];
int main(){

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        for (int j = 0; j < 6; ++j) {
            cin >> x;
            v[i].push_back(x);
        }
        sort(v[i].begin(), v[i].end());
    }
    if(n == 2) {
        for (int i = 0; i < 6; ++i)
            v[2].push_back(100);
    } else if(n == 1) {
        for (int i = 0; i < 6; ++i) {
            v[2].push_back(100);
            v[1].push_back(100);
        }
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k  = 0; k < 6; ++k) {
                int d = v[0][i] * 100 + v[1][j] * 10 + v[2][k];
                int dd = v[0][i] * 10 + v[1][j];
                int dv = v[1][i] * 10 + v[0][j];
                int ddd = v[1][i] * 10 + v[2][j];
                int ddv = v[2][i] * 10 + v[1][j];
                int dddd = v[0][i] * 10 + v[2][j];
                int dddv = v[2][i] * 10 + v[0][j];
                if(d >= 100) vis[d] = 1;
                if(dd >= 10) vis[dd] = 1;
                if(dv >= 10) vis[dv] = 1;
                if(ddd >= 10)vis[ddd] = 1;
                if(ddv >= 10)vis[ddv] = 1;
                if(dddd >= 10)vis[dddd] = 1;
                if(dddv >= 10)vis[dddv] = 1;
                vis[v[0][i]] = 1;
                vis[v[1][i]] = 1;
                vis[v[2][i]] = 1;
            }
        }
    }
    int p = 1;
    while(vis[p] == 1) p++;p--;
    cout << p << "\n";
    return 0;
}

