#include <bits/stdc++.h>

using namespace std;

long long m[1010][1010];
int vis[1010];
int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<long long> ans, cur, is;
    for (int i = 0; i < n; ++i) {
        long long gcd = 0;
        for (int j = 0; j < n; ++j) {
            long long x;
            cin >> x;
            m[i][j] = x;
        }
    }
    

    return 0;
}

