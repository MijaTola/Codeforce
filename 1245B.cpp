#include <bits/stdc++.h>

using namespace std;

int n,a,b,c;
string s;
char ans[110];

int main() {

    int t;
    cin >> t;
    while(t--) {

        for (int i = 0; i < 110; ++i)
            ans[i] = '.';

        cin >> n >> a >> b >> c >> s;

        int mid = (n + 1) / 2;
        int pos = 0;
        int cnt = 0;
        for (char x: s) {
            if(x == 'R' and b) {
                ans[pos] = 'P';
                b--;
                cnt++;
            }

            if(x == 'P' and c) {
                ans[pos] = 'S';
                c--;
                cnt++;
            }

            if(x == 'S' and a) {
                ans[pos] = 'R';
                a--;
                cnt++;
            }
            pos++;
        }

        for (int i = 0; i < n; ++i) {
            if(ans[i] == '.') {
                if(a) ans[i] = 'R', a--;
                else if(b) ans[i] = 'P', b--;
                else if(c) ans[i] = 'S', c--;
            }
        }

        if(cnt >= mid) {
            cout << "Yes\n";
            for (int i = 0; i < n; ++i)
                cout << ans[i];
            cout << "\n";
        } else cout << "No\n";

    }
    return 0;
}

