#include <bits/stdc++.h>

using namespace std;

int c[110][110];
int f[110], l[110];
int n,m,h;
int main() {
    cin >> n >> m >> h;


    for (int i = 0; i < m; ++i) 
        cin >> f[i];
    for (int i = 0; i < n; ++i)
        cin >> l[i];

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if(x == 0) continue;
            c[i][j] = min(f[j], l[i]);
        }
    

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << c[i][j] << " ";
        cout << "\n";
    }

    
        
    return 0;
}

