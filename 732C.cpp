#include <bits/stdc++.h>

using namespace std;

long long v[3];
int main() {


    cin >> v[0] >> v[1] >> v[2];

    sort(v, v + 3);

    long long ans =0 ;

    v[2]--;

    for (int i = 0; i < 2; ++i) {
        ans += v[2] - v[i];
    }

    cout << ans << "\n";
    return 0;
}

