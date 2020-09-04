#include <bits/stdc++.h>

using namespace std;

int v[100010];
map<long long, int> c;
int main() {

    int n,x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        c[v[i]]++;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += c[v[i] ^ x];
        if(v[i] == (v[i] ^ x)) ans--;
    }
    cout << ans / 2 << "\n";
    return 0;
}
