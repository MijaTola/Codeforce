#include <bits/stdc++.h>

using namespace std;
int n;
int v[110];

bool ver(int x) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        a += v[i];
        b += x - v[i];
        if(v[i] > x) return 0;
    }
    return b > a;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int a = -1;
    int b = 1e5;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    cout << b << "\n";
    return 0;
}

