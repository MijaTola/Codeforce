#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;

//x1,y1
//x2,y2

//(y2 - y1) = m * (x2 - x1) + (y2 - y1) / (x2 - x1);

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n - 2; i++) {
        
    }
    return 0;
}

