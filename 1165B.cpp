#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];

bool ver(int k) {
    int pos = n - 1;
    while(k) {
        if(v[pos] >= k) k--, pos--;
        else return 0;
    }
    return 1;
}
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    int a = -1, b = n + 1;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }

    cout << a << "\n";
    return 0;
}

