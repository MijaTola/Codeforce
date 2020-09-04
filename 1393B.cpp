#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main() {

    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    priority_queue<pair<int,int> > q;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }

    for (int i = 1; i <= 100000; ++i) {
        q.push({v[i],i});
    }

    int t;
    cin >> t;
    while(t--) {
        char ct;
        int x;
        cin >> ct >> x;

        if(ct == '+') {
            v[x]++;
        } else {
            v[x]--;
        }

        q.push({v[x], x});

        pair<int,int> a,b,c;

        while(q.top().first != v[q.top().second]) q.pop();
        a = q.top();
        q.pop();

        while(q.top().first != v[q.top().second]) q.pop();
        b = q.top();
        q.pop();

        while(q.top().first != v[q.top().second]) q.pop();
        c = q.top();
        q.pop();
    
        if(a.first < 4) {
            cout << "NO\n";
            q.push(a);
            q.push(b);
            q.push(c);
            continue;
        }

        x = a.first - 4;

        vector<int> e = {x, b.first, c.first};
        
        sort(e.rbegin(), e.rend());
        if(e[0] >= 4 or (e[0] >= 2 and e[1] >= 2))  cout << "YES\n";
        else cout << "NO\n";

        q.push(a);
        q.push(b);
        q.push(c);
    }

    return 0;
}

