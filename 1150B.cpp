#include <bits/stdc++.h>

using namespace std;

int n;
char c[55][55];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
bool can(int x, int y) {
    if(c[x][y] != '.') return 0;
    for (int i = 0; i < 4; ++i) {
        int u = dx[i] + x;
        int v = dy[i] + y;
        if(u >= 0 and u < n and v >= 0 and v < n and c[u][v] == '.') {}
        else return 0;
    }
    return 1;
}

void fill(int x, int y) {
    c[x][y] = '#';
    for (int i = 0; i < 4; ++i) {
        int u = dx[i] + x;
        int v = dy[i] + y;
        if(u >= 0 and u < n and v >= 0 and v < n) c[u][v] = '#';
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> c[i][j];
            

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(can(i,j)) fill(i,j);
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if(c[i][j] == '.') return cout << "NO\n", 0;
    
    cout << "YES\n";
    return 0;
}

