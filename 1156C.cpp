#include <bits/stdc++.h>

using namespace std;

int n,z,x;
int v[200010];

bool ver(int k) {
    for (int i = 0; i < k; ++i) 
        if(abs(v[n - k + i] - v[i]) < z) return 0;
    return 1;
}

int main() {
    cin >> n >> z;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    sort(v, v + n);

    int a = 0, b = n / 2 + 1;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }

    cout << a << "\n"; 
    return 0;
}

