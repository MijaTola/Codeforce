#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[200010];

bool ver(int x) {
    long long  total = 0;
    int cur = 0;
    int i = 0;
    int lim = x;
    while(i < n) {
        for (;i < lim and i < n; i++) 
            total += max(0,(v[i] - cur));
        lim += x;
        cur++;
    }
    return total >= m;
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    sort(v, v + n);
    reverse(v, v + n);
    int a = 0, b = m + 1;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    if(b == m + 1) return cout << "-1\n",0;
    cout << b << "\n";
    return 0;
}

