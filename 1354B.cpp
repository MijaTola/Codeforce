#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int a = -1, b = s.size() + 1;


        auto ver = [&] (int k) -> bool {
            int v[4];   
            v[0] = v[1] = v[2] = v[3] = 0;

            for (int i = 0; i < k; ++i) {
                v[s[i] - '0']++;
            }

            if(v[1] and v[2] and v[3]) return 1;

            bool flag = 0;
            for (int i = k, l = 0; i < (int)s.size(); ++i, l++) {
                v[s[l] - '0']--;
                v[s[i] - '0']++;
                flag |= (v[1] and v[2] and v[3]);
            }

            return flag;
        };

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid)) b = mid;
            else a = mid;
        }
        if(b <= (int)s.size()) cout << b << "\n";
        else cout << "0\n";
    }
    return 0;
}

