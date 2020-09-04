#include <bits/stdc++.h>

using namespace std;

pair<int,int>  v[200010];
int ans[200010];
int pre[200010];
int n,m,d;

bool ver(int x) {
    for (int i = 0; i < x; ++i) 
        pre[i] = i + 1;
    
    for (int i = x; i < n; ++i) {
        if(abs(v[i].first - v[i - x].first) <= d) return 0;
        pre[i] = pre[i - x];
    }

    return 1;
}
int main() {

    cin >> n >> m >> d;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    if(n == 1) return cout << "1\n1\n",0;
    if(n == 2) {
        if(abs(v[0].first - v[1].first) <= d) 
            cout << "2\n1 2\n";
        else cout << "1\n1 1\n";
        return 0;
    }
    sort(v, v + n);

    int a = -1,  b = n;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    
    cout << b << "\n";
    ver(b);
    for (int i = 0; i < n; ++i) 
        ans[v[i].second] = pre[i];
    
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
