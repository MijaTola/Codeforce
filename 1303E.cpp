#include <bits/stdc++.h>

using namespace std;

string s,t;
int da,db;
int dp[406][406][406];

int f(int pos, int a, int b) {
    if(pos == (int)s.size()) return a == da and b == db;
    if(a == da and b == db) return 1;
    int &ans = dp[pos][a][b];
    if(ans != -1) return ans;
    ans = 0;
    if(a < da and s[pos] == t[a]) ans |= f(pos + 1, a + 1, b);
    if(b < db and s[pos] == t[b]) ans |= f(pos + 1, a, b + 1);
    if(a < da or b < db) ans |= f(pos + 1, a, b);
    return ans;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    int te;
    cin >> te;

    while(te--) {
        cin >> s >> t;
        bool flag = 0;
        for (int i = 0; i < (int)t.size(); ++i) {
            for (int j = 0; j < (int) s.size() + 5; ++j) 
                for (int k = 0; k < (int)t.size() + 5; ++k)
                    for (int l = 0; l < (int)t.size() + 5; ++l)
                        dp[j][k][l] = -1;
            da = i + 1, db = t.size();
            flag |= f(0, 0, i + 1);
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}

