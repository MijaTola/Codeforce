#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > v;

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(), v.end());
    
    int ini = 0;
    int fin = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        
    }
    return 0;
}

