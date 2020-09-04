#include <bits/stdc++.h>

using namespace std;

int n;
long long h;
int v[1010];
bool ver(int k) {
    
    priority_queue<int> q;

    for (int i = 0; i < k; ++i)
        q.push(v[i]);

    long long mx = 0;
    while(q.size() > 2) {
        int u = q.top();
        q.pop();
        int x = q.top();
        q.pop();
        mx += max(u,x);
    }
    if(!q.empty()) mx += q.top();
    return mx <= h;
}
int main() {

    cin >> n >> h;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int a = -1, b = n + 1;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(!ver(mid)) b = mid;
        else a = mid;
    }
    cout << a << "\n";
    return 0;
}

