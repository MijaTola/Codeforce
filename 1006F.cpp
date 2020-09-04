#include <bits/stdc++.h>

using namespace std;

int n,m;
long long k;
long long v[25][25];
map<long long, int> mp[25][25];
int mid;

void left(int x,int y, long long cur, int c) {
    if(x == n or y == m) return;
    if(c == mid) {
        mp[x][y][cur ^ v[x][y]]++;
        return;
    }
    left(x + 1, y, cur ^ v[x][y], c + 1);
    left(x, y + 1, cur ^ v[x][y], c + 1);
}

long long right(int x, int y, long long cur, int c) {
    if(x < 0 or y < 0) return 0;
    if(c == n + m - 2 - mid)  return mp[x][y][cur ^ k];
    long long ans = 0;
    ans += right(x - 1, y, cur ^ v[x][y], c + 1);
    ans += right(x, y - 1, cur ^ v[x][y], c + 1);
    return ans;
}
int main(){

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];
    mid = (n + m - 2) / 2;

    left(0,0,0,0);
    cout << right(n - 1, m - 1, 0, 0) << "\n";
    return 0;
}

