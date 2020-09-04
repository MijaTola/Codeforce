#include <bits/stdc++.h>

using namespace std;

int n,t;
string s;

int main() {

    cin >> t;

    while(t--) {
        cin >> s;
        n = s.size();

        int ans = 1e9;
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i] == '1') a++;
            else b++;
            int c = 0;
            int d = 0;
            for (int j = i + 1; j < n; ++j) {
                if(s[j] == '1') c++;
                else d++;
            }
            //cout << i << " " << b + c << " " << a + d<< "\n";
            //10
            ans = min(ans, b + c);
            //01
            ans = min(ans, a + d);
        }

        cout << ans << "\n";
    }

    return 0;
}

