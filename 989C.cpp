#include <bits/stdc++.h>

using namespace std;

int v[4];
int b[4];
int d[4];
int c[55][55];
bool vis[55][55];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool ver() {
    for (int i = 0; i < 4; ++i) {
        if(b[i] > v[i]) return 0;
    }
    return 1;
}
bool valid() {
    for (int i = 0; i < 4; ++i)
        if(d[i] > v[i]) return 0;
    return 1;
}

bool distinct() {
    for (int i = 0; i < 4; ++i) 
        if(d[i] != b[i]) return 1;
    return 0;
}

void dfs(int x,int y, int num) {
    for (int i = 0; i < 4; ++i) {
        int uu = dx[i] + x;
        int vv = dy[i] + y;
        if(uu >= 0 and uu < 50 and vv >= 0 and vv < 50 
                and !vis[uu][vv] and c[uu][vv] == num) {
            vis[uu][vv] = 1;
            dfs(uu,vv,num);
        }
    }
}

void fill() {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            if(!vis[i][j]) {
                d[c[i][j]]++;
                vis[i][j] = 1;
                dfs(i,j,c[i][j]);
            }
        }
    }
}

void print() {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            cout << (char)(c[i][j] + 'A');
        }
        cout << "\n";
    }
}
int main(){
    memset(c,0,sizeof c);

    for (int i = 0; i < 4; ++i) {
        cin >> v[i];
    }
    b[0] = 1;
    while(ver()) {
        for (int i = 0; i < 50; ++i) {
            for (int j = 0; j < 50; ++j) {
                for (int k = 0; k < 4; ++k) {
                    memset(vis,0,sizeof vis);
                    memset(d,0,sizeof d);
                    if(b[k] == v[k] or c[i][j] != 0) continue;
                    c[i][j] = k;
                    fill(); 
                    if(!valid() or !distinct()) {
                        c[i][j] = 0;
                    }else break;
                }
            }
        }
        next: 
            for (int i = 0; i < 4; ++i)
                b[i] = d[i];
    }
    print();
    
    for (int i = 0; i < 4; ++i) 
        cout << b[i] << " ";
    return 0;
}

