#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[200050];

int main() {
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) cnt++;
    }

    if (cnt > k) {
        cout << "-1\n";
        return 0;
    }

    vector<int> v;
    int pos=-1;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (pos >= 0) {
                v.push_back(i-pos-1);
            }
            pos=i;
        }
    }

    int ans = 2 * cnt;
    k-=cnt;

    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); i++) {
        if (k >= v[i] and v[i] >= 0) {
            ans -= 2;
            k -= v[i];
        }
    }

    if (pos >=0 and k >= n - pos - 1) ans--;
    cout << ans << "\n";
    return 0;
}

