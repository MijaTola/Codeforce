#include <bits/stdc++.h>

using namespace std;

int c[510][510];
int dx[510];
int n,m,q;

int main() {
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            scanf("%d", &c[i][j]);
    
    auto check = [] (int x) {
        int cnt = 0;
        int last = 0;
        int mx = 0;
        for (int i = 0; i < m; ++i) {
            if(c[x][i] == last) cnt++;
            else {
                if(last) mx = max(cnt, mx);
                cnt = 1;
            }
            last = c[x][i];
        }
        if(last) mx = max(cnt, mx);
        return mx;
    };
    
    set<pair<int,int> > ans;

    for (int i = 0; i < n; ++i) {
        dx[i] = check(i);
        ans.insert({dx[i], i});   
    }

    //printf("%d\n", (*ans.rbegin()).second);
    while(q--) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--,y--;
        c[x][y] = 1 - c[x][y];
        ans.erase({dx[x], x});
        dx[x] = check(x);
        //cout << dx[x] << " nuevo\n";
        ans.insert({dx[x], x});   
        printf("%d\n", (*ans.rbegin()).first);
    }
    return 0;
}

