#include <bits/stdc++.h>

using namespace std;

int n,m;
long long x,mx;
deque<int> q;
vector<pair<int,int> > ans;

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        mx = max(mx, x);
        q.push_back(x);
    }

    while(q.front() != mx) {
        int a = q.front();
        q.pop_front();
        int b = q.front();
        q.pop_front();
        ans.emplace_back(a,b);
        if(a < b) swap(a,b);
        q.push_front(a), q.push_back(b);
    }

    while(m--) {
        scanf("%lld", &x);
        if(x <= (int)ans.size()) {
            printf("%d %d\n", ans[x - 1].first, ans[x - 1].second);
            continue;
        }
        x -= ans.size();
        x--;
        int pos = x % (n - 1);
        printf("%d %d\n", q[0], q[pos + 1]);
    }


    

    return 0;
    
}

