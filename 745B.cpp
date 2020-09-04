#include <bits/stdc++.h>

using namespace std;

char c[510][510];
int main () {
    
    int n,m;
    cin >> n >> m;
    
    bool first = 1;
    int inix = -1, iniy = -1;
    int finx = -1, finy = -1;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
            if(c[i][j] == 'X') {
                if(first) {
                    inix = i, iniy = j;
                    first = 0;
                }
                finx = i, finy = j;
            }
        }

    if(inix == -1) return cout << "NO\n",0;
    
    bool full = 1;

    for (int i = inix; i <= finx; ++i) 
        for (int j = iniy; j <= finy; ++j) {
            full &= c[i][j] == 'X';
            c[i][j] = '.';
        }
    if(!full) return cout << "NO\n",0;
    full = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            full &= c[i][j] == '.';

    if(full) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}
