#include <bits/stdc++.h>

using namespace std;

int v[200010];
int main(){
    
    int n,s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v, v + n);
    long long ans = 0;
    for (int i = 0; i <= n / 2; ++i) {
        if(v[i] > s) ans += abs(s - v[i]);
    }

    for (int i = n / 2; i < n; ++i)
        if(v[i] < s) ans += abs(v[i] - s);
    cout << ans << "\n";
    return 0;
}

