#include <bits/stdc++.h>

using namespace std;

long long v[110];
vector<int> G[110];
int in[110];

void dfs(int u) {
    cout << v[u] << " ";
    for (int x: G[u])
        dfs(x);
}

int main(){
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(v[i] * 2 == v[j]) 
                G[i].push_back(j), in[j]++;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(v[i] * 3 == v[j])
                G[j].push_back(i), in[i]++;
        }

    }
    int id = -1;
    for (int i = 0; i < n; ++i) {
        if(in[i] == 0) {
            id = i;
            break;
        }
    }
    
    dfs(id);
    cout << "\n";
    return 0;
}

