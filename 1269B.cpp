#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[2010];
int b[2010];
int c[2010];

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);
    deque<int> q;

    for (int i = 0; i < n; ++i)
        q.push_back(a[i]);
    int ans = 1e9 + 10;
    for (int i = 0; i < n; ++i) {
        set<int> s;
        for (int j = 0; j < n; ++j) 
            s.insert((b[j] + m - q[j]) % m);
        
        q.push_front(q.back());
        q.pop_back();
        if(s.size() == 1) {
            int val = *s.begin();
            ans = min(ans, val);
        }
    }
    cout << ans << "\n";
    return 0;
}

