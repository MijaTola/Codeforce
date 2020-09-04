#include <bits/stdc++.h>

using namespace std;

int n,k;
char v[2010][2010];
int letter[2010][2010];
int used[2010][2010];
pair<int,int> way[2010][2010];

bool ver(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < n;
}
int main() {

    cin >> n >> k;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
            letter[i][j] = used[i][j] = 1e9;
        }
    
    priority_queue<pair<pair<int,int> , pair<int,int> > > q;

    way[0][0] = {-1,-1};
    if(k and v[0][0] > 'a') {
        letter[0][0] = 'a';
        q.push({{-'a', k - 1}, {0,0}});
    } else {
        letter[0][0] = v[0][0];
        q.push({{-v[0][0], k}, {0,0}});
    }
    

    while(!q.empty()) {
        //int val = -q.top().first.first;
        int dk = q.top().first.second;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        used[x][y] = dk;
        if(dk) {
            if(ver(x + 1, y)) {
                if(letter[x + 1][y] > 'a') {
                    q.push({{-'a', dk - 1}, {x + 1,y}});
                    letter[x + 1][y] = 'a';
                    used[x + 1][y] = dk - 1;
                    way[x + 1][y].first = x;
                    way[x + 1][y].second = y;
                }
                if(letter[x + 1][y] == 'a' and used[x + 1][y] > dk - 1) {
                    q.push({{-'a', dk - 1}, {x + 1,y}});
                    letter[x + 1][y] = 'a';
                    used[x + 1][y] = dk - 1;
                    way[x + 1][y].first = x;
                    way[x + 1][y].second = y;
                }
            }
            if(ver(x, y + 1)) {
                if(letter[x][y + 1] > 'a') {
                    q.push({{-'a', dk - 1}, {x,y + 1}});
                    letter[x][y + 1] = 'a';
                    used[x][y + 1] = dk - 1;
                    way[x][y + 1].first = x;
                    way[x][y + 1].second = y;
                }

                if(letter[x][y + 1] == 'a' and used[x][y + 1] > dk - 1) {
                    q.push({{-'a', dk - 1}, {x,y + 1}});
                    letter[x][y + 1] = 'a';
                    used[x][y + 1] = dk - 1;
                    way[x][y + 1].first = x;
                    way[x][y + 1].second = y;
                }
            }
        } 
        if(ver(x + 1, y)) {
            if(letter[x + 1][y] > 'a') {
                q.push({{-v[x + 1][y], dk - 1}, {x + 1,y}});
                letter[x + 1][y] = v[x + 1][y];
                used[x + 1][y] = dk - 1;
                way[x + 1][y].first = x;
                way[x + 1][y].second = y;
            }
            if(letter[x + 1][y] == 'a' and used[x + 1][y] > dk - 1) {
                q.push({{-v[x + 1][y], dk - 1}, {x + 1,y}});
                letter[x + 1][y] = v[x + 1][y];
                used[x + 1][y] = dk - 1;
                way[x + 1][y].first = x;
                way[x + 1][y].second = y;
            }
        }
        if(ver(x, y + 1)) {
            if(letter[x][y + 1] > 'a') {
                q.push({{-v[x][y + 1], dk - 1}, {x,y + 1}});
                letter[x][y + 1] = v[x][y + 1];
                used[x][y + 1] = dk - 1;
                way[x][y + 1].first = x;
                way[x][y + 1].second = y;
            }

            if(letter[x][y + 1] == 'a' and used[x][y + 1] > dk - 1) {
                q.push({{-v[x][y + 1], dk - 1}, {x,y + 1}});
                letter[x][y + 1] = v[x][y + 1];
                used[x][y + 1] = dk - 1;
                way[x][y + 1].first = x;
                way[x][y + 1].second = y;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << letter[i][j] << " ";
        cout << "\n";
    }
    int dx = n - 1;
    int dy = n - 1;
    string ans = "";
    while(dx != 0 and dy != 0) {
        ans += letter[dx][dy];
        pair<int,int> p = way[dx][dy];
        dx = way[p.first][p.second].first;
        dy = way[p.first][p.second].second;
    }
    ans += letter[0][0];
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
    return 0;
}

