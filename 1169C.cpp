#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[300010];
int b[300010];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

   
    int left = 0;
    int mx = 0;
    for (int i = 0; i < n - 1; ++i) {
        if(v[i] > v[i + 1]) {
            int d1 = m - v[i] + left;
            int d2 = v[i] - v[i + 1];
            if((abs(d1 - d2) <= 1 or d1 < d2) and v[i] > left) {
                mx = max(mx, m - v[i] + left);
            } else {
                mx = max(mx, v[i] - v[i + 1]);
                v[i + 1] = v[i];
                left = v[i];
            }
        } else left = v[i];
    }
    cout << mx << "\n";
    return 0;
}

//2 4 1 2 5

