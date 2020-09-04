#include <bits/stdc++.h>

using namespace std;

int a[210];
int b[210];
set<int> sa,sb;
int main() {
    
    int n,m;
    cin >> n;
    for (int i = 0;i < n; ++i) {
        cin >> a[i];
        sa.insert(a[i]);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sb.insert(b[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j  = 0; j < m; ++j) {
            int v = a[i] + b[j];
            if(!sa.count(v) and !sb.count(v)) {
                return cout << a[i] << " " << b[j] << "\n",0;
            }
        }
    }
    return 0;
}

