#include <bits/stdc++.h>

using namespace std;

int n,x;
int v[200010];
int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        v[x]++;
    }
    int l = 0, r = 0;
    int c = 0;
    int ans = 0;
    int sum = 0;
    for (int i = 1; i < 200010; ++i) {
        int cur = v[i];
        if(cur > ans) {
            r = i;
            if(v[i - 1]) cur += sum;
            else l = i;
            sum = cur;
            ans = cur;
        } else {
            if(v[i - 1]) cur += sum;
            if(cur > ans) r = i;
        }
    }
    vector<int> b;
    for (int i = l; i <= r; ++i) {
        while(v[i]--) b.push_back(i);
    }
    cout << b.size() << "\n";
    for (int x: b)
        cout << x<< " ";
    cout << "\n";
    return 0;
}

