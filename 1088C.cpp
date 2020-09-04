#include <bits/stdc++.h>

using namespace std;

int n;
int v[2000];

bool bs(int x, int n1) {
    int a = -1;
    int b = 1000000;
    
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if((long long)(mid * n1) >= x) b = mid;
        else a = mid;
    }
    return b;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    long long sum = 0;
    cout << n + 1 << "\n";
    for (int i = n; i >= 1; i--) {
        long long dif = (((i - 1) - (v[i - 1] + sum) % n) + n) % n;
        cout << 1 << " " << i << " " << dif << "\n";
        sum += dif;
    }
    cout << 2 << " " << n << " " << n << "\n";
    return 0;
}

