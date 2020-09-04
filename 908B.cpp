#include <bits/stdc++.h>

using namespace std;

int n,m;
char c[110][110];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int v[] = {0,1,2,3};
//d u r l
//

int main(){
    cin >> n >> m;
    int sx,sy,ex,ey;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            cin >> c[i][j];
            if(c[i][j] == 'S') sx = i, sy = j;
            if(c[i][j] == 'E') ex = i, ey = j;
        }

    string s;
    cin >> s;
    int ans = 0;
    do {
        int x = sx;
        int y = sy;
        bool found = 0;
        for (int i = 0; i < (int)s.size(); ++i){
            if(x == ex and y == ey) {
                ans++;
                found = 1;
                break;
            }
            int p = s[i] - '0';
            int pp;
            for (int j = 0; j < 4; ++j){
                if(v[j] == p) pp = j;
            }
            int uu = dx[pp] + x;
            int vv = dy[pp] + y;
            if(uu >= 0 and uu < n and vv >= 0 
                    and vv < m and c[uu][vv] != '#') {
                x = uu;
                y = vv;
            } else break;
        }
            if(x == ex and y == ey and !found) {
                ans++;
            }
    }while(next_permutation(v, v + 4));
        
    cout << ans << "\n";
    return 0;
}

