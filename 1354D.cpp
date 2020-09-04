#include <bits/stdc++.h>

using namespace std;

int BIT[1000010];

void update(int x, int val) {
    for(; x < 1000010; x += x&-x)
          BIT[x] += val;
}

int query(int x) {
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n,q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        update(x, 1);
    }

    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if(k < 0) {
            int a = -1, b = 1000000;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                if(query(mid) >= -k) b = mid;
                else a = mid;
            }
            update(b, -1);
        } else {
            update(k,1);
        }
    }

    for (int i = 0; i < 1000010; ++i) {
        if(query(i)) {
            return cout << i << "\n", 0;
        }
    }

    cout << "0\n";

    return 0;
}

