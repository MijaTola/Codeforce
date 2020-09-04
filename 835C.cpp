#include <bits/stdc++.h>

using namespace std;

long long stars[15][110][110];

int main(){
    int n,q,c;
    cin >> n >> q >> c;
    c++;
    for (int i = 0; i < n; ++i){
        int x,y,s; 
        cin >> x >> y >> s;
        for (int j = 0; j < 15; ++j){
            stars[j][x][y] += (s + j) % c;
        }
    }

    for (int i = 0; i < 15; ++i){
        for (int x = 1; x <= 100; ++x){
            for (int y = 1; y <= 100; ++y){
                if(x) stars[i][x][y] += stars[i][x - 1][y];
                if(y) stars[i][x][y] += stars[i][x][y - 1];
                if(x and y) stars[i][x][y] -= stars[i][x - 1][y - 1];
            }
        }
    }

    while(q--){
        int t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int curt = t % c;
        long long ans = stars[curt][x2][y2];
        if(x1) ans -= stars[curt][x1 - 1][y2];
        if(y1) ans -= stars[curt][x2][y1 - 1];
        if(x1 and y1) ans += stars[curt][x1 - 1][y1 - 1];
        cout << ans  << "\n";
    }
    return 0;
}

