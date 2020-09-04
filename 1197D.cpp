#include <bits/stdc++.h>

using namespace std;

long long v[300010];
long long n,m,k;
long long get(int l, int r) {
    long long dif = abs(r - l + 1);
    return k * (dif / m + (dif % m != 0));
}

int main() {
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    long long ans = -1e18;
    long long sum = 0;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        if(sum - get(last, i) > ans) {
            ans = sum - get(last, i);
        }
        if(sum - get(last, i) < 0) {
            sum = 0;
            last = i + 1;
        }
    }
    cout << max(ans, 0ll) << "\n";
    return 0;
}

