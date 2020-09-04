#include <bits/stdc++.h>

using namespace std;

int t,n;
int v[300010];
int dl[300010];
int dr[300010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;

    while(t--) {
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            dl[i] = -1, dr[i] = -1;
        }
        

        int cur = 0;
        int pos = 0;
        while(v[pos] >= cur and pos < n) {
            dl[pos] = cur;
            cur++, pos++;
        }
    
        pos = n - 1;
        cur = 0;
        while(pos >= 0 and v[pos] >= cur) {
            dr[pos] = cur;
            cur++, pos--;
        }
        
        bool flag = 0;
        
        flag |= dr[0] == n - 1;
        flag |= dl[n - 1] == n - 1;

        for (int i = 1; i < n - 1; ++i) {
            if(dl[i] == -1 or dr[i] == -1) continue;
            if(dl[i - 1] == -1 or dr[i + 1] == -1) continue;
            int mx = max(dr[i + 1], dl[i - 1]) + 1;
            flag |= v[i] >= mx;
        }

        if(flag) cout << "Yes\n";
        else cout << "No\n";

        
    }
    return 0;
}

