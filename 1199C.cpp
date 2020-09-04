#include <bits/stdc++.h>

using namespace std;

int n,I;
int v[400010];
int cnt[400010];
bool ver(int ini, int fin) {
    long long total = cnt[fin] - cnt[ini - 1];
    cout << cnt[fin] << " "<< cnt[ini] << " " << total << "\n";
    long long p = 0;
    while((1LL << p) < total) p++;
    return p * n <= 8ll * I;
}
int main() {
    cin >> n >> I;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v, v + n);
    int last = -1;

    for (int i = 0; i < n; ++i) {
        if(v[i] != last) cnt[i] = 1;
        last = v[i];
    }
    
    for (int i = 1; i < n; ++i)
        cnt[i] += cnt[i - 1];
    

    int ans = 1e9;;
    for (int i = 0; i < n; ++i) {
        int a = i, b = n;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(i,mid)) a = mid;
            else b = mid;
        }
        cout << i << " " << a << " " << " puta\n";
        ver(i,a);
        int left = i;
        int right = n - a - 1;
        if(ver(i, a))ans = min(ans, left + right);
    }
    cout << ans << "\n";
    return 0;
}

