#include <bits/stdc++.h>

using namespace std;

int w[300010];
vector<pair<int,int> > G[300010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> w[i];

    for (int i = 0; i < n - 1; i++) {
        int x,y,c;
        cin >> x >> y >> c;
        G[x].push_back(make_pair(y,c));
        G[y].push_back(make_pair(x,c));
    }

    return 0;
}

