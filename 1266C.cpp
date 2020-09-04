#include <bits/stdc++.h>

using namespace std;


int lcm(int a, int b) {
    return a * b / __gcd(a,b);
}

vector<int> ans[510];

int main() {

    int n,m;
    cin >> n >> m;

    if(n == 1 and m == 1) return cout << "0\n", 0;

    bool flag = 0;
    if(n > m) swap(n, m), flag = 1;
    int cur = 2;
    for (int i = 0; i < m; ++i)
        ans[i].push_back(cur++);

    for (int i = 0; i < n - 1; ++i, cur++) {
        for (int j = 0; j < m; ++j) {
            ans[j].push_back(lcm(ans[j][0], cur));
        }
    }

    if(!flag) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cout << ans[j][i] << " ";
            cout << "\n";
        }
    } else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                cout << ans[i][j] << " ";
            cout << "\n";
        }

    }
    return 0;
}

