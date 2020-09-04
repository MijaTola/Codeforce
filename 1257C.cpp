#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf("%d", &t);

    while(t--) {

        map<int, vector<int> > v;
        int n;
        scanf("%d", &n);
        int ans = 1e9;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            if(v[x].size()) 
                ans = min(ans, i - v[x].back() + 1); 
            v[x].push_back(i);
        }

        printf("%d\n", ans == 1e9 ? -1: ans);
    }

    return 0;
}
