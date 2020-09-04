#include <bits/stdc++.h>

using namespace std;

int n;
int v[20];

int f(int l, int r) {
    if(l == r) return 1;
    bool flag = 1;
    for (int i = l + 1; i <= r; ++i) 
        if(v[i] < v[i - 1]) flag = 0;

    if(flag) return r - l + 1;
    int mid = (l + r) / 2;
    return max(f(l , mid), f(mid + 1, r));
}
int main() {

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    cout << f(0, n - 1) << "\n";
    return 0;
}

