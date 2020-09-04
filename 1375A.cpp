#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int dp[100][2][100][100];

int f(int pos, int last, int a, int b) {
    if(pos == n) {
        if(a == b) return 1;
        return 0;
    }

    int &ans = dp[pos][last][a][b];
    if(ans != -1) return ans;
    ans = 0;
    if(pos) {
        int l = v[pos - 1];
        if(last) l = -l;

        int df = v[pos] - l;
        if(df < 0) ans |= f(pos + 1, 0, a + 1, b);
        if(df > 0) ans |= f(pos + 1, 0, a, b + 1);
        if(df == 0) {
            ans |= f(pos + 1, 0, a + 1, b);
            ans |= f(pos + 1, 0, a, b + 1);
        }

        df = -v[pos] - l;
        if(df < 0) ans |= f(pos + 1, 1, a + 1, b);
        if(df > 0) ans |= f(pos + 1, 1, a, b + 1);
        if(df == 0) {
            ans |= f(pos + 1, 1, a + 1, b);
            ans |= f(pos + 1, 1, a, b + 1);
        }

    } else {
        ans |= f(pos + 1, 1, a, b);
        ans |= f(pos + 1, 0, a ,b);
    }
    return ans;
}

void r(int pos, int last, int a, int b) {
    if(pos == n) {
        return;
    }

    if(pos) {
        int l = v[pos - 1];
        if(last) l = -l;

        int df = v[pos] - l;

        if(df < 0 and f(pos + 1, 0, a + 1, b)) {
            cout << v[pos] << " ";
            r(pos + 1, 0, a + 1, b);
            return;
        }
        if(df > 0 and f(pos + 1, 0, a, b + 1)) {
            cout << v[pos] << " ";
            r(pos + 1, 0, a, b + 1);
            return;
        }
        if(df == 0) {
            if(f(pos + 1, 0, a + 1, b)) {
                cout << v[pos] << " ";
                r(pos + 1, 0, a + 1, b);
                return;
            } 
            if(f(pos + 1, 0, a, b + 1)) {
                cout << v[pos] << " ";
                r(pos + 1, 0, a, b + 1);
                return;
            }
        }

        df = -v[pos] - l;
        if(df < 0 and f(pos + 1, 1, a + 1, b)) {
            cout << -v[pos] << " ";
            r(pos + 1, 1, a + 1, b);
            return;
        }
        if(df > 0 and f(pos + 1, 1, a, b + 1)) {
            cout << -v[pos] << " ";
            r(pos + 1, 1, a, b + 1);
            return;
        }
        if(df == 0) {
            if(f(pos + 1, 1, a + 1, b)) {
                cout << -v[pos] << " ";
                r(pos + 1, 1, a + 1, b);
                return;   
            }
            if(f(pos + 1, 1, a, b + 1)) {
                cout << -v[pos] << " ";
                r(pos + 1, 1, a, b + 1);
                return;
            }
        }


    } else {
        if(f(pos + 1, 1, a, b)) {
            cout << -v[pos] << " ";
            r(pos + 1, 1, a, b);
            return;
        }
        if(f(pos + 1, 0, a ,b)) {
            cout << v[pos] << " ";
            f(pos + 1, 0, a ,b);
            return;
        }
    }
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        v.clear();
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < n; ++k) {
                    for (int l = 0; l < n; ++l)
                        dp[i][j][k][l] = -1;
                }
            }
        }
        f(0,0,0,0);
        r(0,0,0,0);
        cout << "\n";
    }
    return 0;
}

