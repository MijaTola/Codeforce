#include <bits/stdc++.h>

using namespace std;

int a[30];
int main(){
    
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        memset(a,0,sizeof a);
        bool ans = 1;
        for (int i = 0; i < (int)s.size() / 2; ++i) {
            int da = s[i] - 'a';
            int db = s[n - (i + 1)] - 'a';
            ans &= da + 1 == db - 1 or da - 1 == db + 1
                    or da + 1 == db + 1 or da - 1 == db - 1;
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

