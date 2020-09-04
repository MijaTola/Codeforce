#include <bits/stdc++.h>

using namespace std;

char c[510][510];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
    int n,m;
bool ver(int x,int y) {
    return x >= 0 and y >= 0 and x < n and y < m;
}
int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            cin >> c[i][j];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == 'W') {
                for (int k = 0; k < 4; ++k) {
                    int u = dx[k] + i;
                    int v = dy[k] + j;
                    if(ver(u,v) and c[u][v] == 'S') 
                        return cout << "NO\n",0;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == 'S') {
                for (int k = 0; k < 4; ++k) {
                    int u = dx[k] + i;
                    int v = dy[k] + j;
                    if(ver(u,v) and c[u][v] == '.') 
                        c[u][v] = 'D';
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout<< c[i][j];
        cout << "\n";
    }
    return 0;
}

