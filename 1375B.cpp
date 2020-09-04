#include <bits/stdc++.h>

using namespace std;

int c[310][310];

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> c[i][j];

        if(n == 1 and m == 1) {
            if(c[0][0] != 0) cout << "NO\n";
            else cout << c[0][0] << "\n";
            continue;
        }

        if(n == 1) {
            bool flag = 1;
            for (int i = 1; i < m - 1; ++i) {
                flag &= c[0][i] <= 2;
                c[0][i] = 2;
            }
            flag &= c[0][0] <= 1;
            c[0][0] = 1;
            flag &= c[0][m - 1] <= 1;
            c[0][m - 1] = 1;

            if(!flag) cout << "NO\n";
            else {
                cout << "YES\n";
                for (int i = 0; i < m; ++i)
                    cout << c[0][i] << " ";
                cout << "\n";
            }
            continue;
        }

        if(m == 1) {
            bool flag = 1;
            for (int i = 1; i < n - 1; ++i) {
                flag &= c[i][0] <= 2;
                c[i][0] = 2;
            }
            flag &= c[0][0] <= 1;
            c[0][0] = 1;
            flag &= c[n - 1][0] <= 1;
            c[n - 1][0] = 1;

            if(!flag) cout << "NO\n";
            else {
                cout << "YES\n";
                for (int i = 0; i < n; ++i)
                    cout << c[i][0] << "\n";
            }
            continue;
        }


        bool flag = 1;

        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                flag &= c[i][j] <= 4;
                c[i][j] = 4;
            }
        }

        for (int i = 1; i < n - 1; ++i) {
            flag &= c[i][0] <= 3;
            c[i][0] = 3;
            flag &= c[i][m - 1] <= 3;
            c[i][m - 1] = 3;
        }

        for (int i = 1; i < m - 1; ++i) {
            flag &= c[0][i] <= 3;
            c[0][i] = 3;
            flag &= c[n - 1][i] <= 3;
            c[n - 1][i] = 3;
        }

        flag &= c[0][0] <= 2;
        c[0][0] = 2;

        flag &= c[0][m - 1] <= 2;
        c[0][m - 1] = 2;

        flag &= c[n - 1][0] <= 2;
        c[n - 1][0] = 2;

        flag &= c[n - 1][m - 1] <= 2;
        c[n - 1][m - 1] = 2;

        if(!flag) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cout << c[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}

