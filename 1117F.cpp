#include <bits/stdc++.h>

using namespace std;

const int lim = 1 << 17;
int m[20][20];
int dp[1 << 20];
int cnt[20];

int main() {
    
    int n,p;
    string s;
    cin >> n >> p >> s;

    for (auto x: s)
        cnt[x - 'a']++;
    
    bitset<lim> bad;
    
    auto f = [&] (char a, char b) {
        bitset<lim> current;
        int mask = 0;
        char last = '.';

        for (int i = 0; i < n; ++i) {
            if(s[i] == a) {
                if(last == b) current[mask] = 1;
                last = a;
                mask = 0;
            } else if(s[i] == b) {
                if(last == a) current[mask] = 1;
                mask = 0;
                last = b;
            } else {
                int x = s[i] - 'a';
                mask |=  (1 << x);
            }
        }

        for (int i = 0; i < (int)current.size(); ++i) {
            if(!current[i]) continue;
            for (int j = 0; j < p; ++j) {
                if(a - 'a' == j or b - 'a' == j) continue;
                current[i | (1 << j)] = 1;
            }
        }

        bad |= current;
    };

    for (int i = 0; i < p; ++i)
        for (int j = 0; j < p;++j) {
            int x;
            cin >> x;
            if(x) continue;
            f(i + 'a', j + 'a');
        }

    for (int i = (1 << p) - 2; i >= 0; i--) {
        dp[i] = 0;
        for (int j = 0; j < p; ++j) {
            if(!(i & (1 << j))) {
                if(bad[i | (1 << j)]) continue;
                dp[i] = max(dp[i], dp[i | (1 << j)] + cnt[j]);
            }
        }
    }
    
    cout << s.size() - dp[0] << "\n";
    return 0;
}

