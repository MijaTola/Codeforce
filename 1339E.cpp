#include <bits/stdc++.h>

using namespace std;

bool vis[100010];
vector<int> v;

int main() {

    int n = 500;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if(vis[i] or vis[j] or vis[k]) continue;
                if((i ^ j ^ k) == 0) {
                    vis[i] = vis[j] = vis[k] = 1;
                    cout << i << " " << j << " " << k << "\n";
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                }
            }
        }
    }

    //for (auto x: v)
        //cout << x << " ";
    //cout << "\n";
    return 0;
}

