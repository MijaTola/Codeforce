#include <bits/stdc++.h> 

using namespace std; 

int n;
int a[400010];
int v[400010];

int main() { 
    
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long sum = 0;
    for (int i = 0; i < 30; ++i) {
        //sort by bit
        int mask = 0;
        for (int j = 0; j <= i; ++j)
            mask |= (1 << j);

        for (int j = 0; j < n; ++j)
            v[j] = a[j] & mask;
        
        sort(v, v + n);

        long long ans = 0;
        
        int down = 1 << i, up = (1 << (i + 1)) - 1;

        for (int j = 0; j < n; ++j) {
            int u = up - v[j], d = down - v[j];
            int pos1 = upper_bound(v, v + n, u) - v;
            int pos2 = lower_bound(v, v + n, d) - v;
            if(pos2 < j + 1) pos2 = j + 1;
            ans += max(pos1 - pos2, 0);
        }

        down += (1 << (i + 1)), up += (1 << (i + 1));

        for (int j = 0; j < n; ++j) {
            int u = up - v[j], d = down - v[j];
            int pos1 = upper_bound(v, v + n, u) - v;
            int pos2 = lower_bound(v, v + n, d) - v;
            if(pos2 < j + 1) pos2 = j + 1;
            ans += max(pos1 - pos2, 0);
        }
        if(ans & 1) sum |= (1 << i);
    }
    cout << sum << "\n";
    return 0; 
} 

