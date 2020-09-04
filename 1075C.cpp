#include <bits/stdc++.h>

using namespace std;

vector<int> v, h;
int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        v.push_back(x);
        if(x == 1000000000) flag = 1;
    }
    for (int i = 0; i < m; ++i) {
        int x1,x2,y;
        scanf("%d%d%d", &x1, &x2, &y);
        if(x1 == 1) h.push_back(x2);
	}
    v.push_back(1000000000);
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    int ans = 1e9;
    for (int i = 0; i < (int)v.size(); ++i) {
        int curx = v[i];
        int pos = lower_bound(h.begin(), h.end(), curx) - h.begin();
        int cnt = i;
        ans = min(ans, ((int)h.size() - pos) + cnt);
    }

    int pos = lower_bound(h.begin(), h.end(), 0) - h.begin();
	
    printf("%d\n", ans);
    return 0;
}

