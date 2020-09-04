#include <bits/stdc++.h>

using namespace std;

int v[110];
int p[110];
int n,m;   

int main() {

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            cin >> v[i];

        for (int i = 0; i < m; ++i) {
            cin >> p[i];
            p[i]--;
        }

        bool flag = 1;
        while(flag) {
            flag = 0;
            for (int i = 0; i < m; ++i) {
                if(v[p[i]] > v[p[i] + 1] and p[i] + 1 < n) {
                    swap(v[p[i]], v[p[i] + 1]);
                    flag = 1;
                }
            }
        }

        flag = 1;
        for (int i = 1; i < n; ++i)
            flag &= v[i] >= v[i - 1];

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

