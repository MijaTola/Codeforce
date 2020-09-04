#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        string r = "abacaba";

        auto count = [&] (string a) {
            int ans = 0;
            for (int i = 0; i <= n - (int)r.size(); ++i) {
                int cnt = 0;
                for (int j = 0, p = i; j < (int)r.size(); ++j, p++) {
                    cnt += r[j] == a[p];
                }
                if(cnt == (int)r.size()) ans++;
            }
            
            return ans == 1;
        };

        for (int i = 0; i <= n - (int)r.size(); ++i) {
            string aux = s;
            int cnt = 0;
            for (int j = 0, p = i; j < (int)r.size(); ++j, p++) {
                cnt += r[j] == aux[p] or aux[p] == '?';
                aux[p] = r[j];
            }
            for (int j = 0; j < n; ++j)
                if(aux[j] == '?') aux[j] = 'z';

            if(cnt == (int)r.size()) {
                if(count(aux)) {
                    cout << "Yes\n";
                    cout << aux << "\n";
                    goto fin;
                }
            }
        }

    
        cout << "No\n";
            fin:;


    }
    return 0;
}

