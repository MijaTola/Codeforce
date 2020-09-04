#include <bits/stdc++.h>

using namespace std;

int main(){

    int n; 
    cin >> n;

    long long sum = 0, ans = LLONG_MAX;
    map<long long, int> mp;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        sum += x;
        mp[sum]++;
        ans = min(ans, 1ll * n - mp[sum]);
    }
    cout << ans << endl;
    return 0;
}
