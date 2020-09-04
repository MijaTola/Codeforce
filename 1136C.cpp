#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> a[100010];
vector<int> b[100010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            a[i + j].push_back(x);
        }

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            b[i + j].push_back(x);
        }

    for (int i = 0; i < 1010; ++i) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
        for (int j = 0; j < (int)a[i].size(); ++j) 
            if(a[i][j] != b[i][j]) return cout << "NO\n",0;
    }
    cout << "YES\n";
    return 0;
}
