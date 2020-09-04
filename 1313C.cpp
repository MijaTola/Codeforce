#include <bits/stdc++.h>
 
using namespace std;
 
int n;
long long v[1010];
long long a[1010];
 
 
int main() {
    cin >> n;
 
    for (int i = 0; i < n; ++i)
        cin >> v[i];
 
    long long ans = 0;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        int l = i - 1;
        int r = i + 1;
        long long cur = v[i];
        long long last = cur;
        while(l >= 0) {
            cur += min(last, v[l]);
            last = min(v[l], last);
            l--;
        }
        last = cur;
        while(r < n) {
            cur += min(last, v[r]);
            last = min(v[r], last);
            r++;
        }
        if(cur > ans) {
            ans = cur;
            id = i;
        }
    }
 
 
    int l = id - 1;
    int r = id + 1;
    long long cur = v[id];
    long long last = cur;
    a[id] = cur;

    while(l >= 0) {
        cur += min(last, v[l]);
        last = min(v[l], last);
        a[l]= last;
        l--;
    }
    last = cur;

    while(r < n) {
        cur += min(last, v[r]);
        last = min(v[r], last);
        a[r] = last;
        r++;
    }
 
    for (int i = 0; i < n;  ++i)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}
