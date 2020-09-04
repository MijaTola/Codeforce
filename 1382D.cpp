#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int p[4010];
int Next[4010];
int dp[4010][4010][2];

int f(int cur, int sz, int flag) {
    if(cur == 2 * n + 1) {
        if(sz == 0) return 1;
        return 0;
    }

    int &ans = dp[cur][sz][flag];
    if(ans != -1) return ans;
    ans = 0;
    int tam = p[Next[cur]] - p[cur];
    
    if(flag) {
        ans |= f(Next[cur], sz - tam, flag);
        ans |= f(Next[cur], sz - tam, !flag);
    } else {
        ans |= f(Next[cur], sz, flag);
        ans |= f(Next[cur], sz, !flag);
    }
    return ans;
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        
        v.clear();
        cin >> n;

        for (int i = 1; i <= 2 * n + 1;++i) {
            Next[i] = 2 * n + 1;
            p[i] = 2 * n + 1;
        }
        
        for (int i = 0; i <= 2 * n + 1; ++i) {
            for (int j = 0; j <= 2 * n + 1; ++j) {
                for (int k = 0; k < 2; ++k)
                    dp[i][j][k] = -1;
            }
        }
        
        p[2 * n + 1] = 2 * n;

        for (int i = 0; i < 2 * n; ++i) {
            int x;
            cin >> x;
            p[x] = i;
            v.push_back(x);
        }

        for (int i = 0; i < 2 * n; ++i) {
            for (int j = i + 1; j < 2 * n; ++j)
                if(v[j] > v[i]) {
                    Next[v[i]] = v[j];
                    break;
                }
        }

        if(f(v[0], n, 1)) cout << "YES\n";
        else cout << "NO\n";
      

        
    }
    return 0;
}

