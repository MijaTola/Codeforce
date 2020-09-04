#include <bits/stdc++.h>

using namespace std;

vector<int> data[200010], h1[200010], h2[200010];
vector<int> G[200010], G2[200010];
int ans1[200010];
int ans2[200010];

int main() {

    int h;
    cin >> h;
    int cur = 1;
    for (int i = 0; i < h + 1; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j)
            data[i].push_back(cur++);
    }
    
    for (int i = 0; i < h + 1; ++i) {
        int parent = data[i][0];
        for (int j = 0; j < (int)data[i + 1].size(); ++j) {
            int child = data[i + 1][j];
            G[parent].push_back(child);
        }
        h1[i].push_back(1);
    }

    for (int i = 0; i < h + 1; ++i) {
        int a = data[i][0];
        int b = data[i][data[i].size() - 1];
        for (int j = 0; j < (int)data[i + 1].size(); ++j) {
            int child = data[i + 1][j];
            if(j & 1) 
                G2[a].push_back(child);
            else 
                G2[b].push_back(child);
        }
        if(G2[a].size()) h2[i].push_back(1);
        if(G2[b].size() and a != b) h2[i].push_back(1);
    }

    bool perfect = 1;
    for (int i = 0; i < h; ++i) {
        perfect &= (h1[i].size() == h2[i].size());
    }
    
    if(perfect) return cout << "perfect\n",0;
    cout << "ambiguous\n";

    for (int i = 1; i < cur; ++i) {
        for (int v: G[i]) 
            ans1[v] = i;
    }

    for (int i = 1; i < cur; ++i) {
        for (int v: G2[i]) 
            ans2[v] = i;
        
    }

    for (int i = 1; i < cur; ++i)
        cout << ans1[i] << " ";
    cout << "\n";

    for (int i = 1; i < cur; ++i)
        cout << ans2[i] << " ";
    cout << "\n";
    return 0;
}

