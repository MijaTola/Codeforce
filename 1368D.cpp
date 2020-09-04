#include <bits/stdc++.h>

using namespace std;

int v[200010];
int c[200010];

int main() {

    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        c[v[i]]++;
        ans |= v[i];
    }

    sort(v, v + n);



    return 0;
}

