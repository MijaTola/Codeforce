#include <bits/stdc++.h>

using namespace std;

int v[110];
int main() {
    int n; cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    
    int mx = 1;
    int c = 1;
    bool flag = 0;
    v[n + 1] = 1001;
    for (int i = 1; i <= n + 1; ++i) {
        if(v[i] == v[i - 1] + 1) {
            c++;
        } else {
            mx = max(c,mx);
            c = 1;
        }
    }
    
    mx = max(c, mx);
    cout << max(0,mx - 2) <<"\n";
    return 0;
}

