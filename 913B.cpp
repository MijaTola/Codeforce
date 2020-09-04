#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[1010];
int main(){
    
    cin >> n;

    for (int i = 1; i <= n - 1; ++i) {
        int x; cin >> x;
        G[x].push_back(i + 1);
    }
    
    bool ans = 1;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        bool f = 1;
        for (int v: G[i]) {
            f = 0;
            if(G[v].size() == 0) cur++;
        }
        ans &= (cur >= 3 or (cur == 0 and f));
    }

    if(ans) cout << "Yes";
    else cout << "No";
    return 0;
}

