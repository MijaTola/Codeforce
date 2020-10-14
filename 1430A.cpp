#include <bits/stdc++.h>

using namespace std;

int v[1010][8];
bool vis[1010];

int main() {

    v[3][3] = 1;
    v[7][7] = 1;
    v[5][5] = 1;
    vis[3] = vis[5] = vis[7] = 1;

    for (int i = 3; i < 1010; ++i) {
        if(vis[i]) {
            for (int j = 0; j < 8; ++j) {
                if(j == 3 or j == 5 or j == 7) {
                    int val = i + j;
                    if(!vis[val]) {
                        vis[val] = 1;
                        for (int k = 0; k < 8; ++k) {
                            v[val][k] = v[i][k];
                        }
                        v[val][j]++;
                    }
                }
            }
        }
    }

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        if(v[n][3] + v[n][5] + v[n][7] != 0) {
            cout << v[n][3] << " " << v[n][5] << " " << v[n][7] << "\n";
        } else cout << "-1\n";
    }
    return 0;
}

