#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int val[4];
int main() {
    

    auto dis = [] (int x, int y, int a, int b) {
        return abs(x - a) + abs(y - b);
    };

    int n,sx,sy;
    cin >> n >> sx >> sy;

    vector<pair<int,int> > b;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        b.emplace_back(x,y);
    }


    for (int i = 0; i < 4; ++i) {
        int u = sx + dx[i];
        int v = sy + dy[i];
        if(u >= 0 and v <= 1e9 and v >= 0 and v <= 1e9) {
        for (auto p: b) 
            if(dis(u, v, p.first, p.second) < dis(sx,sy,p.first, p.second)) val[i]++;
        }
    }

    int id = 0;
    int mx = 0;
    for (int i = 0; i < 4; ++i) {
        if(val[i] > mx) {
            id = i;
            mx = val[i];
        }
    }
    cout << val[id] << "\n";
    cout << sx + dx[id] << " " << sy + dy[id] << "\n";
    return 0;
}

