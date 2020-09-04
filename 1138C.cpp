#include <bits/stdc++.h>

using namespace std;

int n,m;

set<int> dx[1010],dy[1010];
int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            dx[i].insert(x);
            dy[i].insert(x);
        }
    }
    
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            cout << max((int)dx[i].size(), (int)dy[i].size()) << " ";
        cout << "\n";    
    }
    return 0;
}

