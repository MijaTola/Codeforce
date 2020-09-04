#include <bits/stdc++.h>

using namespace std;

int m[26][26];
int main() {

    int t;
    cin >> t;

    while(t--) {
        memset(m, 0, sizeof m);
        int n;
        string a,b;
        cin >> n >> a >> b;

        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            if(a[i] > b[i]) {
                flag = 0;
                break;
            }
            if(a[i] != b[i]) m[a[i] - 'a'][b[i] - 'a']++;
        }

        if(!flag) {
            cout << "-1\n";
            continue;
        }
        
        int ans = 0;

        for (int i = 0; i < 21; ++i) {
            int id = -1;
            for (int j = 0; j < 21; ++j) {
                if(m[i][j]) {
                    id = j;
                    break;
                }
            }
            
            if(id == -1) continue;
            ans++;
            for (int j = 0; j < 20; ++j) {
                if(m[i][j] and id != j) {
                    m[id][j] += m[i][j];
                }
            }

        }
        cout << ans << "\n";

    }
    return 0;
}

