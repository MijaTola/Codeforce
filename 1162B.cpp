#include <bits/stdc++.h>

using namespace std;

int n,m;
int c1[55][55];
int c2[55][55];

bool nochange(int x, int y) {
    for (int i = y + 1; i < m; ++i) 
        if(c1[x][i] <= c1[x][y] or c2[x][i] <= c2[x][y]) 
            return 0;
    for (int i = x + 1; i < n; ++i)
        if(c1[i][y] <= c1[x][y] or c2[i][y] <= c2[x][y])
            return 0;
    return 1;
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c1[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c2[i][j];
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if(c1[i][j] > c2[i][j])
                swap(c1[i][j], c2[i][j]);

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if(!nochange(i,j)) return cout << "Impossible\n",0;
    cout << "Possible\n";
    return 0;
}

