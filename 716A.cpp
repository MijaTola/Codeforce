#include <bits/stdc++.h>

using namespace std;

int v[200010];

int main() {
    
    int n,c;
    cin >> n >> c;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int cur = 1;

    for (int i = 1; i < n; ++i) {
        if(v[i] - v[i - 1] <= c) cur++;
        else cur = 1;
    }
    cout << cur << "\n";
    return 0;
}

