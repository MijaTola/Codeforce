#include <bits/stdc++.h>

using namespace std;

int ix,iy,s,t,n;
map<int,set<int> > mp;
set<pair<int,int> > st;

int dx[] = {1,-1,0,0,1,-1,-1,1};
int dy[] = {0,0,1,-1,1,-1,1,-1};

int main() {

    cin >> ix >> iy >> s >> t >> n;

    for (int i = 0 ; i < n; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        for (int j = b; j <= c; ++j)
            mp[a].insert(j);
    }
    

    queue<pair<pair<int,int>, int> > q;
    
    auto check = [] (int x, int y) {
        return mp[x].count(y);
    };

    q.push({{ix,iy}, 0});
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if(x == s and y == t) return cout << c << "\n", 0;
        if(st.count({x,y})) continue;
        st.insert({x,y});
        for (int i = 0; i < 8; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if(check(u,v)) 
                q.push({{u,v}, c + 1});
        }
    }
    
    puts("-1");
    return 0;
}

