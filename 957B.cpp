#include <bits/stdc++.h>

using namespace std;

char c[55][55];
bool dx[55];
bool dy[55];
int n,m;

int main(){

    cin >> n >> m;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            cin >> c[i][j];
 

    auto find = [&] (vector<int> v) {
    
        for (int i = 0; i < n; ++i) {
            if(dx[i]) continue;
            vector<int> b;
            for (int j = 0; j < m; ++j) {
                if(c[i][j] == '#' and !dy[j])
                    b.push_back(j);
            }

            if(b == v) {
                dx[i] = 1;
                for (int x: b) {
                    c[i][x] = '.';
                }
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if(dx[i]) continue;
        vector<int> v;
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == '#' and !dy[j])
                v.push_back(j);
        }
        
        find(v);

        for (int x: v)
            dy[x] = 1;
    }

    bool flag = 1;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            flag &= c[i][j] == '.';

    if(flag) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

