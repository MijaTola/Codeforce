#include <bits/stdc++.h>

using namespace std;

string s[2010];
int a[2010];
int main() {

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j)
            a[j] += (s[i][j] == '1');
    }
    //1 2 2 2 2 2 3 3
    for (int i = 0; i < n; ++i) {
        bool can = 1;
        for (int j = 0; j < m; ++j) 
            can &= (a[j] - (int)(s[i][j] - '0')) > 0;
        if(can) return cout << "YES\n", 0;
    }
    cout << "NO\n";
    return 0;
}

