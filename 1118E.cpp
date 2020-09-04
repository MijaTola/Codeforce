#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
int main() {
    int n,k;
    cin >> n >> k;
    
    for (int i = 1; i <= k and (int)v.size() < n; ++i) {
        for (int j = i; j <= k and (int)v.size() < n; ++j) {
            if(i == j) continue;
            v.push_back({i,j});
            v.push_back({j,i});
        }
    }

    if((int)v.size() < n) return cout << "NO\n",0;
    cout << "YES\n";

    for (int i = 0; i < n; ++i) 
        cout << v[i].first << " "<< v[i].second << "\n";
    
    return 0;
}

