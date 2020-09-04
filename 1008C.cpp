#include <bits/stdc++.h>

using namespace std;

int ans[100010];
int n; 
vector<int> v;
vector<int> b;
int main(){
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v.push_back(x);
        b.push_back(x);
    }

    sort(v.rbegin(),v.rend());
    sort(b.rbegin(),b.rend());
        
    int pv = 0;
    int pb = 0;
    int ans = 0;
    while(pv < n and pb < n) {
        if(v[pv] > b[pb]) {
            ans++;
            pv++;
            pb++;
        } else pb++;
    }
    cout << ans << "\n";
    return 0;
}
