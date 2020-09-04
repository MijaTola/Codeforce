#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
    cin >> t;

    while(t--) {
        cin >> s;
        int p = 0;
        int i = 0;
        long long sum = 0;
        long long ans = 0;
        while(i < (int)s.size()) {
            ans += i;
            bool flag = 0;
            long long cur = p + sum;
            while(i < (int)s.size()) {
                ans++;
                if(s[i] == '+') sum++, cur++;
                else sum--,cur--;
                i++;
                if(cur < 0) {
                    flag = 1;
                    break;
                }
            }
            if(!flag) break;

            if(i == (int)s.size()) {
                ans += s.size();
                break;
            }
            p++;
        }
        cout << ans << "\n";
    }
    return 0;
}

