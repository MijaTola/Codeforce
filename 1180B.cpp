#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
int ans[100010];

int main () {

    int n,x;
    scanf("%d", &n);

    for (int i = 0 ; i < n; ++i) {
        scanf("%d", &x);
        v.emplace_back(x,i);
    }
    
    sort(v.begin(), v.end());
    
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if(v[i].first >= 0) {
            v[i].first = -v[i].first - 1;
            cnt++;
        } else cnt++;
    }
    
    int mx = -1e9;
    int id = -1;
    if(cnt & 1) {
        for (int i = 0; i < n; ++i) {
            if(v[i].first < 0 and mx < -v[i].first) {
                mx = -v[i].first;
                id = i;
            }
        }
        v[id].first = -v[id].first - 1;
    }
    
    for (int i = 0; i < n; ++i) {
        ans[v[i].second] = v[i].first;
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}
