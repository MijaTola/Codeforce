#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,-1,0,0,1,-1,-1,1};
int dy[] = {0,0,1,-1,1,-1,1,-1};
int n,m;

bool v[1010][1010];
bool b[1010][1010];
bool ver(int x,int y) {
    return x >= 0 and x < n and y >= 0 and y < m;
}
int main() {
    memset(v,0,sizeof v);
    memset(b,0,sizeof b);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x; cin >> x;
            if(x == '#') v[i][j] = 1;
            else v[i][j] = 0;
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
                bool flag = 1;
                for (int k = 0; k < 8; ++k) {
                    int xx = dx[k] + i;
                    int yy = dy[k] + j;
                    if(!ver(xx,yy)) flag = 0;
                    if(!v[xx][yy]) flag = 0;
                }
                if(flag) {
                    for (int k = 0; k < 8; ++k) {
                        int xx = dx[k] + i;
                        int yy = dy[k] + j;
                        b[xx][yy] = 1;
                    }
                }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(v[i][j] != b[i][j]) return cout << "NO\n",0;
        }
    }
    cout << "YES\n";
        return 0;
    }

