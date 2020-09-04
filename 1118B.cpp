#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int e[200010];
int o[200010];
int de[200010];
int od[200010];

int main() {
    
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    
    for (int i = 0; i < n; ++i) {
        if(i & 1) o[i] = od[i] = v[i];
        else e[i] = de[i] = v[i];
    }


    for (int i = 1; i < n; ++i) {
        e[i] += e[i - 1];
        o[i] += o[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        de[i] += de[i + 1];
        od[i] += od[i + 1];
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int le = 0;
        int re = 0;
        int lo = 0;
        int ro = 0;
        if(i) {
            le = e[i - 1];
            lo = o[i - 1];
        }
        re = de[i + 1];
        ro = od[i + 1];
        if(le + ro == re + lo) ans++;
    }
    cout << ans << "\n";
    return 0;
}

