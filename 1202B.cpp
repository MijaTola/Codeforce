#include <bits/stdc++.h>

using namespace std;

string s;
int dis[10];
int pre[10][10][10][10];
int ans[10][10];
int x,y;

void f(int a, int b, int x, int y) {
    memset(dis, -1, sizeof dis);
    queue<int> q;
    q.push(a);
    dis[a] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(dis[u + x] == -1) {
            dis[u + x] = dis[u] + 1;
            q.push(u + x);
        }
        if(dis[u + y] == -1) {
            dis[u + y] = dis[u] + 1;
            q.push(u + y);
        }
    }
    cout << a << " " << b << " " << x << " " << y << " " << dis[b] << " haha\n";
    pre[a][b][x][y] = (dis[b] != -1) ? dis[b] : -1e9;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < 10; ++i) 
        for (int j = 0; j < 10; ++j) 
            for (int x = 0; x < 10; ++x)
                for (int y = 0; y < 10; ++y)
                    f(i,j,x,y);
        

    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int ans = 0;
            for (int k = 1; k < (int)s.size(); ++k) {
                int l = s[k - 1] - '0';
                int r = s[k] - '0';
                ans += pre[l][r][i][j];
            }
            cout << max(ans, -1) << " ";
        }
        cout << "\n";
    }

        
    
    return 0;
}

