#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        vector<int> ans(n);
        priority_queue<tuple<int,int,int> > q;
        q.push({n, 0, n - 1});

        for (int i = 0; i < n; ++i) {
            int sz, l, r;
            tie(sz,l,r) = q.top();
            q.pop();
            l = -l;
            int mid = (r + l) / 2;
            ans[mid] = i + 1;
            q.push({mid - l, -l, mid - 1});
            q.push({(r - mid), -(mid + 1), r});
        }

        for (auto x: ans)
            printf("%d ", x);
        puts("");
    }
    return 0;
}

