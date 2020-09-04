#include <bits/stdc++.h>

using namespace std;

int v[200010];
int main() {
    int n;
    cin >> n;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        l += v[i] == 1;
        r += v[i] == 0;
    }
    int i;
    for (i = 0; i < n and l and r; ++i) {
        if(v[i] == 1) l--;
        else r--;
    }
    cout << i << "\n";
    return 0;
}

