#include <bits/stdc++.h>

using namespace std;

int v[300010];
bool vis[300010];
int main() {
    
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    priority_queue<int> q; 
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += v[i] - v[i - 1];
        q.push(v[i] - v[i - 1]);
    }
    k--;
    while(k--) {
        ans -= q.top();
        q.pop();
    }
    
    cout << ans << "\n";

    return 0;
}

