#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n,x;
        string s;
        cin >> n >> x >> s;
        long long a = 0, b = 0;
        bool is = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if(s[i] == '0') a++;
            else b++;
            is |= a - b == x;
        }
        if(a == b and is) {
            cout << "-1\n";
            continue;
        }
        
        bool flag = 0;
        if(x < 0) flag = 1,swap(a,b), x = -x;
        
        if(b > a) {
            cout << "0\n";
            continue;
        }
        long long dif = a - b;
        long long l = -1, r = 1e9;

        while(r - l > 1) {
            long long mid = (r + l) / 2;
            if(mid * dif >= x) r = mid;
            else l = mid;
        }
        r--;
        long long ans = dif == x;
        dif *= r;
        for (int i = 0; i < 100; ++i) {
            for (auto c: s) {
                if(flag) {
                    if(c == '1') dif++;
                    else dif--;
                } else {
                    if(c == '1') dif--;
                    else dif++;
                }
                if(dif == x) ans++;
            }
        }
        cout << ans << "\n";

    }
    return 0;
}

