#include <bits/stdc++.h>

using namespace std;

int manhattan(int x, int y, int a, int b) {
    return abs(x - a) + abs(y - b);
}

vector<pair<int,int> > fake;
vector<pair<int,int> > rl;

pair<int,int> next(pair<int,int> p, char c) {
    int x = p.first;
    int y = p.second;
    if(c == 'U') return {x, y + 1};
    if(c == 'D') return {x, y - 1};
    if(c == 'R') return {x + 1, y};
    if(c == 'L') return {x - 1, y};
}
char dif(char x) {
    if(x == 'L') return 'R';
    if(x == 'R') return 'L';
    if(x == 'U') return 'D';
    if(x == 'D') return 'U';
}
int main() {

    int n; cin >> n;
    string s; cin >> s;
    int x,y;
    cin >> x >> y;

    ///if(manhattan(0,0,x,y) > n or manhattan(0,0,) return cout << "-1\n",0;
    fake.push_back({0,0});
    for (int i = 0; i < n; ++i) {
        pair<int,int> p = next(fake[fake.size() - 1], s[i]);
        fake.push_back(p);
    }

    rl.push_back({x,y});
    for (int i = n - 1; i >= 0; i--) {
        pair<int,int> p = next(rl[rl.size() -1], dif(s[i]));
        rl.push_back(p);
    }

    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int a = -1;
        int b = n - i + 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            int dis = manhattan(fake[i].first, fake[i].second, rl[mid].first, rl[mid].second);
            if( n - (i + mid) >= dis and ((dis & 1 and (n - (i + mid)) & 1) or (!(dis & 1) and !((n - (i + mid)) & 1)))) a = mid;
            else b = mid;
        }
        b = a;
        int dis = manhattan(fake[i].first, fake[i].second, rl[b].first, rl[b].second);
        if( n - (i + b) >= dis and ((dis & 1 and (n - (i + b)) & 1) or (!(dis & 1) and !((n - (i + b)) & 1)))) 
            ans = min(ans, n - (b + i));
    }
    if(ans == 1e9) puts("-1");
    else cout << ans << "\n";
    return 0;
}

