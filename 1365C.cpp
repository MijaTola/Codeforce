#include <bits/stdc++.h>

using namespace std;

int a[1000010];
int b[1000010];
int main() {

    int n;
    cin >> n;

    
    for (int i = 0; i < n; ++i)
        cin >> a[i];


    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b[x] = i;
    }

    map<int,int> mp;

    for (int i = 0; i < n; ++i) {
        int pos = b[a[i]];
        if(pos < i) pos += n;
        mp[pos - i]++;
    }
    

    int ans = 1;
    
    for (auto p: mp)
        ans = max(ans, p.second);

    cout << ans << "\n";

    return 0;
}
