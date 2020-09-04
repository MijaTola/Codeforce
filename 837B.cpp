#include <bits/stdc++.h>

using namespace std;

char f[110][110];
int main(){
    
    int n,m; 
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> f[i][j];


    bool flag = true;

    for (int i = 0; i < n; ++i){
        for (int j = 1; j < m; ++j)
            if(f[i][j] != f[i][j - 1]){
                flag = false;
                break;
            }
        if(!flag) break;
    }

    for (int i = 0; i < m; ++i){
        int r,g,b,rr,gg,bb;
        r = g = b = 0;
        int ans = 1;
        for (int j = 0; j < n; ++j){
            if(j and f[j][i] != f[j - 1][i]) ans++;
            if(f[j][i] == 'R') r++;
            if(f[j][i] == 'G') g++;
            if(f[j][i] == 'B') b++;
        }
        if(!r or !g or !b or r != g or r != b or g != b or ans != 3)
            {flag = false; break;}
    }

    if(flag) return puts("YES"),0;
    flag = true;
    for (int i = 0; i < m; ++i){
        for (int j = 1; j < n; ++j){
            if(f[j][i] != f[j - 1][i]){
                flag = false; break;
            }
        }
    }

    for (int i = 0; i < n; ++i){
        int r,g,b;
        r = g = b = 0;
        int ans = 1;
        for (int j = 0; j < m; ++j){
            if(j and f[i][j] != f[i][j - 1]) ans++;
            if(f[i][j] == 'R') r++;
            if(f[i][j] == 'G') g++;
            if(f[i][j] == 'B') b++;
        }
        if(!r or !g or !b or r != g or r != b or g != b or ans != 3)
            {flag = false; break;}
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}

