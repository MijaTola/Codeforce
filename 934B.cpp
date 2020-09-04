#include <bits/stdc++.h>

using namespace std;

long long v[1000100];
bool vis[1000100];
int main(){
    
    queue<pair<long long,int> > q;

    q.push({0,0});

    while(!q.empty()) {
        long long x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(vis[y] or x > 1e18) continue;
        vis[y] = 1;
        v[y] = x;
        unsigned long long t = x;
        if(t * 10 > 1e18) continue;
        //q.push(make_pair(x * 10 + 0, y + 1));
        q.push(make_pair(x * 10 + 1, y));
        q.push(make_pair(x * 10 + 2, y));
        q.push(make_pair(x * 10 + 3, y));
        q.push(make_pair(x * 10 + 4, y + 1));
        q.push(make_pair(x * 10 + 5, y));
        q.push(make_pair(x * 10 + 6, y + 1));
        q.push(make_pair(x * 10 + 7, y));
        q.push(make_pair(x * 10 + 8, y + 2));
        q.push(make_pair(x * 10 + 9, y + 1));
    }

    int k; cin >> k;
    if(!vis[k]) cout << -1 << "\n";
    else cout << v[k] << "\n";
    return 0;
}

