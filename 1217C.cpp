#include <bits/stdc++.h>

using namespace std;


int c[200010];
int main() {
    
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
    
        for (int i = 0; i < (int)s.size(); ++i)
            if(s[i] == '0') c[i] = 1;

        for (int i = 1; i < (int)s.size(); ++i)
            c[i] += c[i - 1];

        int ans = 0;
        for (int i = 0;  i < (int)s.size(); ++i) {
            
            int p = 0;
            long long sum = 0;
            for (int j = i, cnt = 1; j >= max(0, i - 20); j--, cnt++) {
                if(s[j] == '1') sum += (1 << p);
                cout << s[j];
                p++;
                if(c[j - 1] + cnt >= sum) ans+= c[j - 1];
            }
            cout << " " << sum << " " << ans << " test\n";
        }

        cout << ans << "\n";
    }
    return 0;
}

