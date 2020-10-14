#include <bits/stdc++.h>

using namespace std;

int query(int x, int y) {
    cout  << "? " << x << " " << y << endl;
    int z;
    cin >> z;
    return z;
}

int a[100010];
int b[100010];
int ans[100010];

int main() {
    
    int n;
    cin >> n;

    
    priority_queue<int> q;
    for (int i = 1; i <= n; ++i)
        q.push(-i);
    

    while((int)q.size() >= 2) {
        int a = -q.top();
        q.pop();
        int b = -q.top();
        q.pop();

        int da = query(a, b);
        int db = query(b, a);
        
        if(da > db) {
            ans[a] = da;
            q.push(-b);
        } else {
            ans[b] = db;
            q.push(-a);
        }
    }
    
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += ans[i];
    }
    
    long long left = ((n * (n + 1)/ 2)) -sum;
    ans[-q.top()] = left;
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

        
    return 0;
}

