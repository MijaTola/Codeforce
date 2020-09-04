#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        
        int ans = 1e9;
        for (char i = '0'; i <= '9'; ++i) {
            for (char j = '0'; j <= '9'; ++j) {
                bool flag = 0;
                int cnt = 0;
                int cnt2 = 0;
                int cnt3 = 0;
                for (char x: s) {
                    if(!flag) {
                        if(x == i and i != j) {
                            cnt++;
                            flag = !flag;
                        }
                    } else {
                        if(x == j and i != j) {
                            cnt++;
                            flag = !flag;
                        }
                    }

                    if(x == i) cnt2++;
                    if(x == j) cnt3++;
                
                }

                if(flag) cnt--;
                
                int del = s.size() - cnt;
                int del2 = s.size() - cnt2;
                int del3 = s.size() - cnt3;
                ans = min(ans, del);
                ans = min(ans, del2);
                ans = min(ans, del3);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

