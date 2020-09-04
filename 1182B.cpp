#include <bits/stdc++.h>

using namespace std;

int h,w;
char m[510][510];
bool vis[510][510];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool ver(int x,int y) {
    return x >= 0 and x < h and y >= 0 and y < w  and m[x][y] == '*';
}

int main() {
    
    cin >> h >> w;

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> m[i][j];

    int cnt = 0;
    for (int i = 0; i < h; ++i) 
        for (int j = 0; j < w; ++j) {
            if(m[i][j] != '*') continue;
            bool is = 1;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                is &= ver(x, y);
            }
            cnt += is;
            if(is) {
                vis[i][j] = 1;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    while(!vis[x][y] and ver(x,y)) {
                        vis[x][y] = 1;
                        x += dx[k];
                        y += dy[k];
                    }
                }
            }
        }
    if(cnt == 1) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0 ; j < w; ++j) {
                if(ver(i,j) and !vis[i][j]) return cout << "NO\n",0;
            }
        }
        cout << "YES\n";
    } else cout << "NO\n";
    return 0;
}

