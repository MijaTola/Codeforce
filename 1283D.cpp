#include <bits/stdc++.h>

using namespace std;

int n,m;

set<int> s;
int main() {
    
    cin >> n >> m;
    
    vector<int> v(n);

    for (int &x: v) {
        cin >> x;
        s.insert(x);
    }

    sort(v.begin(), v.end());

    priority_queue<pair<int,int> > q;
    

    for (auto x: v) {
        if(!s.count(x - 1)) {
            s.insert(x - 1);
            q.push({-1, x - 1});
        }
        if(!s.count(x + 1)) {
            s.insert(x + 1);
            q.push({-1, x + 1});
        }
    }

    long long a = 0;
    vector<int> ans;

    for (int i = 0; i < m; ++i) {
        int y = q.top().second;
        int d = -q.top().first;
        q.pop();
        ans.push_back(y);
        a += d;

        if(!s.count(y - 1)) {
            s.insert(y - 1);
            q.push({-(d + 1), y - 1});
        }

        if(!s.count(y + 1)) {
            s.insert(y + 1);
            q.push({-(d + 1), y + 1});
        }
    }

    cout << a << "\n";

    for (int x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}

