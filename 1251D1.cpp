#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > v;



int main() {

    int t;
    cin >> t;
    while(t--) {
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            v.push_back({x,y});
        }

        sort(v.begin(), v.end());
        

    }
    return 0;
}

