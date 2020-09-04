#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[200010];
int cnt[200010];
bool vis[200010];
vector<pair<int,int> > v;
int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        cnt[x]++;
        cnt[y]++;
    }

    return 0;
}

