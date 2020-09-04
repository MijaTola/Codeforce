#include <bits/stdc++.h>

using namespace std;

char m[55][55];
char a[55][55];

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        
        priority_queue<tuple<int,int,int> > q;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                char x;
                cin >> x;
                m[i][j] = x;
                a[i][j] = '0';
                if(x == '1') q.push({i + j, i, j});
            }

        bool flag = 1;
        while(!q.empty()) {
            int c,x,y;
            tie(c,x,y) = q.top();
            q.pop();

            if(x == n - 1 or y == n - 1) {
                a[x][y] = '1';
                continue;
            }
            
            if(a[x + 1][y] == '1' or a[x][y + 1] == '1') {
                a[x][y] = '1';
            } else {
                flag = 0 ;
                break;
            }
        }

        if(!flag) {
            puts("NO");
            continue;
        }
        
        for (int i = 0; i < n; ++i)  {
            for (int j = 0; j < n; ++j) {
                flag &= m[i][j] == a[i][j];
            }
        }

        puts(flag ? "YES" : "NO");
        
    }


    return 0;
}

