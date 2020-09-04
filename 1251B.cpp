#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;

    while(q--) {
        vector<pair<int,int> > v;
        int n;
        cin >> n;
        int  c = 0, ans = 0, e = 0;;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int a = 0, b = 0;
            for (char x: s) {
                if(x == '1') a++;
                else b++;
            }
            if(s.size() & 1) e++;
            else {
                if(a % 2 == 0 and b % 2 == 0) ans++;
                else c++;
            }
        }
        
        int p = 2 * (c / 2);
        c -= p;
        int cur = 2 * min(c, e);
        int left = e - min(c,e);
        cout << ans + p + cur + left << "\n";
    }
    return 0;
}

