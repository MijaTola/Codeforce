#include <bits/stdc++.h>

using namespace std;

int v[110];
priority_queue<int> q;
int main() {

    int n,m;
    cin >> n >> m;
    
    int a = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a = max(a,x);
        q.push(-x);
    }
    int mx = a + m;
    while(m) {
        int u = -q.top(); q.pop();
        u++,m--;
        q.push(-u);
    }
    
    int a2 = 0;
    while(!q.empty()) {
        a2 = max(-q.top(),a2);
        q.pop();
    }
    cout << a2 << " " << mx << "\n";
    return 0;
}

