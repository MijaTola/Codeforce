#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {

        int a,b,c;
        cin >> a >> b >> c;

        int res = 1e9;
        int r1 = -1, r2 = -1,r3 = -1;

        for (int i = 1; i <= 20000; ++i) {
            int dfa = 1e9;
            int ans1 = -1,ans2 = -1,ans3 = -1;
            ans2 = i;
            int df = abs(b - i);
            for (int j = 1; j * j <= i; ++j) {
                if(i % j == 0) {
                    int x = i / j;
                    int y = j;
                    int curd = -1;
                    int val = -1;
                    if(abs(x - a) <= abs(y - a)) {
                        curd = abs(x - a);
                        val = x;
                    } else {
                        curd = abs(y - a);
                        val = y;
                    }

                    if(curd < dfa) {
                        dfa = curd;
                        ans1 = val;
                    }
                }
            }

            int l = 0, r = c;

            while(r - l > 1) {
                int mid = (r + l) / 2;
                if(mid * i >= c) r = mid;
                else l = mid;
            }

            int x = r * i;
            int y = (r - 1) * i;

            int dfb = 1e9;

            if(abs(c - x) <= abs(c - y)) {
                dfb = abs(c - x);
                ans3 = x;
            } else {
                dfb = abs(c - y);
                ans3 = y;
            }

            if(df + dfb + dfa < res) {
                res = df + dfb + dfa;
                r1 = ans1;
                r2 = ans2;
                r3 = ans3;
            }
        }
        assert(r1 != -1 and r2 != -1 and r3 != -1);
        cout << res << "\n";
        cout << r1 << " "  << r2 << " " << r3 << "\n";

    }
    return 0;
}

