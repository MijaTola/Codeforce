#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010],v;
int vis[200010];
int x,y;

void print(set<int> s) {
    for (int r: s)
        cout << r << " ";
    cout << "\n";
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    queue< set<int> > q;
    q.push({1});
    vis[1] = 1;
    set<int> cur = q.front();
    q.pop();
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if(cur.count(x)) {
            vis[x] = 1;
            set<int> s;
            for (int v: G[x]) {
                if(!vis[v])
                s.insert(v);
            }
            if(s.size()) q.push(s);
            cur.erase(x);
            if(cur.empty() and !q.empty()) {
                cur = q.front();
                q.pop();
            }
        } else return puts("No");
    }
    puts("Yes");
    return 0;
}
