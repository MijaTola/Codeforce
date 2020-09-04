#include <bits/stdc++.h>

using namespace std;

long long p[26][26];
long long d[26][26];
string s;
long long get(int x, int y) {
    if(x == y) return 0;
    return d[x][y];
}

void build() {
    for (int k = 0; k < 26; ++k) 
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j) 
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j) {
            cin >> p[i][j];
            d[i][j] = p[i][j];
        }
    build();
    cin >> s;
    int l = 0, r = s.size() - 1;
    long long ans = 0;
    while(l < r) {
        if(s[l] != s[r]){
            long long mn = 1e18;
            for (int i = 0; i < 26; ++i) 
                mn = min(mn, get(s[l] - 'a', i) + get(s[r] - 'a',i));
            ans += mn;
        }
        l++,r--;
    }
    cout << ans << "\n";
    return 0;
}

