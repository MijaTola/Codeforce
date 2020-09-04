#include <bits/stdc++.h>

using namespace std;

int v[200010];
int n;

int f(int l, int r) {
    int dl = lower_bound(v, v + n, l) - v;
    int dr = upper_bound(v, v + n, r) - v;
    dr--;
    return dr - dl + 1;
}


int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);

    int ans = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = v[i] - 5; j + 5 <= v[i] + 5; ++j) 
            ans = max(ans, f(j, j + 5));
    cout << ans << "\n";
    return 0;
}

