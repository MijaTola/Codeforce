#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[100010];
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    
    int pos = 0;
    long long sum = 0;

    while(k--) {
        while(v[pos] - sum <= 0 and pos < n) pos++;
            cout << max(0LL,v[pos] - sum) << "\n";
        if(pos < n)sum += v[pos++] - sum;
    }
    return 0;
}

