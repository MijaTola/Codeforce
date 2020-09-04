#include <bits/stdc++.h>

using namespace std;

int a[100010];
int b[100010];
bool vis[100010];
int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    queue<int> q;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        q.push(a[i]);
        while(!q.empty() and vis[q.front()]) q.pop();
        
        if(q.front() != b[i]) {
            ans++;
            vis[b[i]] = 1;
        } else q.pop();
        
    }
    cout << ans << "\n";
    return 0;
}

