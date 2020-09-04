#include <bits/stdc++.h>

using namespace std;

int a[30];
int main() {
    string s;
    int t;
    cin >> t;
    while(t--) {
        memset(a, 0, sizeof a);
        cin >> s;

        for (int i = 0; i < (int)s.size(); ++i) {
            a[s[i] - 'a']++;
        }
        bool ans = 1;
        for (int i = 0; i < 30; i++)
            if(a[i] > 1) ans = 0;
    
        if(ans == 0) {
            cout << "NO\n";
            continue;
        }
        int cnt = 0;
        int c = 0;
        for (int i = 0; i < 30; ++i) {
            if(a[i] >= 1) c++;
            else {
                cnt += (c != 0);
                c = 0;
            }
        }
        cnt += (c != 0);
        if(cnt == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

