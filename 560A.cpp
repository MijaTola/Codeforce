#include <bits/stdc++.h>

using namespace std;

set<int> s;
int v[1010];
bool vis[3000010];
int main() {
    
    int n;
    cin >> n;
    int mn = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mn = min(v[i],mn);
    }
    
    if(mn == 1) cout << "-1\n";
    else cout << "1\n";
    return 0;
}

