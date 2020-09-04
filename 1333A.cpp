#include <bits/stdc++.h>

using namespace std;

char a[110][110];
int main() {


    for (int i = 0; i <  110; ++i)
        for (int j = 0; j < 110; ++j)
            a[i][j] = 'B';
    a[0][0] = 'W';
    int t;
    cin >> t;
    
    while(t--) {

        int n,m;
        cin >> n >> m;

        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cout << a[i][j];
            cout << "\n";
        }
    }
    return 0;
}

